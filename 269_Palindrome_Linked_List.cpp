//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node* reverse_list(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool is_identical(Node* n1, Node* n2) {
        for (; n1 && n2; n1 = n1->next, n2 = n2->next)
            if (n1->data != n2->data)
                return 0;
        return 1;
    }
    
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node* head) {
        // Your code here
        int size = 0;
        Node* ptr;
        for (ptr = head; ptr; ptr = ptr->next)
            size++;

        if (size < 2)
            return 1;

        ptr = head;
        int mid_pt = (size - 1) / 2;
        while (mid_pt--)
            ptr = ptr->next;
        Node* head2 = ptr->next;
        ptr->next = NULL;
        head2 = reverse_list(head2);
        bool ret = is_identical(head, head2);
        head2 = reverse_list(head2);
        ptr->next = head2;
        return ret;
    }
};


//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends