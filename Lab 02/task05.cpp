/*
Task #5:
Write a C++ program that dynamically creates a 2D matrix and provides:
=> Addition of two matrices.
=> Subtraction of two matrices.
=> Ensure safe memory handling with proper allocation/deallocation.

*/ 

#include <iostream>
using namespace std;

// Print 2D Array
void print2DArray(int** arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << "| ";
    for (int j = 0; j < size; j++) {
        cout << arr[i][j] << " ";
    }
    cout << "|\n";
  }
  cout << endl;
} 

// Input 2D Array
void inputMatrixElement(int** matrix, int size) {

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      cout << "[" << i  << "][" << j << "]: ";
      cin >> matrix[i][j];
    }
  }
  cout << endl;
}

// Dynamic Memory Allocation of 2D Array
int** DMAof2DArray(int size) {
  int** matrix = new int*[size];
  for(int i = 0; i < size; i++) {
    matrix[i] = new int [size];
  } 
  return matrix;
}

// Addition of Two Matrices
void add(int** matrix1, int** matrix2, int** resultMatrix, int size) {

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) { 
      resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  cout << endl;
}

// Subtraction of Two Matrices
void subtract(int** matrix1, int** matrix2, int** resultMatrix, int size) {

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) { 
      resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
  cout << endl;
}

// --- MAIN FUNCTION ---
int main() {

  int size;
  cout << "Enter size of matrix: ";
  cin >> size;  

  int** matrix1 = DMAof2DArray(size);
  int** matrix2 = DMAof2DArray(size); 
  int** resultMatrix = DMAof2DArray(size); 

  cout << "Enter elements for Matrix1:  \n";
  inputMatrixElement(matrix1, size);

  cout << "Enter elements for Matrix2:  \n";
  inputMatrixElement(matrix2, size); 

  cout << "Matrix 1:\n";
  print2DArray(matrix1, size);
  cout << "Matrix 2:\n";
  print2DArray(matrix2, size);
 
  // Addition
  add(matrix1, matrix2, resultMatrix, size);
  cout << "Result of Addition :\n";
  print2DArray(resultMatrix, size); 

  // Subtraction
  subtract(matrix1, matrix2, resultMatrix, size); 
  cout << "Result of Subtraction :\n";
  print2DArray(resultMatrix, size);

  // Deallocation
  for(int i = 0; i < size; i++) {
    delete[] matrix1[i];
    delete[] matrix2[i];
    delete[] resultMatrix[i];
  }
  delete[] matrix1;
  delete[] matrix2;
  delete[] resultMatrix;

  cout << endl;
  return 0;
}