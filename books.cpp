#include <iostream>
#include <fstream>
#include <sstream>
#include "books.hpp"

void Books::addBook(const Book& book) {
    bookList.push_back(book);
}

void Books::loadBooksFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string isbn, title, author, pubYearStr, availabilityStr;


        std::getline(iss, isbn, ',');
        std::getline(iss, title, ',');
        std::getline(iss, author, ',');
        std::getline(iss, pubYearStr, ',');
        std::getline(iss, availabilityStr);


        int publicationYear = std::stoi(pubYearStr);
        bool availabilityStatus = availabilityStr == "1";


        addBook(Book(isbn, title, author, publicationYear, availabilityStatus));
    }
}

void Books::displayBooks() const {
    for (const auto& book : bookList) {
        std::cout  << ", Title: " << book.getTitle()
                  << ", Available: " << (book.isAvailable() ? "Yes" : "No") << std::endl;
    }
}
