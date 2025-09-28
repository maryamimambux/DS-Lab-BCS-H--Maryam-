#include <iostream>
using namespace std;
 
/*

Task 5:

    Implement a Sudoku solver using the backtracking technique. The program should take a
    partially filled 9x9 Sudoku grid and fill the empty cells (represented by 0) to solve the puzzle.
    Your algorithm should:
    1. Find an empty cell.
    2. Try placing a number from 1 to 9 in the empty cell.
    3. Check if the number is valid in the current row, column, and 3x3 subgrid.
    4. If valid, recursively call the function to solve the rest of the puzzle.
    5. If the recursive call doesn't lead to a solution,
    backtrack by resetting the cell to 0 and trying the next number.

*/

const int SIZE = 9;

void printsudokuGrid(int grid[SIZE][SIZE]) {
  cout << "Sudoku Grid: \n";

  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cout << grid[i][j] << "  ";
      if(j==2 || j==5) cout << " ";
    }
    cout << endl;
    if(i==2 || i==5) cout << "\n";
  }
  cout << endl;
}

bool findFreeCell(int grid[SIZE][SIZE], int& row, int& col) {

  for(int r = 0; r < SIZE; r++) {
    for(int c = 0; c < SIZE; c++) {  
      if( grid[r][c] == 0) {
        row = r;
        col = c;
        return true; 
      }
    } 
  } 
  return false; 
}


bool isValid(int grid[SIZE][SIZE], int n, int row, int col){

  for(int i = row, j = 0; j < SIZE; j++) {
    if(grid[i][j] == n) {
      return false;
    }
  }
  for(int i = 0, j = col; i < SIZE; i++) {
    if(grid[i][j] == n) {
      return false;
    }
  }

  if( (row >= 0 && row < 3) ) {
    if(col >= 0 && col < 3) {

      for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
          if(grid[i][j] == n) {
            return false;
          }
        }
      }

    }

    if(col >= 3 && col < 6) {

    for(int i = 0; i < 3; i++) {
      for(int j = 3; j < 6; j++) {
        if(grid[i][j] == n) {
          return false;
        }
      }
    }
      
  }

    if(col >= 6 && col < 9) {

      for(int i = 0; i < 3; i++) {
        for(int j = 6; j < 9; j++) {
          if(grid[i][j] == n) {
            return false;
          }
        }
      }
        
    }

  } 


  if( (row >= 3 && row < 6) ) {

    if(col >= 0 && col < 3) {

      for(int i = 3; i < 6; i++) {
        for(int j = 0; j < 3; j++) {
          if(grid[i][j] == n) {
            return false;
          }
        }
      }

    }

    if(col >= 3 && col < 6) {

      for(int i = 3; i < 6; i++) {
        for(int j = 3; j < 6; j++) {
          if(grid[i][j] == n) {
            return false;
          }
        }
      }
        
    }

    if(col >= 6 && col < 9) {

      for(int i = 3; i < 6; i++) {
        for(int j = 6; j < 9; j++) {
          if(grid[i][j] == n) {
            return false;
          }
        }
      }
        
    }

  } 


  
  if( (row >= 6 && row < 9) ) {
      
    if(col >= 0 && col < 3) {

      for(int i = 6; i < 9; i++) {
        for(int j = 0; j < 3; j++) {
          if(grid[i][j] == n) {
            return false;
          }
        }
      }

    }

    if(col >= 3 && col < 6) {

      for(int i = 6; i < 9; i++) {
        for(int j = 3; j < 6; j++) {
          if(grid[i][j] == n) {
            return false;
          }
        }
      }
        
    }

    if(col >= 6 && col < 9) {

      for(int i = 6; i < 9; i++) {
        for(int j = 6; j < 9; j++) {
          if(grid[i][j] == n) {
            return false;
          }
        }
      }
        
    }

  }

  return true;
}


bool sudokuSolver(int grid[SIZE][SIZE]) {
  int row, col;
  if(!findFreeCell(grid, row, col)) return true; // puzzle is solved

  for(int num = 1; num <= 9; num++) {

    if( isValid(grid, num, row, col) ) {
      grid[row][col] = num;
      if (sudokuSolver(grid)) return true; // recursion
      grid[row][col] = 0; // backtrack
    }

  } 
  return false;
}


int main() {

  int grid[9][9] = {  {5,0,0, 4,6,7, 3,0,9},
                      {9,0,3, 8,1,0, 4,2,7},
                      {1,7,4, 2,0,3, 0,0,0},

                      {2,3,1, 9,7,6, 8,5,4},
                      {8,5,7, 1,2,4, 0,9,0},
                      {4,9,6, 3,0,8, 1,7,2},

                      {0,0,0, 0,8,9, 2,6,0},
                      {7,8,2, 6,4,1, 0,0,5},
                      {0,1,0, 0,0,0, 7,0,8} };
 
  printsudokuGrid(grid);

  if (sudokuSolver(grid)) {
    printsudokuGrid(grid);
  } else {
      cout << "No solution exists!";
  }



  cout << endl;
  return 0;
}