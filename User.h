#pragma once

#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sys/stat.h>

using namespace std;
class User {
private:
    int* id;
    string* username;
    string* password;
    string* role;
    string* name;
    string* lastname;
    time_t* date_joined;

public:
    User();
    ~User();

    int getId() const;
    string getUsername() const;
    string getPassword() const;
    string getRole() const;
    string getName() const;
    string getLastname() const;
    time_t getDateJoined() const;

    void setId(int id);
    void setUsername(const string& username);
    void setPassword(const string& password);
    void setRole(const string& role);
    void setName(const string& name);
    void setLastname(const string& lastname);
    void setDateJoined(time_t date_joined);

    void addUser();
    void editUser();
    void viewUser() const;
    void deleteUser();
    void displayMenu();
    bool isAdmin() const;

    static void initializeDefaultAdmin();
    static bool usersExist();
    static bool loadUserFromFile(User& user, const string& username);
    static void saveUserToFile(const User& user);
};
