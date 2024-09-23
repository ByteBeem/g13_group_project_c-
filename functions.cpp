#include <sstream>
#include <ctime>
#include <iostream>
#include "functions.hpp"
#include "books.hpp"
#include "user.hpp"
#include <ctime>
#include <sstream>
#include <algorithm>
#include <thread>
#include <chrono>



void BorrowBook(const std::string& bookName) {
    // Implementation of borrowing
    std::cout << "Borrowing book: " << bookName << std::endl;
}

void ReserveBook(const std::string& bookName) {
    // Implementation of reserving
    std::cout << "Reserving book: " << bookName << std::endl;
}

std::string generateID(const std::string& name) {
    std::ostringstream oss;
    oss << name << "_" << std::time(nullptr);
    return oss.str();
}



void searchBooks(Books& books) {
    std::string bookName;
    system("cls");
    std::cout << "Enter the book name: ";
    std::getline(std::cin, bookName);
    bookName = trim(bookName);

    std::cout << "Searching for book: '" << bookName << "'" << std::endl;


    std::cout << "Available books:" << std::endl;
    for (const auto& book : books) {
        std::string title = book.getTitle();
        std::cout << "- " << title << " (trimmed: '" << trim(title) << "', lowercased: '" << toLower(title) << "')" << std::endl;
    }

    auto it = std::find_if(books.begin(), books.end(), [&bookName](const Book& book) {
        return toLower(book.getTitle()) == toLower(bookName);
    });

    if (it != books.end()) {
        std::cout << "Book found: " << it->getTitle() << ", Author: " << it->getAuthor() << std::endl;
    } else {
        std::cout << "Book not found." << std::endl;
    }
}




std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

std::string login(const Users& users) {
     bool isCorrect;
    do{

    std::string username, password;
    system("cls");
    std::cout << "Username is your name.\n" << std::endl;

    std::cout << "Username: ";
    std::getline(std::cin, username);
    username = trim(username);
    system("cls");

    std::cout << "\nPassword is your cellphone number.\n" << std::endl;

    std::cout << "Password: ";
    std::getline(std::cin, password);
    password = trim(password);

    for (const auto& user : users.getUserList()) {
        if (toLower(user.getName()) == toLower(username) &&
            toLower(user.getCellphone()) == toLower(password)) {
                isCorrect = true;
            std::cout << "You logged in successfully." << std::endl;
            return username;
        }
    }

    std::cout << "Login failed. Please check your username and password." << std::endl;

    std::this_thread::sleep_for (std::chrono::seconds(2));

    }while(!isCorrect);

    ;
    return "";
}

void createAccount(Users& users) {
    std::string name, cellphone;
    system("cls");

    std::cout << "Enter Your Name: ";
    std::getline(std::cin, name);
    system("cls");

    std::cout << "Enter Your Cellphone Number: ";
    std::getline(std::cin, cellphone);

    std::string userID = generateID(name);
    User newUser(userID, name, cellphone);

    for (const auto& user : users.getUserList()) {
        if (user.getName() == name && user.getCellphone() == cellphone) {
            std::cout << "User already exists. Please log in." << std::endl;
            return;
        }
    }

    users.addUser(newUser);
    std::cout << "User Registered Successfully!" << std::endl;
    std::cout << "Generated ID: " << newUser.getID() << std::endl;
}




void bookManagement(Books& books) {
    system("cls");
    int option;

    std::cout << "1. Search for a book" << std::endl;
    std::cout << "2. See Available books" << std::endl;
    std::cout << "3. Reserve a book" << std::endl;
    std::cout << "4. Return a book" << std::endl;
    std::cout << "5. Borrowing History" << std::endl;

    std::cout << "\nOption: ";
    std::cin >> option;
    std::cin.ignore();

    switch (option) {
        case 1:

           searchBooks(books);
            break;
        case 2:
          books.displayBooks();
            break;
        case 3:
            // Implement reserve book logic
            break;
        case 4:
            // Implement return book logic
            break;
        case 5:
            // Implement borrowing history logic
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
    }
}



void Main_menu(const std::string& name, Books& books) {
    int option;
    system("cls");

    std::cout << "Welcome back " << name << std::endl;
    std::cout << "\n1. User Management" << std::endl;
    std::cout << "2. Book Management" << std::endl;
    std::cout << "\nOption: ";
    std::cin >> option;

    if (option == 1) {

    } else if (option == 2) {
        bookManagement(books);
    } else {
        std::cout << "Invalid option. Please try again." << std::endl;
    }
}



