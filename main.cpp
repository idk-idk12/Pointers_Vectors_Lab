// Jonathan Contreras-Jimenez
// 10/25/2026
// Book manager using pointers

#include <iostream>
#include <string>
#include <limits>
#include "Book.h"
#include "Inventory.h"

using namespace std;


bool myCin(double &x) {
    // this handles non-double inputs
    if (!(cin >> x)) {
	// these two lines clears the buffer and ensures that the user can input again.
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Input is suppose to be int/double." << endl;
	return false;
    }
    return true;
}


/**
 * Displays the main menu options and reads the user's selection.
 *
 * @param userChoice reference to an int that receives the menu option
 *                   entered by the user (1-4)
 */
void displayMenu(int& userChoice) {
    cout << "1. Add Book" << endl;
    cout << "2. Display All Books" << endl;
    cout << "3. Remove Book" << endl;
    cout << "4. Quit" << endl;
    cin >> userChoice;
}


/**
 * Prompts the user for a book's title, author, and price and creates a pointer
 * that is then added to the Inventory object.
 *
 * @param store reference to the Inventory that will own the new Book
 */
void addBook(Inventory& store) {
    string title, author;
    double price;
    cin.ignore(10000, '\n');   // discard the '\n' left by the menu choice
    cout << "Book title: ";
    getline(cin, title);
    cout << "Book author: ";
    getline(cin, author);
    cout << "Book price: $";
    if (myCin(price)) {
	Book* bookPtr = new Book(title, author, price);
	store.addBook(bookPtr);
    }
}


/**
 * Prompts the user for the index of a book and asks the inventory to
 * remove it. Invalid indexes are ignored by the inventory.
 *
 * @param store reference to the Inventory to remove the Book from
 */
void removeBook(Inventory& store) {
    int bookIdx;
    cout << "Book index: ";
    cin >> bookIdx;
    store.removeBook(bookIdx);
}


int main() {
    int userChoice;
    Inventory store;
    do {
	displayMenu(userChoice);
	switch (userChoice) {
	    case 1:
		addBook(store);
		cout << endl;
		break;
	    case 2:
		store.displayAll();
		break;
	    case 3:
		removeBook(store);
		cout << endl;
		break;
	    case 4:
		break;
	    default:
		cout << userChoice << " not valid choice." << endl << endl;
	}
    }
    while (userChoice != 4);
    return 0;
}

