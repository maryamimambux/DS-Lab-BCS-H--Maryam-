/*

Task #1:
Implement a program that dynamically allocates a 1D array of integers.
=> The size should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly.

*/

#include <iostream>
using namespace std; 

int main() {

  // 1. Asking SIZE from user.
  int size;
  cout << "Enter the size of array: " ;
  cin >> size;

  // 2. Dynamic Memory Allocation.
  int* arr = new int[size];

  // 3. Initializing all Elements with ZERO.
  for(int i = 0; i < size; i++) {
    arr[i] = 0;
  }

  // 4. Asking from user for Array Values
  cout << "Enter elements: " << endl;
  for(int i = 0; i < size; i++) {
    cout << "arr[" << i << "]: ";
    cin >> arr[i];
  }
  cout << endl;

  // 5. Printing the array
  cout << "Array: " << endl;
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // 6. Deallocating Memory of Array
  delete[] arr; 

  cout << endl;
  return 0;
}