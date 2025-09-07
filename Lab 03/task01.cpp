#include <iostream>
using namespace std;

/* ======== Palindrome Check in Singly Linked List ========
   
Write a program to check if a singly linked list is a palindrome.
  • Input: A singly linked list of integers.
  • Output: true if the list reads the same forward and backward, false otherwise.

*/

class Node {
public:
  int data;
  Node* next;
  Node() : data(0), next(nullptr) {}
  Node(int x) : data(x), next(nullptr) {}
  Node(int x, Node* next) : data(x), next(next) {}
};

Node* reverseList(Node* head) {
  Node* prev = nullptr;
  Node* curr = head;
  while (curr) {
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev; // new head
}

bool isPalindrome(Node* head) {
  if (!head || !head->next) return true;

  // Find middle
  Node* slow = head;
  Node* fast = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Reverse second half  
  Node* secondHalf = reverseList(slow->next);
 
  Node* firstHalf = head;
  Node* temp = secondHalf;
  bool result = true;

  while (temp) {
    if (firstHalf->data != temp->data) {
      result = false;
      break;
    }
    firstHalf = firstHalf->next;
    temp = temp->next;
}

  // Restore the list by reversing second half back
  slow->next = reverseList(secondHalf);

  return result;
}

void printList(Node* head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(5);
  head->next->next->next = new Node(2);
  head->next->next->next->next = new Node(1);

  cout << "List: ";
  printList(head);

  if (isPalindrome(head))
    cout << "List is a Palindrome!";
  else
    cout << "List is NOT a Palindrome!";
  return 0;
}
