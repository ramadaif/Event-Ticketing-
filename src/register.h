#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <string>
using namespace std;

class Register {

private:

    struct User {
        string name;
        string email;
        string password;

        User(string n, string e, string p) {
            name = n;
            email = e;
            password = p;
        }
    };

    struct Node {
        User data;
        Node* next;

         
    };

    Node* head = nullptr;

public:
 Register() : head(nullptr) {}

 
    Register() : head(nullptr) {}


~Register() {

    Node* temp;

    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    cout << "Memory cleared\n";

  
=======
    // 1. Register (from backlog)
    void registerUser() {

        string name, email, pass;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Email: ";
        getline(cin, email);

        cout << "Enter Password: ";
        getline(cin, pass);

        // validation
        if (name.empty() || email.empty() || pass.empty()) {
            cout << " Invalid input\n";
            return;
        }

        
        User u(name, email, pass);
        Node* newNode = new Node(u);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << " Account created successfully!\n";
    }

    // 2. Login (from backlog)
    bool login(string email, string password) {

        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data.email == email &&
                temp->data.password == password) {

                cout << " Login successful\n";
                return true;
            }

            temp = temp->next;
        }

        cout << " Invalid credentials\n";
        return false;
        ~Register() {

        Node* temp;

        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }

        cout << "List cleared\n";
    }
     Register(const Register&) = delete;
    Register& operator=(const Register&) = delete;
    
    }

   
    void displayUsers() {

        Node* temp = head;

        cout << "\n--- Users ---\n";

        while (temp != nullptr) {
            cout << temp->data.name << " | "
                << temp->data.email << endl;

            temp = temp->next;
        }
    }
};

#endif
