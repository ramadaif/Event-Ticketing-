#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class User {
private:
    const int MAX_USERS = 100;
    
    struct UserRecord {
        string name;
        string email;
        string password;
    };
    
    UserRecord users[MAX_USERS];
    int count = 0;
    
    // find user by email
    int findByEmail(string email) {
        for (char& c : email) c = tolower(c);
        for (int i = 0; i < count; i++) {
            string stored = users[i].email;
            for (char& c : stored) c = tolower(c);
            if (stored == email) return i;
        }
        return -1;
    }
    
public:
    bool registerUser() {
        if (count >= MAX_USERS) {
            cout << "System is full.\n";
            return false;
        }
        string name, email, password;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Password: ";
        getline(cin, password);
        
        if (name.empty() || email.empty() || password.empty()) {
            cout << "Error: Fill all fields.\n";
            return false;
        }
        if (email.find('@') == string::npos || email.find('.') == string::npos) {
            cout << "Error: Invalid email.\n";
            return false;
        }
        if (findByEmail(email) != -1) {
            cout << "Error: Email already exists.\n";
            return false;
        }
        
        users[count].name = name;
        users[count].email = email;
        users[count].password = password;
        count++;
        
        cout << "Account created successfully! Welcome " << name << ".\n";
        return true;
    }
    
    string login() {
        string email, password;
        cin.ignore();
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Password: ";
        getline(cin, password);
        
        int i = findByEmail(email);
        if (i != -1 && users[i].password == password) {
            cout << "Welcome back " << users[i].name << "!\n";
            return users[i].name;
        }
        cout << "Error: Invalid email or password.\n";
        return "";
    }
    
    void displayUsers() {
        cout << "\n--- All Users ---\n";
        if (count == 0) {
            cout << "No users yet.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << users[i].name << " | " << users[i].email << "\n";
        }
    }
    
    void editProfile(string currentName) {
        for (int i = 0; i < count; i++) {
            if (users[i].name == currentName) {
                string newName, newPassword;
                cin.ignore();
                cout << "\n--- Edit Profile ---\n";
                cout << "New name (leave empty to keep): ";
                getline(cin, newName);
                cout << "New password (leave empty to keep): ";
                getline(cin, newPassword);
                
                if (!newName.empty()) users[i].name = newName;
                if (!newPassword.empty()) users[i].password = newPassword;
                
                cout << "Profile updated successfully!\n";
                return;
            }
        }
        cout << "User not found.\n";
    }
};

#endif
