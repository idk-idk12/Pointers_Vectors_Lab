#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
    public:
	Book(std::string title,	std::string author, double price);
	void displayInfo() const;
    private:
	std::string title;
	std::string author;
	double price;
};

#endif
