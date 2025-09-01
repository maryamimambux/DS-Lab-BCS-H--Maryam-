/*

Task #8:
Create a dynamic program to store temperature readings of a city for n days and m different times in a day
using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day

*/


/*

Task #8:
Create a dynamic program to store temperature readings of
a city for n days and m different times in a day
using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day

*/

#include <iostream>
using namespace std; 

int main() {

  int days, times;  

  cout << "Enter number of days: ";
  cin >> days; 
  cout << "Enter number of readings per day: ";
  cin >> times;

  // Dynamic 2D array for storing temperatures
  double** temp = new double*[days];
  for(int i = 0; i < days; i++) {
    temp[i] = new double[times];
  }

  // Input temperatures
  for(int i = 0; i < days; i++) {
    cout << "Day " << i+1 << " - Enter " << times << " temperature readings: " << endl;
    for(int j = 0; j < times; j++) {
      cout << "Reading " << j+1 << ": ";
      cin >> temp[i][j];
    }
  }

  cout << endl;
  // Display readings
  for(int i = 0; i < days; i++) {
    cout << "Day " << i+1 << ": ";
    for(int j = 0; j < times; j++) {
      cout << temp[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  double hottestAvg = -1e9; // very small
  double coldestAvg = 1e9;  // very large
  int hottestDay = -1;
  int coldestDay = -1;

  // Calculate daily averages + hottest and coldest
  for(int i = 0; i < days; i++) {
    double sum = 0;
    for(int j = 0; j < times; j++) {
      sum += temp[i][j];
    }
    double avg = sum / times;
    cout << "Average temperature of Day " << i+1 << " : " << avg << endl;

    if(avg > hottestAvg) {
      hottestAvg = avg;
      hottestDay = i + 1;
    }
    if(avg < coldestAvg) {
      coldestAvg = avg;
      coldestDay = i + 1;
    }
  }

  cout << "\nHottest Day: Day " << hottestDay << " with average temperature " << hottestAvg << endl;
  cout << "Coldest Day: Day " << coldestDay << " with average temperature " << coldestAvg << endl;

  // Free memory
  for(int i = 0; i < days; i++) {
    delete[] temp[i];
  }
  delete[] temp;

  cout << endl;
  return 0;
}
