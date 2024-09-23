#include <iostream>
#include "functions.hpp"
#include "user.hpp"
#include "books.hpp"
#include <vector>

int main() {
    int option;
    Users users;
    Books books;
    std::string name;

    users.loadUsersFromFile("users.txt");
    books.loadBooksFromFile("book.txt");

    std::cout << "Welcome To Library Management " << std::endl;
    std::cout << "User Management: \n" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Create Account" << std::endl;

    std::cout << "\nOption: ";
    std::cin >> option;
    std::cin.ignore();

    if (option == 1) {
        name = login(users);
        if (!name.empty()) {
            Main_menu(name, books);
        }
    } else if (option == 2) {
        createAccount(users);
        Main_menu(name, books);
    }

    return 0;
}
