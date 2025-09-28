#include <iostream>
using namespace std;

/*

Task 6:

  Modify the provided "Rat in a Maze" code 
  to handle a more complex version of the problem.

  The rat should now be able to move in four directions 
  (up, down, left, and right) instead of just two. 
  
  Your updated code should still use backtracking to find 
  a valid path from the source (0,0) to the destination (N-1, N-1) 
  while avoiding dead ends.


*/ 

#include <iostream>
using namespace std;

#define N 5   // size

// print solution matrix
void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
        cout << sol[i][j] << "  ";
      cout << endl;
    }
    cout << endl;
}

void printMaze(int maze[N][N]) {
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << maze[i][j] << "  ";
    cout << endl;
  }
  cout << endl;

} 
 
bool isSafe(int maze[N][N], int x, int y) {
  return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}
 
void solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
  // WHEN destination is reached
  if (x == N - 1 && y == N - 1) {
    sol[x][y] = 1;
    cout << "Possible Path:\n";
    printSolution(sol);
    sol[x][y] = 0;  // backtrack for other solutions
    return;
  }

  if (isSafe(maze, x, y) && sol[x][y] == 0) {  // also check not visited
    sol[x][y] = 1;

    // Move Right
    solveMazeUtil(maze, x, y + 1, sol);

    // Move Down
    solveMazeUtil(maze, x + 1, y, sol);

    // Move Left
    solveMazeUtil(maze, x, y - 1, sol);

    // Move Up
    solveMazeUtil(maze, x - 1, y, sol);

    // FOR Backtrack
    sol[x][y] = 0;
  }
}

void solveMaze(int maze[N][N]) {
  int sol[N][N] = {0};

  cout << "All possible paths (4 directions):\n";
  solveMazeUtil(maze, 0, 0, sol);
}

int main() {
  int maze[N][N] = {  {1, 1, 1, 1, 1},
                      {1, 0, 0, 0, 1},
                      {1, 1, 1, 0, 1},
                      {0, 0, 1, 1, 1},
                      {1, 1, 1, 0, 1} }; 

  cout << "Maze:\n";
  printMaze(maze); 
  solveMaze(maze);
  return 0;
}

