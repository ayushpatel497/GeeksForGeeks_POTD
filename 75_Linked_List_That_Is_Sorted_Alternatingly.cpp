//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    void reverselist(Node *&head)
    {
    	Node* prev = NULL, *curr = head, *next;
    	while (curr)
    	{
    		next = curr->next;  
    		curr->next = prev;   
    		prev = curr;         
    		curr = next;         
    	}
    	head = prev;
    }
    
    Node *mergelist(Node *head1, Node *head2)
    {
    	if (!head1) return head2;  
    	if (!head2) return head1;  
    	Node *temp = NULL;
    	if (head1->data < head2->data)
    	{
    		temp = head1;  
    		head1->next = mergelist(head1->next, head2);
    	}
    	else
    	{
    		temp = head2; 
    		head2->next = mergelist(head1, head2->next);
    	}
    	return temp;
    }
    
    void splitList(Node *head, Node **Ahead, Node **Dhead)
    {
    	*Ahead = new Node(0);
    	*Dhead = new Node(0);
    	Node *asc = *Ahead;
    	Node *dsc = *Dhead;
    	Node *curr = head;
    	while (curr)
    	{
    		asc->next = curr;
    		asc = asc->next;
    		curr = curr->next;
    		if (curr)
    		{
    			dsc->next = curr;
    			dsc = dsc->next;
    			curr = curr->next;
    		}
    	}
    	asc->next = NULL;
    	dsc->next = NULL;
    	*Ahead = (*Ahead)->next;
    	*Dhead = (*Dhead)->next;
    }
    
    void sort(Node **head)
    {
        // code here
    	Node *Ahead, *Dhead;
    	splitList(*head, &Ahead, &Dhead);
    	reverselist(Dhead);
    	*head = mergelist(Ahead, Dhead);
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends