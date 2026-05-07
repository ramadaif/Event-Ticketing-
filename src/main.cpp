#include <iostream>
#include "register.h"

using namespace std;

void eventMenu() {

    int choice;

    do {
        cout << "\n===== EVENT MENU =====\n";
        cout << "3. Browse Events\n";
        cout << "4. Search for Events\n";
        cout << "5. Logout\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 3:
            cout << " Showing all events...\n";
            break;

        case 4:
            cout << " Searching events...\n";
            break;

        case 5:
            cout << " Logged out\n";
            break;

        default:
            cout << "Invalid choice \n";
        }

    } while (choice != 5);
}

int main() {
    std::cout << "Event Ticketing System Running\n";

    Register r;
    int choice;

    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            r.registerUser();
            break;

        case 2: {
            string email, pass;

            cout << "Email: ";
            cin >> email;

            cout << "Password: ";
            cin >> pass;

            bool success = r.login(email, pass);

            if (success) {
                eventMenu(); 
            }

            break;
        }

        case 3:
            cout << "Bye \n";
            break;

        default:
            cout << "Invalid choice \n";
        }

    } while (choice != 3);

    return 0;
}
