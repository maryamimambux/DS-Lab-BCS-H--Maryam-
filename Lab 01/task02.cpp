/*

Q2. Create a C++ class named "Exam" 
using DMA designed to ""manage"" student exam records, 

complete with a shallow copy implementation? 

Define ATTRIBUTES such as "student name", "exam date", and "score" within the class, 
and include METHODS to "set these attributes" and "display exam details". 

As part of this exercise, intentionally OMIT 
the implementation of the copy constructor and copy assignment operator. 

Afterward, create an instance of the "Exam" class, generate a shallow copy, 
and observe any resulting issues?  

*/  

#include <iostream>
using namespace std;

class Exam {
  private:
  string* name;
  string* exam_date;
  double* score;

  public:
  // Default Constructors
  Exam() {
    name = new string("");
    exam_date = new string("");
    score = new double(0.0);
  }

  // Parametrized Constructors
  Exam(string n, string d, double s) {
    name = new string(n);
    exam_date = new string(d);
    score = new double(s);
  }

  // Copy Constructors OMITTED
  /*
    CONSEQUENSES
    1. Since you did not define a copy constructor, the compiler generates a shallow copy.
    2. Both result1 and result2 now point to the same memory addresses.
  */

  // Set Attributes
  void setName(string n) { *name = n; }
  void setExamDate(string d) { *exam_date = d; }
  void setScore(double s) { *score = s; }

  // Display Exam Details
  void displayExamDetails() {
    cout << "Name: " << *name << endl;
    cout << "Exam Date: " << *exam_date << endl;
    cout << "Score: " << *score << endl;
    
    cout << endl;
  }

  ~Exam() {
    delete name;
    delete exam_date;
    delete score;
  }

};

int main() {

  Exam result1;
  result1.setName("Maryam");
  result1.setExamDate("24-08-2025");
  result1.setScore(95.75);
  result1.displayExamDetails();


  Exam result2 = result1; 
  result2.displayExamDetails();

  result1.setName("Imam Bux");
  result1.displayExamDetails(); 

  result2.displayExamDetails();
  cout << endl;
  return 0;
}