/*

Task #9:
Implement a program to represent a sparse matrix using a dynamic 2D array.
=> Input matrix elements.
=> Display the matrix in normal form.
=> Display the matrix in compressed form (row, column, value)

*/

#include <iostream>
using namespace std;

int main() {

  int rows, cols;

  cout << "Enter number of rows: ";
  cin >> rows;
  cout << "Enter number of columns: ";
  cin >> cols;

  // Dynamic 2D array
  int** matrix = new int*[rows];
  for(int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
  }

  // Input elements
  cout << "Enter matrix elements: \n";
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      cout << "Element [" << i << "][" << j << "]: ";
      cin >> matrix[i][j];
    }
  }

  cout << "\nMatrix in normal form:\n";
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  cout << "\nMatrix in compressed form (row, col, value):\n";
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      if(matrix[i][j] != 0) {
        cout << "(" << i << ", " << j << ", " << matrix[i][j] << ") ";
      }
    }
  }
  cout << endl;

  // Free memory
  for(int i = 0; i < rows; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;

  cout << endl;
  return 0;
}
