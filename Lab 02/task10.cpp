/*

Task #10:
Design a program that maintains library book records using dynamic arrays.
=> Each row represents a category (e.g., Fiction, Science, History).
=> Each category has a different number of books (use a jagged array).
=> Store book IDs dynamically and allow the user to search for a given book ID.
=> Print whether the book is available and in which category.

*/

#include <iostream>
using namespace std;

int main() {
  
  int categories;  // rows
  int* books;      // number of books in each category

  cout << "Enter number of categories: ";
  cin >> categories;

  books = new int[categories];   // store no. of books per category
  int** bookIDs = new int*[categories];  // jagged array

  // Input books
  for(int i = 0; i < categories; i++) {
    cout << "\nEnter number of books in Category " << i+1 << ": ";
    cin >> books[i];

    bookIDs[i] = new int[books[i]];  // allocate memory for this category

    cout << "Enter Book IDs for Category " << i+1 << ":\n";
    for(int j = 0; j < books[i]; j++) {
      cout << "Book " << j+1 << ": ";
      cin >> bookIDs[i][j];
    }
  }

  // Display records
  cout << "\nLibrary Book Records:\n";
  for(int i = 0; i < categories; i++) {
    cout << "Category " << i+1 << ": ";
    for(int j = 0; j < books[i]; j++) {
      cout << bookIDs[i][j] << " ";
    }
    cout << endl;
  }

  // Search a book
  int searchID;
  bool found = false;

  cout << "\nEnter Book ID to search: ";
  cin >> searchID;

  for(int i = 0; i < categories; i++) {
    for(int j = 0; j < books[i]; j++) {
      if(bookIDs[i][j] == searchID) {
        cout << "Book ID " << searchID << " is available in Category " << i+1 << endl;
        found = true;
        break;
      }
    }
    if(found) break;
  }

  if(!found) {
    cout << "Book ID " << searchID << " not found in library.\n";
  }

  // Free memory
  for(int i = 0; i < categories; i++) {
    delete[] bookIDs[i];
  }
  delete[] bookIDs;
  delete[] books;

  cout << endl;
  return 0;
}

