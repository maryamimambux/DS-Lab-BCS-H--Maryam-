/*

Task #6:
Implement a Safe Pointer class to wrap around an integer pointer.
=> Provide methods for setValue(), getValue(), and release().
=> Demonstrate the class by storing marks of 5 students and printing them safely without
   direct pointer manipulation. 

*/

#include <iostream>
using namespace std; 

class SafePointer {
  private:
  int* value;

  public:
  SafePointer() { value = new int; }
  
  void setValue(int val) { *value = val; }
  int getValue() { return *value; }
  void release() { delete value; value = nullptr; } 

};

int main() {

  SafePointer* markOfStudents = new SafePointer[5];

  cout << "Enter Marks of 5 Students: " << endl;
  int marks;
  for(int i = 0; i < 5; i++) {
    cout << "Student " << i+1 << ": ";
    cin >> marks;
    markOfStudents[i].setValue(marks);
  }
  cout << endl;

  cout << "Marks of all 5 Students: " << endl; 
  for(int i = 0; i < 5; i++) {
    cout << "Student " << i+1 << ": " << markOfStudents[i].getValue() << " ";
  }
  cout << endl;

  for(int i = 0; i < 5; i++) {
    markOfStudents[i].release();
  }

  delete[] markOfStudents;

  cout << endl;
  return 0;
}