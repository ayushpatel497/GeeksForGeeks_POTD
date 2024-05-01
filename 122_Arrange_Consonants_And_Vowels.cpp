//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
    public:
    // task is to complete this function
    // function should return head to the list after making 
    // necessary arrangements
    bool isVowel(char x)
    {
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
    }
    
    // Function to rearrange the linked list based on vowels
    struct Node* arrangeCV(Node *head)
    {
        
        Node *newHead = head;
        Node *latestVowel;
        Node *curr = head;
        
        if (head == NULL)
            return NULL;
        
        if (isVowel(head->data))
            latestVowel = head;
        else
        {
            while (curr->next != NULL && !isVowel(curr->next->data))
                curr = curr->next;
           
            if (curr->next == NULL)
               return head;
            
            latestVowel = newHead = curr->next;
            curr->next = curr->next->next;
            latestVowel->next = head;
        }
        
        while (curr != NULL && curr->next != NULL)
        {
            if (isVowel(curr->next->data))
            {
                if (curr == latestVowel)
                     latestVowel = curr = curr->next;
                else
                {
                    Node *temp = latestVowel->next;
                    latestVowel->next = curr->next;
                    latestVowel = latestVowel->next;
                    curr->next = curr->next->next;
                    latestVowel->next = temp;
                }
            }
            else
                curr = curr->next;
        }
        return newHead;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends