#include <iostream>
using namespace std;

 /* ========= "TASK 01: LINEAR SEARCH" =========

    Implement a linear search algorithm to FIND a specific integer in an array. 

    The program should take an "ARRAY" of integers and 
    a "TARGET VALUE" as INPUT from the user.

    Print the index of the target value if it's found or 
    a message indicating that the element is not in the array.

 */ 

 
int linearSearch(int arr[], int size, int key) {
  for(int i = 0; i < size; i++) {
    if(arr[i] == key) return i;
  }
  return -1;
}

void inputArray(int arr[], int size) {
  cout << "Enter " << size << " elements: ";
  for(int i = 0; i < size; i++) {
    cin >> *(arr+i);
  }
}

int main() {
  int size = 6;
  int array[6];

  inputArray(array, size);

  int target = 0;
  cout << "Enter target element: ";
  cin >> target;

  int targetIndex = linearSearch(array, size, target);

  if (targetIndex != -1) cout << "Index of target element: " << targetIndex << endl;
  else cout << target << " NOT found!\n";

  return 0;
}