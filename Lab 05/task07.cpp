#include <iostream>
using namespace std;

/*

Task 7:

  Create a program that solves the N-Queens problem 
  for any given N using backtracking.
  
  The program should print all possible solutions for placing N queens 
  on an N x N chessboard so that no two queens threaten each other. 
  
  This task requires you to use a recursive function to place queens row by row , 
  and a validation function to check if a queen can be placed in a specific cell. 
  
  If a placement leads to a conflict, 
  the algorithm should backtrack to the previous row and try a different column.


*/

#define N 4   

// Print the solution 
void printSolution(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << board[i][j] << "  ";
    }
    cout << endl;
  }
  cout << endl;
}
 
bool isSafe(int board[N][N], int row, int col) {
  int i, j;

  // Check this column (above rows only)
  for (i = 0; i < row; i++)
    if (board[i][col] == 1) return false;

  // Check upper-left diagonal
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j] == 1) return false;

  // Check upper-right diagonal
  for (i = row, j = col; i >= 0 && j < N; i--, j++)
    if (board[i][j] == 1) return false;

  return true;  
}
 
bool solveNQUtil(int board[N][N], int row) { 
  if (row == N) {
    printSolution(board);
    return true;
  }

  bool res = false;
  // Try placing queen in each column of this row
  for (int col = 0; col < N; col++) {
    if (isSafe(board, row, col)) {
      board[row][col] = 1; 

      // Recurse for next row
      res = solveNQUtil(board, row + 1) || res;

      // Backtrack (remove queen)
      board[row][col] = 0;
    }
  }
  return res;
}

// Main solver function
void solveNQ() {
  int board[N][N] = {0};

  if (!solveNQUtil(board, 0)) {
    cout << "No solution exists\n";
    return;
  }
}

int main() {
    cout << "All possible solutions for " << N << "-Queens:\n\n";
    solveNQ();
    return 0;
}
