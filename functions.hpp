#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "books.hpp"
#include <string>
#include "user.hpp"

void BorrowBook(const std::string& bookName);
void ReserveBook(const std::string& bookName);
std::string generateID(const std::string& name);
void searchBooks(const std::string& bookName);


std::string trim(const std::string& str);
std::string toLower(const std::string& str);
std::string login(const Users& users);
void createAccount(Users& users);
void bookManagement();
void Main_menu(const std::string& name, Books& books);


#endif
