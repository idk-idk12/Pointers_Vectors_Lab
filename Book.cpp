#include "Book.h"
#include <string>
#include <iostream>

using namespace std;


/**
 * Constructs a Book with the given title, author, and price.
 *
 * @param title  the title of the book
 * @param author the author of the book
 * @param price  the price of the book in dollars
 */
Book::Book(string title, string author, double price) {
    this->title = title;
    this->author = author;
    this->price = price;
}


/**
 * Prints the book's title, author, and price,
 * followed by a blank line.
 */
void Book::displayInfo() const {
    cout << "Title: " << this->title << endl;
    cout << "Author: " << this->author << endl;
    cout << "Price: $" << this->price << endl;
    cout << endl;
}

