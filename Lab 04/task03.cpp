#include <iostream>
using namespace std; 

/* ========= "TASK 03: SELECTION SORT" =========

Implement the Selection Sort algorithm. 
The program should take an array of integers from the user, 
find the smallest element, and exchange it with the element at the first position.
This process should continue until the array is completely sorted. Display the sorted array
to the user.

========= "Selection Sort Algorithm" =========
  - Go through the array to find the lowest value.
  - Move the lowest value to the front of the unsorted part of the array.
  - Go through the array again as many times as there are values in the array.

*/

void selectionSort(int arr[], int size) {

  // Outer loop: pick elements one by one (starting from index 1)
  for(int i = 0; i < size; i++) {
 
    int minIndex = i;

    // traversing through elements on higher indexs 
    // checking if there is even minimum element
    for(int j = i; j < size; j++) {

      // if there is element smaller than element on minIndex
      // then UPDATE it 
      if (arr[j] < arr[minIndex]) 
        minIndex = j; 

    }

    // finally swap ith element with smallest element found
    if (minIndex != i) {
    swap(arr[i], arr[minIndex]);
    }

  }
} 

void inputArray(int arr[], int size) {
  cout << "Enter " << size << " elements: ";
  for(int i = 0; i < size; i++) {
    cin >> *(arr+i);
  }
}

void printArray(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    cout << *(arr+i) << " ";
  }
  cout << endl;
}

int main() {
  int size = 6;
  int array[6];

  inputArray(array, size);
 
  cout << "Before Sorting: ";
  printArray(array, size);

  selectionSort(array, size);

  cout << "After Sorting: ";
  printArray(array, size); 

  return 0;
}