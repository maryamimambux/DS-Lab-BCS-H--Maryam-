/*

Task #7:
A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee
   salaries.

Calculate:
  -> The highest salary in each department.
  -> The department with the overall maximum average salary.

*/

#include <iostream>
using namespace std; 

int main() {

  int departments; // rows 
  int* employees; // cols

  cout << "Enter no. of departments: ";
  cin >> departments; 

  employees = new int[departments];  

  int** salaries = new int* [departments];

  for(int i = 0; i < departments; i++) {
    cout << "Department " << i+1 << " - Enter  no. of employees: "; 
    cin >> employees[i];

    salaries[i] = new int[employees[i]]; 

    cout << "Enter Salaries: \n" ;
    for(int j = 0; j < employees[i]; j++) {
      cout << "Employee " << j+1 << " : " ;
      cin >> salaries[i][j];
    }
  }

  cout << endl;
  for(int i = 0; i < departments; i++) {
    cout << "Department " << i+1 << ": ";
    for(int j = 0; j < employees[i]; j++) {
      cout << " $" << salaries[i][j] << " "  ;
    }
    cout << endl;
  }
  cout << endl;
  
  double avg = 0;
  double maxAvg = 0;
  double total = 0;

  for(int i = 0; i < departments; i++) { 
    int highestSalary = 0;
    total = 0;  
    for(int j = 0; j < employees[i]; j++) {
      if(salaries[i][j] > highestSalary) {
        highestSalary = salaries[i][j];
      }
      total += salaries[i][j]; 
    }
    avg = total / employees[i];  

    if(avg > maxAvg){
      maxAvg = avg;
    }

    cout << "The Highest Salary in department " << i+1 << " : " << highestSalary << endl;  
  }
  cout << "The Maximum Average in all departments: " << maxAvg << endl; 

  for(int i = 0; i < departments; i++){
    delete[] salaries[i];
  }
  delete[] salaries;  // free salaries array
  delete[] employees; // free employees array

  cout << endl;
  return 0;
}
