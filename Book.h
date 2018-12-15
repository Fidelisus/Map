#pragma once
#include <string>
#include <iostream>

class Book
{
public:
    std::string author, category;
	unsigned int inMagazine;
    
	Book(const std::string &author, const std::string & category, unsigned int inMagazine);
    Book(){};
	friend std::ostream& operator<<(std::ostream& out, const Book& book);
};

