#include <iostream>
using namespace std;

/* ======== Josephus Problem using Circular Linked List ========
   
Use a circular linked list to solve the Josephus problem:
  • N people stand in a circle, eliminating every k-th person until only one survives.
  • Input: N = 7, k = 3
  • Output: Position of survivor.
  • Hint: Use circular traversal and deletion.

*/

class Node {
public:
  int info;
  Node* next;

  Node () : info(0), next(NULL) {}
  Node(int val) : info(val), next(NULL) {}
};


Node* CircularList(int N) {
  Node* head = new Node(1);
  Node* prev = head;

  for (int i = 2; i <= N; i++) {
    Node* temp = new Node(i);
    prev->next = temp;
    prev = temp;
  }
  prev->next = head;  
  return head;
}

 
int josephusProblem(int N, int k) {
  Node* head = CircularList(N);

  Node* prev = NULL;
  Node* curr = head;

  while (curr->next != curr) { 
     
    for (int count = 1; count < k; count++) {
      prev = curr;
      curr = curr->next;
    } 

    cout << "Eliminated: " << curr->info << endl;
    prev->next = curr->next;
    delete curr;
    curr = prev->next;
  }

  int survivor = curr->info;
  delete curr;  
  return survivor;
}

int main() {
  int N, k;
  cout << "Enter number of people: ";
  cin >> N;
  cout << "Enter step size: ";
  cin >> k;

  int survivor = josephusProblem(N, k);
  cout << "Survivor's Position': " << survivor << endl;

  cout << endl;
  return 0;
}
