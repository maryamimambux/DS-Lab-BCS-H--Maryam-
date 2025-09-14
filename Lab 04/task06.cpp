#include <iostream>
using namespace std;

/* ========= "TASK 06: COMB SORT" =========

  Implement the Comb Sort algorithm to sort an array of integers. 
  This algorithm improves upon bubble sort by reducing the number 
  of comparisons and swaps using a "gap" that decreases over time. 
  
  After sorting, perform a complexity analysis: count and display the
  total number of swaps and comparisons performed during the sorting process.  

*/ 

void combSort(int arr[], int size) {

  int swapCount = 0;
  int totalPasses = 0; 
  int gap = size; 
  float shrink = 1.3;

  bool swaped = false;


  while(gap > 1 || swaped) {

    // Updating the Gap
    gap = int(gap/shrink);
    if(gap < 1) {
      // Note: When gap = 1, Comb sort work as Bubble Sort
      gap = 1;
    }
    swaped = false;

    totalPasses++;

    for(int i = 0; i + gap < size; i++) { 
      if(arr[i] > arr[i+gap]) {
        swap(arr[i], arr[i+gap]);
        swapCount++; 
        swaped  = true;
      } 
    }

  }
  cout << "Total passes: " << totalPasses << endl;
  cout << "Total no. of swaps: " << swapCount << endl;

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

  combSort(array, size);

  cout << "After Sorting: ";
  printArray(array, size); 

  return 0;
}