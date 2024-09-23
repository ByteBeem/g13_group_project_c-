#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>

class User {
private:
    std::string ID;
    std::string name;
    std::string cellphone;

public:
    User(const std::string& id, const std::string& name, const std::string& cellphone)
        : ID(id), name(name), cellphone(cellphone) {}

    std::string getID() const { return ID; }
    std::string getName() const { return name; }
    std::string getCellphone() const { return cellphone; }

};

class Users {
public:
    void addUser(const User& user);
    void addUserToList(const User& user);
    void loadUsersFromFile(const std::string& filename);
    void displayUsers() const;
    const std::vector<User>& getUserList() const;

private:
    std::vector<User> userList;
};

#endif
