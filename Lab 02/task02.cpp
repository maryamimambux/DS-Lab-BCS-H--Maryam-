/*

Task #2:
Write a program that uses a dynamic 2D array to represent a seating chart in a classroom.
=> Rows represent benches, columns represent seats on each bench.
=> Initialize the array with 0 (empty).
=> Let the user fill seats (1 for occupied).
=> Print the final seating chart in matrix form.

*/

#include <iostream>
using namespace std; 

int main() {

  // 1. Asking benches and seats on each bench from user.
  int benches; // rows (total no. of benches)
  int seats; // columns (seates on each bench)

  cout << "Enter the no. of benches: " ; 
  cin >> benches;
  cout << "Enter the no. of seats: " ; 
  cin >> seats;

  // 2. Dynamic Memory Allocation for 2D Array.
  int** seatingChart = new int*[benches];

  for(int i = 0; i < benches; i++) {
    seatingChart[i] = new int[seats];
  }

  // 3. Initializing all Elements with ZERO.
  for(int i = 0; i < benches; i++) {
    for(int j = 0; j < seats; j++) {
      seatingChart[i][j] = 0;
    }
  }

  // 4. Asking from user for Array Values
  cout << "Fill seats (1 for occupied, 0 for unoccupied): " << endl;
  for(int i = 0; i < benches; i++) {
    for(int j = 0; j < seats; j++) {
      cout << "Benche " << i+1 << " Seat " << j+1 << ": ";
      cin >> seatingChart[i][j];
    }
  }
  cout << endl;

  // 5. Printing the array
  cout << "Final Seating Chart: " << endl; 
  for(int i = 0; i < benches; i++) {
    for(int j = 0; j < seats; j++) {
      cout << seatingChart[i][j] << " ";
    }
    cout << endl;
  }

  // 6. Deallocating Memory of Array
  for(int i = 0; i < benches; i++) {
    delete[] seatingChart[i];
  }
  delete[] seatingChart; 

  cout << endl;
  return 0;
}