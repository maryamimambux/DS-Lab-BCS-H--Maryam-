/*

Q1. Suppose you are developing a bank account management system, 
and you have defined the "BankAccount class" with the required constructors. 
You need to "demonstrate" the "use of these constructors" in various scenarios. 

1. Default Constructor Usage: 
Create a default-initialized BankAccount object named account1. 
Print out the balance of account1. 

2. Parameterized Constructor Usage: 
Create a BankAccount object named account2 with an initial balance of $1000. 
Print out the balance of account2. 

3. Copy Constructor Usage: Using the account2 you created earlier, 
create a new BankAccount object named account3 using the copy constructor. 

Deduct $200 from account3 and print out its balance. 
Also, print out the balance of account2 to ensure it hasn't been affected by the transaction involving account3. 

*/

#include <iostream>
using namespace std;

class BankAccount {
  private:
  double  balance;

  public:
  // 1. Default Constructor
  BankAccount() : balance(0) {};

  // 2. Parametrized Constructor
  BankAccount(double  balance) : balance(balance) {};

  // 3. Copy Constructor

  // NOTE: A deep copy is only needed when your class manages dynamic memory or resources.
  BankAccount (const BankAccount& obj) : balance(obj.balance) {}
  // Here Copying it means making a new double inside the new object → no sharing, no pointers, no problem.
  // So there’s no difference between shallow and deep here.


  void printBalance() {
    cout << "Balance: $" << balance << endl;
  }

  void deduct(int amount) {
    balance -= amount;
  }

};

int main() {

  cout << "account1: ";
  BankAccount account1;
  account1.printBalance();

  cout << "account2: ";
  BankAccount account2(1000);
  account2.printBalance();

  cout << "account3: ";
  BankAccount account3(account2);
  account3.printBalance();

  // Deduction of $200
  account3.deduct(200);

  cout << "account3 (after deduction): ";
  account3.printBalance();

  cout << "account2 (unchanged): ";
  account2.printBalance();

  cout << endl;
  return 0;
}