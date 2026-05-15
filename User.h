#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_USERS = 100;

struct UserRecord {
    string name;
    string email;
    string password;
};

class User {
private:
    UserRecord users[MAX_USERS];
    int count = 0;

    // dawer 3la el user bel email
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
            cout << "  el system msh fr gh.\n";
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

        // check en el fields msh fadya
        if (name.empty() || email.empty() || password.empty()) {
            cout << "  Error: emla kol el fields.\n";
            return false;
        }
        if (email.find('@') == string::npos || email.find('.') == string::npos) {
            cout << "  Error: el email msh sah.\n";
            return false;
        }
        if (findByEmail(email) != -1) {
            cout << "  Error: el email dh mwgod 3nna 5alas.\n";
            return false;
        }

        users[count].name     = name;
        users[count].email    = email;
        users[count].password = password;
        count++;

        cout << "  Account etla3 tamam! Ahlan " << name << ".\n";
        return true;
    }

    // login - rg3 el esm law sah wala string fadya
    string login() {
        string email, password;
        cin.ignore();
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Password: ";
        getline(cin, password);

        int i = findByEmail(email);
        if (i != -1 && users[i].password == password) {
            cout << "  Ahlan tany " << users[i].name << "!\n";
            return users[i].name;
        }
        cout << "  Error: el email aw el password ghalt.\n";
        return "";
    }

    // el user 3ayz yghyr data bta3to
    void editProfile(string currentName) {
        for (int i = 0; i < count; i++) {
            if (users[i].name == currentName) {
                string newName, newPassword;
                cin.ignore();
                cout << "\n--- 3dl el profile ---\n";
                cout << "Esm gdid (sibu fadya law msh 3ayz tghyr): ";
                getline(cin, newName);
                cout << "Password gdid (sibu fadya law msh 3ayz tghyr): ";
                getline(cin, newPassword);

                if (!newName.empty())     users[i].name     = newName;
                if (!newPassword.empty()) users[i].password = newPassword;

                cout << "  etghayr tamam.\n";
                return;
            }
        }
        cout << "  el user msh mwgod.\n";
    }

    // dah lel admin bas
    void displayUsers() {
        cout << "\n--- kol el users ---\n";
        if (count == 0) {
            cout << "  mafish users lsa.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "  " << users[i].name << " | " << users[i].email << "\n";
        }
    }
};

#endif