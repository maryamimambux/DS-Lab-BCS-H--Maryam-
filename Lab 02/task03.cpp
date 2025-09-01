/*

Task #3:
Design a program to handle marks of students in different courses using a jagged array
(since each student is enrolled in a different number of courses).
=> Input the number of courses each student takes.
=> Dynamically allocate memory for each student accordingly.
=> Calculate and display each student’s average marks.

*/ 
#include <iostream>
using namespace std; 

int main() {

    int students; // rows
    int courses[5]; // columns

    cout << "Enter no. of students: ";
    cin >> students; 

    int** handleMarks = new int* [students];

    for(int i = 0; i < students; i++) {
        cout << "Student " << i+1 << " - Enter enrolled no. of courses: ";
        cin >> courses[i];

        handleMarks[i] = new int[courses[i]]; 

        cout << "Enter Marks: \n";
        for(int j = 0; j < courses[i]; j++) {
            cout << "Course " << j+1 << " : " ;
            cin >> handleMarks[i][j];
        }
    }
    cout << endl;

    for(int i = 0; i < students; i++) {
        cout << "Student " << i+1 << ": ";
        for(int j = 0; j < courses[i]; j++) {
            cout <<  handleMarks[i][j] << " "  ;
        }
        cout << endl;
    }

    for(int i = 0; i < students; i++){
        delete[] handleMarks[i];
    }
    delete[] handleMarks;

    return 0;
}
