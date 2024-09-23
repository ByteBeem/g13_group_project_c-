#include <iostream>
#include <fstream>
#include <sstream>
#include "user.hpp"

void Users::addUser(const User& user) {

    for (const auto& existingUser : userList) {
        if (existingUser.getID() == user.getID()) {
            std::cerr << "User with ID " << user.getID() << " already exists." << std::endl;
            return;
        }
    }


    userList.push_back(user);


    std::ofstream file("users.txt", std::ios::app);
    if (file.is_open()) {
        file << user.getID() << "," << user.getName() << "," << user.getCellphone() << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}


void Users::addUserToList(const User& user) {

    userList.push_back(user);
}


void Users::loadUsersFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::istringstream iss(line);
        std::string id, name, cellphone;

        if (std::getline(iss, id, ',') &&
            std::getline(iss, name, ',') &&
            std::getline(iss, cellphone, ',')) {

            if (id.empty() || name.empty() || cellphone.empty()) {
                std::cerr << "Warning: Missing data in line: " << line << std::endl;
                continue;
            }


            addUserToList(User(id, name, cellphone));
        } else {
            std::cerr << "Warning: Could not parse line: " << line << std::endl;
        }
    }

    file.close();
}



void Users::displayUsers() const {
    for (const auto& user : userList) {
        std::cout << "ID: " << user.getID() << ", Name: " << user.getName()
                  << ", Cellphone: " << user.getCellphone() << std::endl;
    }
}

const std::vector<User>& Users::getUserList() const {
    return userList;
}

