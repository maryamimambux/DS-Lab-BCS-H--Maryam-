#include <iostream>
using namespace std;

/* ========= "TASK 05: INTERPOLATION SEARCH" =========

  Implement the Interpolation Search algorithm. 
  The program should take a sorted array with uniformly distributed values 
  and a target value from the user. 
  The algorithm should estimate the position of the target and 
  check if the estimated position holds the correct value. 
  If the element is found, print its index; otherwise, indicate that it's not present.  

*/    

int interpolationSearch(int arr[], int size, int key ) {
  int start = 0;
  int end = size-1; 
  
  while (start <= end && key >= arr[start] && key <= arr[end]) {
      
    // Formula to estimate the position of 'key' 
    int probe = start + ( (end - start) * (key - arr[start]) ) / (arr[end] - arr[start]); 

    // Just for understanding
    cout << "Probe: " << probe << endl;

    // Case 1: Key is found at estimated position
    if (arr[probe] == key) {
      return probe;
    }

    // Case 2: If key is larger than the element at pos,
    // then it must be in the right part of the array
    if (arr[probe] < key) {
      start = probe + 1;
    }
    // Case 3: If key is smaller than the element at pos,
    // then it must be in the left part of the array
    else {
      end = probe - 1;
    }
  }

  // If we exit the loop, it means the key is not present
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
  int size = 8;
  int array[] = {2, 4, 8, 16, 32, 64, 128, 256}; 
  

  int target = 0;
  cout << "Enter target element: ";
  cin >> target;

  int targetIndex = interpolationSearch(array, size, target);

  if (targetIndex != -1) cout << "Index of target element: " << targetIndex << endl;
  else cout << target << " NOT found!\n";

  return 0;
}