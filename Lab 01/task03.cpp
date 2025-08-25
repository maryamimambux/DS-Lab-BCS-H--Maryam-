/*

Q3. Create a C++ "class Box" that uses DMA for an integer. 
Implement the "Rule of Three" by defining 
a destructor, copy constructor, and copy assignment operator. 
Demonstrate the behavior of both shallow and deep copy using test cases.

*/

#include <iostream>
using namespace std;

class Box {
private:
    int* integer;   // dynamically allocated integer

public:
    // Constructor
    Box(int value = 0) {
        integer = new int(value);
    }

    // Destructor
    ~Box() {
        delete integer;
    }

    // Copy Constructor (Deep Copy)
    Box(const Box& other) {
        integer = new int(*other.integer);
    }

    // Copy Assignment Operator (Deep Copy)
    Box& operator=(const Box& other) {
        if (this != &other) {    
            delete integer; 

            integer = new int(*other.integer);
        }
        return *this;
    }
 
    // Accessors and Mutators
    void setValue(int value) { *integer = value; }
    int getValue() const { return *integer; }

    // Shallow Copy function (just for demo)
    Box shallowCopy() {
        Box temp;
        delete temp.integer;  

        temp.integer = this->integer;  
        return temp;
    }
};
 
int main() {
    cout << "Deep Copy\n";
    Box b1(10);
    Box b2 = b1;  // Copy constructor (deep copy)
    b2.setValue(20);

    cout << "b1 value (unchanged): " << b1.getValue() << endl; 
    cout << "b2 value (after change): " << b2.getValue() << endl;  

    cout << "\nShallow Copy\n";
    Box b3(30);
    Box b4 = b3.shallowCopy(); // Shallow copy
    b4.setValue(40);

    cout << "b3 value (changed): " << b3.getValue() << endl;  
    cout << "b4 value (changed): " << b4.getValue() << endl;  

    return 0;
}
