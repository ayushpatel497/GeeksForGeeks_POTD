//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* sortedInsert(struct Node* head_ref, struct Node* new_node)
	{
		struct Node* current;
		if (head_ref == NULL || (head_ref)->data >= new_node->data)
		{
			new_node->next = head_ref;
			head_ref = new_node;
		}
		else
		{
			current = head_ref;
			while (current->next != NULL &&
			        current->next->data < new_node->data)
			{
				current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
		}

		return head_ref;
	}

	Node* insertionSort(struct Node* head_ref)
	{
		struct Node *sorted = NULL;
		struct Node *current = head_ref;
		while (current != NULL)
		{
			struct Node *next = current->next;
			sorted = sortedInsert(sorted, current);
			current = next;
		}
		head_ref = sorted;
		return head_ref;
	}
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		Node *head = NULL;
		Node *temp = head;
		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
		head = ob.insertionSort(head);
		printList(head);
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
