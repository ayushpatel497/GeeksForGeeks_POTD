//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int helper(Node* targetNode,unordered_map<Node*,Node*>&childToParent){
        int maxi=0;
        queue<Node*>q;
        q.push(targetNode);
        unordered_map<Node*,int>vis;
        vis[targetNode]=1;
        
        while(!q.empty()){
            int size=q.size();
            bool flag=0;
            for(int i=0;i<size;i++){
                Node* old=q.front();
                q.pop();
                
                if(old->left && !vis[old->left]){
                    flag=1;
                    vis[old->left]=1;
                    q.push(old->left);
                }
                
                if(old->right && !vis[old->right]){
                    flag=1;
                    vis[old->right]=1;
                    q.push(old->right);
                }
                
                if(childToParent[old] && !vis[childToParent[old]]){
                    flag=1;
                    vis[childToParent[old]]=1;
                    q.push(childToParent[old]);
                }
            }
            if(flag) maxi++;
        }
        
        return maxi;
    }
    
    Node* levelOT(Node* root,unordered_map<Node*,Node*>&childToParent,
    int target){
        Node* result=NULL;
        queue<Node*>q;
        Node* node=root;
        q.push(node);
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* old=q.front();
                if(old->data==target) result=old;
                q.pop();
                
                if(old->left){
                    childToParent[old->left]=old;
                    q.push(old->left);
                }
                
                if(old->right){
                    childToParent[old->right]=old;
                    q.push(old->right);
                }
            }
        }
        
        return result;
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>childToParent;
        Node* targetNode=levelOT(root,childToParent,target);
        int minTime=helper(targetNode,childToParent);
        
        return minTime;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends