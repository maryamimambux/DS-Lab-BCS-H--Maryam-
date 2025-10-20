#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    int i = low;
    int j = high;
    int pivot = arr[(low + high) / 2]; // middle element as pivot

    while (i <= j) {
        while (arr[i] < pivot)  
            i++;
        while (arr[j] > pivot)  
            j--;
        if (i <= j) {
            // swap elements
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // Recursive call
    if (low < j)
        quickSort(arr, low, j);
    if (i < high)
        quickSort(arr, i, high);
}

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
