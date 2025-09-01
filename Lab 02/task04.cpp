/*

Task #4:
Create a dynamic program that manages monthly expenses for a family.
=> Use a 1D dynamic array to store expenses for n months.
=> Add a feature to resize the array if the user wants to track more months later.
=> Compute and display the total and average expenses.

*/
 
#include <iostream>
using namespace std;

int* resizeArray(int oldSize, int newSize, int* array) {
	int updatedSize = oldSize+newSize;
	int* newArray = new int[updatedSize];
	
	for(int i = 0; i < oldSize; i++) {
		newArray[i] = array[i];
	} 
	delete[] array;
	
	return newArray;
}

int main() {
	
	// Asking user for no of months
	int noOfMonths;
	cout << "Enter no. of months: ";
	cin >> noOfMonths;
	
	// DMA of array
	int* monthlyExpensesArray = new int[noOfMonths];
	
	// Asking user for expenses
	cout << "Enter Monthly Expenses: \n";
	for(int i = 0; i < noOfMonths; i++) {
		cout << "Month " << i+1 <<": ";
		cin >> monthlyExpensesArray[i];
	}
	cout << endl;
	
	// Displaying array
	cout << "Monthly Expenses List: \n";
	for(int i = 0; i < noOfMonths; i++) {
		cout << "Month " << i+1 <<": $" << monthlyExpensesArray[i] << " ";
	}
	cout << endl;
	
	// Asking user for new no of months
	int newNoOfMonths;
	cout << "Enter NEW no. of months: ";
	cin >> newNoOfMonths;
	
	int* newmonthlyExpensesArray = resizeArray(noOfMonths, newNoOfMonths, monthlyExpensesArray);
	
	// Asking user for ADDITIONAL expenses
	cout << "Enter " << newNoOfMonths << " Monthly Expenses: \n";
	int updatedMonths = noOfMonths + newNoOfMonths;
	for(int i = noOfMonths; i < updatedMonths; i++) {
		cout << "Month " << i+1 <<": ";
		cin >> newmonthlyExpensesArray[i];
	}
	cout << endl;
	
    int total = 0;
    double average = 0;

	// Displaying NEW resized array
	cout << "Resized Monthly Expenses List: \n";
	for(int i = 0; i < updatedMonths; i++) { 
        total += newmonthlyExpensesArray[i] ;
		cout << "Month " << i+1 <<": $" << newmonthlyExpensesArray[i] << " ";
	}
    cout << endl; 

    cout << endl;
    // Compute and display the total and average expenses.
    average = total/updatedMonths;
    cout << "Total Monthly Expenses: " << total << endl;
    cout << "Average Monthly Expenses: " << average << endl;
    cout << endl;
	 
    return 0;
}
