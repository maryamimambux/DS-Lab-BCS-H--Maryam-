#include <iostream>
using namespace std;

/* ========= "TASK 04: INSERTION SORT" =========

    Use Insertion Sort to sort an array of integers provided by the user. 
    Then, implement the Binary Search algorithm to find a target value 
    within the newly sorted array. 
    
    The program should display the sorted array and 
    the index of the found element or a message if it's not present

    ========= "Insertion Sort Algorithm" =========

    - Take the first value from the unsorted part of the array.
    - Move the value into the correct place in the sorted part of the array.
    - Go through the unsorted part of the array again as many times as there are values. 

      Note: FIRST values is assumed as sorted.

*/    

void insertionSort(int arr[], int size) {
  // Outer loop: pick elements one by one (starting from index 1)
  // and insert them into the sorted part of the array (left side).
  for (int i = 1; i < size; i++) {

    int key = arr[i];    
    int j = i - 1;      


    // MOVE/SHIFT (DONOT swap) all elements greater than 'key' one step ahead
    // This creates the correct position for 'key'
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];  // Shift element to the right
        j--;                  
    }

    // Insert the 'key' into its correct position
    arr[j + 1] = key;
  }
}

int binarySearch(int arr[],int key, int start, int end) { 

  while(start <= end) {
    int mid = start + (end - start) / 2; 

    if(arr[mid] == key) {
      return mid;
    } 
    if(arr[mid] > key) {
      end = mid-1;
    }
    else{
      start = mid+1;
    }
  } 
  return -1;

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

  insertionSort(array, size);

  cout << "After Sorting: ";
  printArray(array, size);

  int target = 0;
  cout << "Enter target element: ";
  cin >> target;

  int targetIndex = binarySearch(array, target, 0, size);

  if (targetIndex != -1) cout << "Index of target element: " << targetIndex << endl;
  else cout << target << " NOT found!\n";

  return 0;
}