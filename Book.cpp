#include "Book.h"

Book::Book(const std::string &author, const std::string & category, unsigned int inMagazine)
{
	this->author = author;
	this->category = category;
	this->inMagazine = inMagazine;
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
	out << "Book author: " << book.author << "\nBook category: " << book.category << "\nNumber of books left: " << book.inMagazine << std::endl;
	return out;
}
