 /*  
 
1. Palindrome Check in Singly Linked List

Write a program to check if a singly linked list is a palindrome.

	Input: A singly linked list of integers.
	Output: true if the list reads the same forward and backward, false otherwise.
	Hint: Use a fast/slow pointer to find the middle, then reverse the second half and
	compare.


*/

#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { 
        data = d; 
        next = NULL;
    }
    
    
    void printList(Node* head) {
	
	    // Base condition is when the head is nullptr
	    if (head == NULL) {
	        return;
	    }
	
	    // Printing the current node data
	    cout << head->data;
	    
	    if(head->next)
	    cout<<", ";
	
	    // Moving to the next node
	    printList(head->next);
	}
};

// Function to check if the linked list 
// is palindrome or not
bool isPalindrome(Node* head) {
    Node* currNode = head;
 
    stack<int> s;
 
    while (currNode != NULL) {
        s.push(currNode->data);
        currNode = currNode->next;
    }
 
    while (head != NULL) {
      
        // Get the topmost element
        int c = s.top();
        s.pop();
 
        if (head->data != c) {
            return false;
        }

        // Move ahead
        head = head->next;
    }

    return true;
}

int main() {
  
    // Linked list : 1->2->5->2->1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

	head->printList(head);
	cout << endl;
	
    bool result = isPalindrome(head);

    if (result)
        cout << "Is Palindrome\n";
    else
        cout << "Not a Palindrome\n";

    return 0;
}
