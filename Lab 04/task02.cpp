#include <iostream>
using namespace std;

/* ========= "TASK 02: BUBBLE SORT" =========

    Write a program to implement the "Bubble Sort Algorithm". 
    
    The program should take an "ARRAY" of integers as INPUT from the user, 
    sort the array using BUBBLE SORT, 

    and then display both the unsorted and sorted arrays. 
*/  

void bubbleSort(int arr[], int size) {
  bool swapped = false;

  for(int i = 0; i < size-1; i++) {
    for(int j = 0; j < size - i - 1; j++) {
      if(arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    if(!swapped) break;
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

  bubbleSort(array, size);

  cout << "After Sorting: ";
  printArray(array, size);

  return 0;
}