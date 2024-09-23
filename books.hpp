#ifndef BOOKS_HPP
#define BOOKS_HPP

#include <string>
#include <vector>

class Book {
private:
    std::string ISBN;
    std::string title;
    std::string author;
    int publicationYear;
    bool availabilityStatus;

public:

    Book(const std::string& isbn, const std::string& title, const std::string& author,
         int pubYear, bool availability)
        : ISBN(isbn), title(title), author(author), publicationYear(pubYear),
          availabilityStatus(availability) {}


    std::string getISBN() const { return ISBN; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
    bool isAvailable() const { return availabilityStatus; }


};


class Books {
public:
    void addBook(const Book& book);
    void loadBooksFromFile(const std::string& filename);
    void displayBooks() const;

    std::vector<Book>::iterator begin() {
        return bookList.begin();
    }

    std::vector<Book>::iterator end() {
        return bookList.end();
    }

    std::vector<Book>::const_iterator begin() const {
        return bookList.begin();
    }

    std::vector<Book>::const_iterator end() const {
        return bookList.end();
    }


private:
    std::vector<Book> bookList;
};

#endif

