#include <iostream>
#include "register.h"
#include "Booking.h"
#include "TicketManager.h"


using namespace std;
Booking bookingSystem; 
string loggedInUser; 

void eventMenu() {

    int choice;

    do {
        cout << "\n===== EVENT MENU =====\n";
        cout << "1. Browse Events\n";
        cout << "2. Search for Events\n";
         cout << "3. Book an Event\n";      
        cout << "4. View My Bookings\n";   
        cout << "5. Cancel Booking\n"; 
        cout << "6. Logout\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << " Showing all events...\n";
            break;

        case 2:
            cout << " Searching events...\n";
            break;

        case 3: {
              string eventName;
            cout << "Enter event name: ";
            cin.ignore();
            getline(cin, eventName);
            bookingSystem.bookEvent(loggedInUser, eventName);
            break;
        }
        case 4: 
             bookingSystem.viewBookings(loggedInUser);
            break;
        case 5: {
            int id;
            cout << "Enter Booking ID to cancel: ";
            cin >> id;
            bookingSystem.cancelBooking(id);
            break;
        
        }
        case 6:
             cout << " Logged out\n";
            break;
            
        
        default:
            cout << "Invalid choice \n";
        }

    } while (choice != 6);
}

int main() {
    std::cout << "Event Ticketing System Running\n";

    Register r;
    TicketManager tm;
    int choice;

    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Admin Login\n";
        cout << "4. Exit\n";

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

             if (r.login(email, pass))
                tm.userMenu(email);
            break;

             
            
        }

        case 3:
              tm.adminMenu();
            break;
        case 4:
             cout << "Bye!\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

        

    } while (choice != 4);

    return 0;
}
