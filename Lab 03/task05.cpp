#include <iostream>
using namespace std;

/* ======== Convert Between Linked List Types ======== 

Implement functions for conversion:
  1. Convert a singly linked list into a doubly linked list.
  2. Convert a singly linked list into a circular linked list.
    • Demonstrate both conversions with sample input lists.

*/

// Singly Linked List Node
class SNode {
public:
  int data;
  SNode* next;

  SNode(int val) : data(val), next(NULL) {}
};

// Doubly Linked List Node
class DNode {
public:
  int data;
  DNode* prev;
  DNode* next;

  DNode(int val) : data(val), prev(NULL), next(NULL) {}
};

 

// Convert Singly to Doubly
DNode* convertToDoubly(SNode* head) {
  if (!head) return NULL;

  DNode* dHead = new DNode(head->data);
  DNode* dCurr = dHead;
  SNode* sCurr = head->next;

  while (sCurr) {
    DNode* newNode = new DNode(sCurr->data);
    dCurr->next = newNode;
    newNode->prev = dCurr;
    dCurr = newNode;
    sCurr = sCurr->next;
  }

  return dHead;
}

// Convert Singly -> Circular
SNode* convertToCircular(SNode* head) {
  if (!head) return NULL;

  SNode* temp = head;
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = head;  
  return head;
}


void printSingly(SNode* head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

void printDoubly(DNode* head) {
  DNode* tail = NULL;

  cout << "Doubly Forward: ";
  while (head) {
    cout << head->data << " ";
    if (!head->next) tail = head; // store last
    head = head->next;
  }
  cout << endl;

  cout << "Doubly Backward: ";
  while (tail) {
    cout << tail->data << " ";
    tail = tail->prev;
  }
  cout << endl;
}

void printCircular(SNode* head, int count) {
  cout << "Circular List (first " << count << " nodes): ";
  SNode* temp = head;
  while (count--) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// -------- Main --------
int main() {
  // 1 -> 2 -> 3 -> 4
  SNode* head = new SNode(1);
  head->next = new SNode(2);
  head->next->next = new SNode(3);
  head->next->next->next = new SNode(4);

  cout << "\nSingly Linked List: ";
  printSingly(head);
 
  DNode* dHead = convertToDoubly(head);
  cout << "Converted to Doubly Linked List:" << endl;
  printDoubly(dHead);
 
  SNode* cHead = convertToCircular(head);
  cout << "\nConverted to Circular Linked List:" << endl;
  printCircular(cHead, 10);  

  cout << endl;
  return 0;
}
