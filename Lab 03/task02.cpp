#include <iostream>
using namespace std;

/* ======== Merge Two Sorted Singly Linked Lists ========
   
Implement a function to merge two sorted singly linked lists into one sorted list.
  • Example:
    o List A: 1 → 3 → 5
    o List B: 2 → 4 → 6
    o Output: 1 → 2 → 3 → 4 → 5 → 6
  • Bonus: Solve without creating new nodes (rearrange pointers).

*/

class Node {
  public:
    int info;
    Node* next;

    Node() : info(0), next(NULL) {}
    Node(int data) : info(data), next(NULL) {}
};

Node* mergeSortedLists( Node* list1, Node* list2) { 
  if(!list1 || !list2) {
    return (list2)? list2 : list1;
  }

  Node* result;
  if(list1->info > list2->info) {
    result = list2;
    list2 = list2->next;
  } else {
    result = list1;
    list1 = list1->next;
  }

  Node* tail = result;

  while (list1 && list2) {
    if (list1->info > list2->info) {
      tail->next = list2;
      list2 = list2->next;
    } else {
      tail->next = list1;
      list1 = list1->next;
    }
    tail = tail->next;  // move forward
  }

  if (list1) tail->next = list1;
  if (list2) tail->next = list2;

  return result;
}


void printList(Node* head) {
  while (head) {
    cout << head->info << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Node* head1 = new Node(2);
  head1->next = new Node(4);
  head1->next->next = new Node(5); 

  cout << "List1: ";
  printList(head1);


  Node* head2 = new Node(1);
  head2->next = new Node(6);
  head2->next->next = new Node(9); 

  cout << "List2: ";
  printList(head2);

  Node* result = mergeSortedLists(head1, head2);
  cout << "Merged List: ";
  printList(result);

  cout  << endl;
  return 0;
}