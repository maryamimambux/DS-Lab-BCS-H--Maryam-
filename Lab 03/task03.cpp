#include <iostream>
using namespace std;

/* ======== Reverse in Groups of K ========
   
Reverse nodes of a singly linked list in groups of size k.
• Example:
  o Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, with k = 3
  o Output: 3 → 2 → 1 → 6 → 5 → 4 → 8 → 7

*/

class Node {
  public:
  int info;
  Node* next;

  Node() : info(0), next(NULL) {}
  Node(int data) : info(data), next(NULL) {}
};
 
Node* reverseGroup(Node* head, int k) {
  if (!head) return NULL;
 
  Node* temp = head;
  int count = 0;
  while (count < k && temp) {
    temp = temp->next;
    count++;
  }
  if (count < k) return head; // less than k nodes, don’t reverse
  
  Node* prev = NULL;
  Node* curr = head;
  Node* next = NULL;
  count = 0;

  while (curr && count < k) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }
 
  if (next) {
    head->next = reverseGroup(next, k);
  }

  return prev; 
}

void printList(Node* head) {
  while (head) {
    cout << head->info << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Node* head1 = new Node(1);
  head1->next = new Node(2);
  head1->next->next = new Node(3);
  head1->next->next->next = new Node(4);
  head1->next->next->next->next = new Node(5);
  head1->next->next->next->next->next = new Node(6); 

  cout << "List: ";
  printList(head1);

  int k;
  cout << "Enter group size: ";
  cin >> k;

  Node* answer = reverseGroup(head1, k);

  cout << "Reversed: " << k << ": ";
  printList(answer);

  return 0;
}
