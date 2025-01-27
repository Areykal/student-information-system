#pragma once

#include <iostream>
#include <cstring>
#include <regex>
using namespace std;

class User
{
private:
    string username;
    string password;
    string role;

public:
    User() : username("Unknown"), password("Unknown"), role("Unknown") {}
    User(string username) : username(username) {}
    User(string username, string password, string role) : username(username), password(password), role(role) {}

    string getUsername() const
    {
        return username;
    }
    string getPassword() const
    {
        return password;
    }
    string getRole() const
    {
        return role;
    }
    void setUsername(string username)
    {
        if (isValidUsername(username))
        {
            this->username = username;
        }
    }
    void setPassword(string password)
    {
        if (isValidPassword(password))
        {
            this->password = password;
        }
    }
    void setRole(string role)
    {
        if (isValidRole(role))
        {
            this->role = role;
        }
    }

    bool isValidUsername(string username)
    {
        return all_of(username.begin(), username.end(), [](char ch)
                      { return (isalpha(ch) || isspace(ch)); });
    }
    bool isValidPassword(string password)
    {
        const regex pattern("[A-Z a-z 0-9 @#!*&]+");
        return regex_match(password, pattern);
    }
    bool isValidRole(string role)
    {
        const regex pattern("[a-z]+");
        return regex_match(role, pattern);
    }

    void inputUser()
    {
        inputUserUsername();
        inputUserPassword();
        inputUserRole();
    }
    void inputUserUsername()
    {
        do
        {
            cout << "Input Username: ";
            cin >> username;
            this->setUsername(username);
        } while (!isValidUsername(username));
    }
    void inputUserPassword()
    {
        do
        {
            cout << "Input Password: ";
            cin >> password;
            this->setPassword(password);
        } while (!isValidPassword(password));
    }
    void inputUserRole()
    {
        do
        {
            cout << "Input Role: ";
            cin >> role;
            this->setRole(role);
        } while (!isValidRole(role));
    }

    void outputUser()
    {
        cout << username << " \t\t " << password << " \t\t " << role << endl;
    }
    void outputIndividualUser()
    {
        cout << "Username: " << username << endl
             << "Passsword: " << password << endl
             << "Role: " << role << endl;
    }
};