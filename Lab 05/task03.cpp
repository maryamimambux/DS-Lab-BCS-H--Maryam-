#include <iostream>
using namespace std;

/*

Task 3:

1. Implement a C++ function sumTail(int n, int total) that 
calculates the sum of numbers from 1 to n using tail recursion. 
The recursive call should be the last operation in the function.

2. Implement another function sumNonTail(int n) that 
calculates the same sum using non-tail recursion. 
This function should perform an operation (e.g., addition) 
after the recursive call returns. 

Compare the two implementations and explain the difference in their call stacks.

*/

// 1. TAIL RECURSION
int sumTail(int n, int total) {
    if(n == 0) {
        return total;
    } 
    return sumTail(n-1, total+n);
}


// 2. NON-TAIL RECURSION
int sumNonTail(int n) {
    if(n == 1) {
        return 1;
    }

    return n + sumNonTail(n-1);
}

/*
    --- Call Stack Comparison ---

    Tail Recursion (sumTail):
    Example: sumTail(3, 0)
      sumTail(3,0) → sumTail(2,3) → sumTail(1,5) → sumTail(0,6)
    
    - Tail recursion passes the result forward, minimal stack usage.

    Non-Tail Recursion (sumNonTail):
    Example: sumNonTail(3)
      sumNonTail(3) = 3 + sumNonTail(2)
      sumNonTail(2) = 2 + sumNonTail(1)
      sumNonTail(1) = 1
      
    - Non-tail recursion waits for return values, deeper call stack.
*/

int main() {

    int n = 0, total = 0;
    cout << "Enter an integer: ";
    cin >> n;

    cout << "Using TAIL Recursion: ";
    cout << sumTail(n, total) << endl;

    cout << "Using NON-TAIL Recursion: ";
    cout << sumNonTail(n) << endl;

    return 0;
}