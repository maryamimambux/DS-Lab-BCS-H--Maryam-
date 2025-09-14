#include <iostream>
using namespace std;

/* ========= "TASK 07: SHELL SORT" =========

  Implement the Shell Sort algorithm to sort an array of integers. 
  The algorithm should start with a large gap, then perform a gapped insertion sort, 
  and gradually reduce the gap until it's 1. 
  
  After sorting, compare its performance against the Bubble Sort and Insertion Sort algorithms 
  for the same input array size (e.g., 1000 elements). 
  
  Record and display the time taken and the number of comparisons/swaps 
  for all three algorithms to demonstrate why Shell Sort is an improvement over Insertion Sort.  

*/  

// ================= SHELL SORT =================
void shellSort(int arr[], int n) {
  int comparisons = 0, swaps = 0;

  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j = i;

      while (j >= gap && (++comparisons && arr[j - gap] > temp)) {
        arr[j] = arr[j - gap];
        j -= gap;
        swaps++;
      }
      arr[j] = temp;
    }
  }

  cout << "Shell Sort\nComparisons: " << comparisons
       << ", Swaps/Shifts: " << swaps << endl;
}

// ================= BUBBLE SORT =================
void bubbleSort(int arr[], int size) {
  int comparisons = 0, swaps = 0;
  bool swapped = false;

  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      comparisons++;
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swaps++;
        swapped = true;
      }
    }
    if (!swapped) break;
  }

  cout << "Bubble Sort\nComparisons: " << comparisons
       << ", Swaps: " << swaps << endl;
}

// ================= INSERTION SORT =================
void insertionSort(int arr[], int size) {
  int comparisons = 0, swaps = 0;

  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && (++comparisons && arr[j] > key)) {
      arr[j + 1] = arr[j];
      j--;
      swaps++;
    }
    arr[j + 1] = key;
  }

  cout << "Insertion Sort\nComparisons: " << comparisons
       << ", Shifts: " << swaps << endl;
}

// ================= HELPERS =================
void inputArray(int arr[], int size) {
  cout << "Enter " << size << " elements: ";
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// ================= MAIN =================
int main() {
  int size = 6;
  int array[6];

  inputArray(array, size);

  cout << "Before Sorting: ";
  printArray(array, size);
  cout << endl;

  // Run all three sorts on copies
  int arr1[6], arr2[6], arr3[6];
  for (int i = 0; i < size; i++) {
    arr1[i] = arr2[i] = arr3[i] = array[i];
  }

  shellSort(arr1, size);
  bubbleSort(arr2, size);
  insertionSort(arr3, size);

  cout << endl;
  cout << "After Shell Sort: ";
  printArray(arr1, size);

  cout << "After Bubble Sort: ";
  printArray(arr2, size);

  cout << "After Insertion Sort: ";
  printArray(arr3, size);

  return 0;
}
