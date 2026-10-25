#include "Inventory.h"
#include <iostream>
#include <vector>

using namespace std;


/**
 * Constructs an empty Inventory with no books.
 */
Inventory::Inventory() {}

/**
 * Destroys the Inventory and frees the memory of every Book it owns.
 */
Inventory::~Inventory() {
    for (int i = 0; i < this->books.size(); ++i) {
	delete this->books.at(i);
    }
}

/**
 * Adds a dynamically allocated Book to the inventory.
 *
 * @param bookPtr pointer to a Book allocated with new
 */
void Inventory::addBook(Book *bookPtr) {
    this->books.push_back(bookPtr);
}

/**
 * Displays the information of every Book in the inventory, in the order
 * the books were added.
 */
void Inventory::displayAll() const {
    if (this->books.empty()) {
	cout << "No books added yet" << endl << endl;
	return;
    }
    for (int i = 0; i < this->books.size(); ++i) {
	this->books.at(i)->displayInfo();
    }
}

/**
 * Removes the Book at the given index. The Book's memory is freed with
 * delete before its pointer is erased from the vector, preventing a
 * memory leak. If the index is out of range, nothing happens.
 *
 * @param index zero-based position of the Book to remove
 */
void Inventory::removeBook(int index) {
    if (index >= 0 && index < this->books.size()) {
	delete this->books.at(index);
	this->books.erase(this->books.begin() + index);
	cout << "Removed book at index [" << index << "] successfully!" << endl;
    }
    else {
	cout << "Couldn't remove book at index [" << index << "]." << endl;
    }
}

