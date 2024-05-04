//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    Node* buildUtil(int in[], int post[], int inStrt, int inEnd, int* pIndex, unordered_map<int, int>& mp)
    {
        if (inStrt > inEnd)
            return NULL;
        int curr = post[*pIndex];
        Node* node = new Node(curr);
        (*pIndex)--;
        if (inStrt == inEnd)
            return node;
        int iIndex = mp[curr];
        node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex, mp);
        node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex, mp);
        return node;
    }

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
            um[in[i]] = i;
        int index = n - 1;
        return buildUtil(in, post, 0, n - 1, &index, um);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends