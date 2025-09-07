#include <iostream>
using namespace std;

/* ======== Flatten a Multilevel Linked List ======== 

Each node has:
  • next pointer (normal linked list connection).
  • child pointer (points to another linked list).

Write a function to flatten the structure so that all nodes appear in a single-level list.
  • Example:
      1 → 2 → 3
          |
          4 → 5
  Output: 1 → 2 → 4 → 5 → 3 

*/ 

class Node {
public:
  int info;
  Node* prev;
  Node* next;
  Node* child;

  Node(int v) {
    info = v;
    prev = next = child = nullptr;
  }
};

// Helper function to flatten a sublist
Node* flattenHelper(Node* start, Node* end) {
  Node* child = start->child;
  if (!child) {
    return start;
  }

  Node* prev = nullptr;
  Node* it = child;

  while (it) {
    if (it->child) {
      it = flattenHelper(it, it->next);
    }
    prev = it;
    it = it->next;
  }
 
  prev->next = end;
  if (end) {
    end->prev = prev;
  }
  start->next = child;
  child->prev = start;
  start->child = nullptr;

  return prev;  
}

// Flatten function
Node* flatten(Node* head) {
  Node* it = head;
  while (it) {
    if (it->child) {
      it = flattenHelper(it, it->next);
    }
    it = it->next;
  }
  return head;
}
 
void printList(Node* head) {
  while (head) {
    cout << head->info << " ";
    head = head->next;
  }
  cout << endl;
}
 
int main() { 
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->prev = head;

  head->next->next = new Node(3);
  head->next->next->prev = head->next;

  head->next->next->next = new Node(4);
  head->next->next->next->prev = head->next->next;

   
  Node* child = new Node(7);
  child->next = new Node(8);
  child->next->prev = child;

  child->next->next = new Node(9);
  child->next->next->prev = child->next;

  head->next->next->child = child;  

  cout << "Original list :" << endl;
  cout << "Head: " << head->info << " ..." << endl;

  head = flatten(head);

  cout << "\nFlattened list:" << endl;
  printList(head);

  cout << endl;
  return 0;
}
