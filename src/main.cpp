#include <iostream>
#include <string>
#include "User.h"
#include "Event.h"
#include "Booking.h"
using namespace std;

// el objects el asasya bta3t el system
User    userSystem;
Event   eventSystem;
Booking bookingSystem;

string loggedInUser = "";
bool   isAdmin      = false;

// admin credentials - msh mesh mesh
const string ADMIN_EMAIL    = "admin@ticketing.com";
const string ADMIN_PASSWORD = "Admin@123";

void adminMenu();
void userMenu();
void mainMenu();

// ─────────────────────────────────────────────────────────────────────────────
// dah el menu bta3 el admin
void adminMenu() {
    int choice;
    do {
        cout << "\n============================\n";
        cout << "        ADMIN PANEL\n";
        cout << "============================\n";
        cout << "1. View All Events\n";
        cout << "2. Add Event\n";
        cout << "3. Remove Event\n";
        cout << "4. View All Bookings\n";
        cout << "5. View All Users\n";
        cout << "6. Logout\n";
        cout << "============================\n";
        cout << "Choice: ";
        cin >> choice;

        if      (choice == 1) eventSystem.browseEvents();
        else if (choice == 2) eventSystem.adminAddEvent();
        else if (choice == 3) eventSystem.adminRemoveEvent();
        else if (choice == 4) bookingSystem.viewAllBookings();
        else if (choice == 5) userSystem.displayUsers();
        else if (choice == 6) { loggedInUser = ""; isAdmin = false; cout << "  m3 el salama.\n"; }
        else cout << "  e5tyar ghalt.\n";

    } while (choice != 6);
}

// ─────────────────────────────────────────────────────────────────────────────
// dah el menu bta3 el user el 3ady
void userMenu() {
    int choice;
    do {
        cout << "\n============================\n";
        cout << "  Ahlan, " << loggedInUser << "\n";
        cout << "============================\n";
        cout << "1. Browse All Events\n";
        cout << "2. Search Events\n";
        cout << "3. Browse by Category\n";
        cout << "4. View Event Details\n";
        cout << "5. Book a Ticket\n";
        cout << "6. My Bookings\n";
        cout << "7. Cancel a Booking\n";
        cout << "8. Edit My Profile\n";
        cout << "9. Logout\n";
        cout << "============================\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            eventSystem.browseEvents();
        }
        else if (choice == 2) {
            eventSystem.searchEvent();
        }
        else if (choice == 3) {
            eventSystem.browseByCategory();
        }
        else if (choice == 4) {
            // wry el lista el awal 3shan yshuf el IDs
            eventSystem.browseEvents();
            eventSystem.viewDetails();
        }
        else if (choice == 5) {
            // book ticket - wry el events el awal
            eventSystem.browseEvents();

            int eventId, qty;
            cout << "Enter Event ID to book: ";
            cin >> eventId;
            cout << "Enter number of tickets: ";
            cin >> qty;

            if (qty < 1) {
                cout << "  lazm ticket wa7d 3la el a2al.\n";
            }
            else {
                double price = eventSystem.getPrice(eventId);
                if (price >= 0) {
                    string eventName = eventSystem.getName(eventId);
                    string eventDate = eventSystem.getDate(eventId);

                    // wry el 7esab el awal 2bl ma y2kd
                    cout << "\n  Event   : " << eventName << "\n";
                    cout << "  Date    : " << eventDate  << "\n";
                    cout << "  Tickets : " << qty        << "\n";
                    cout << "  Total   : $" << qty * price << "\n";
                    cout << "Confirm? (1=Yes / 0=No): ";
                    int confirm;
                    cin >> confirm;

                    if (confirm == 1) {
                        if (eventSystem.reduceTicket(eventId, qty)) {
                            bookingSystem.bookEvent(loggedInUser, eventId, eventName, eventDate, qty, price);
                        }
                    } else {
                        cout << "  el booking etlgha.\n";
                    }
                }
            }
        }
        else if (choice == 6) {
            bookingSystem.viewBookings(loggedInUser);
        }
        else if (choice == 7) {
            // wry bookings el awal 3shan yshuf el IDs
            bookingSystem.viewBookings(loggedInUser);
            int bid;
            cout << "Enter Booking ID to cancel: ";
            cin >> bid;
            int outEventId = 0, outQty = 0;
            // lw el cancel nge7 rg3 el tickets
            if (bookingSystem.cancelBooking(loggedInUser, bid, outEventId, outQty)) {
                eventSystem.restoreTicket(outEventId, outQty);
            }
        }
        else if (choice == 8) {
            userSystem.editProfile(loggedInUser);
        }
        else if (choice == 9) {
            loggedInUser = "";
            cout << "  m3 el salama.\n";
        }
        else {
            cout << "  e5tyar ghalt.\n";
        }

    } while (choice != 9);
}

// ─────────────────────────────────────────────────────────────────────────────
// el main menu - awl 7aga bttla3
void mainMenu() {
    int choice;
    do {
        cout << "\n====================================\n";
        cout << "    EVENT TICKETING PLATFORM\n";
        cout << "====================================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Admin Login\n";
        cout << "4. Exit\n";
        cout << "====================================\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            userSystem.registerUser();
        }
        else if (choice == 2) {
            string name = userSystem.login();
            if (!name.empty()) {
                loggedInUser = name;
                isAdmin      = false;
                userMenu();
            }
        }
        else if (choice == 3) {
            // admin login - el password case sensitive bas el email la2
            string email, pass;
            cin.ignore();
            cout << "Admin Email: ";    getline(cin, email);
            cout << "Admin Password: "; getline(cin, pass);

            string emailLower = email;
            for (char& c : emailLower) c = tolower(c);

            if (emailLower == ADMIN_EMAIL && pass == ADMIN_PASSWORD) {
                loggedInUser = "Admin";
                isAdmin      = true;
                cout << "  Ahlan admin.\n";
                adminMenu();
            } else {
                cout << "  el credentials ghalta.\n";
            }
        }
        else if (choice == 4) {
            cout << "  m3 el salama!\n";
        }
        else {
            cout << "  e5tyar ghalt.\n";
        }

    } while (choice != 4);
}

// ─────────────────────────────────────────────────────────────────────────────
int main() {
    mainMenu();
    return 0;
}
