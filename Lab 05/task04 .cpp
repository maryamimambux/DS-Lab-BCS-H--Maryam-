#include <iostream>
using namespace std;

/*

Task 4:

    Write a C++ program that implements the Ackermann function, 
    which is a classic example of nested recursion. 
    The function ackermann(int m, int n) is defined as:
        ● If m=0, return n+1.
        ● If m>0 and n=0, return ackermann(m-1, 1).
        ● If m>0 and n>0, return ackermann(m-1, ackermann(m, n-1)).
    This task requires you to trace the execution and 
    understand how one recursive call is a parameter to another.

*/

int ackermann(int m, int n) {
    if(m == 0) {
        return n + 1;
    }
    else if(m>0 && n==0) {
        return ackermann(m-1, 1);
    }
    else if(m>0 && n>0) {
        return ackermann(m-1, ackermann(m, n-1));
    }  
    return 0;
}

 /*
    --- Trace Example ---
    Suppose m = 1, n = 2:
    
    ackermann(1, 2)
    = ackermann(0, ackermann(1, 1))   // rule 3
    = ackermann(0, ackermann(0, ackermann(1, 0)))  // expand ackermann(1,1)
    = ackermann(0, ackermann(0, ackermann(0,1)))  // expand ackermann(1,0)
    = ackermann(0, ackermann(0,2))    // ackermann(0,1) = 2
    = ackermann(0,3)                  // ackermann(0,2) = 3
    = 4

    So, Ackermann(1,2) = 4

*/

int main() {

    int n = 0, m = 0;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << endl;
    return 0;
} 