#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H

#include "Event.h"
#include "Ticket.h"
#include "Booking.h"
using namespace std;

class TicketManager {
private:
    Event eventSystem;
    Ticket ticketSystem;
    Booking bookingSystem;

public:
    
    void adminMenu() {
        int choice;
        do {
            cout << "\n===== ADMIN MENU =====\n";
            cout << "1. Add Event\n";
            cout << "2. Browse All Events\n";
            cout << "3. Exit Admin\n";
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
            case 1: {
                string name, date, location;
                int tickets;
                cin.ignore();
                cout << "Event Name: ";
                getline(cin, name);
                cout << "Date: ";
                getline(cin, date);
                cout << "Location: ";
                getline(cin, location);
                cout << "Available Tickets: ";
                cin >> tickets;
                eventSystem.addEvent(name, date, location, tickets);
                break;
            }
            case 2:
                eventSystem.browseEvents();
                break;
            case 3:
                cout << "Exiting Admin Menu.\n";
                break;
            default:
                cout << "Invalid choice.\n";
            }
        } while (choice != 3);
    }

    
    void userMenu(string userName) {
        int choice;
        do {
            cout << "\n===== USER MENU =====\n";
            cout << "1. Browse Events\n";
            cout << "2. Search Events\n";
            cout << "3. Book a Ticket\n";
            cout << "4. View My Tickets\n";
            cout << "5. View My Bookings\n";
            cout << "6. Cancel Booking\n";
            cout << "7. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                eventSystem.browseEvents();
                break;
            case 2: {
                string keyword;
                cin.ignore();
                cout << "Search: ";
                getline(cin, keyword);
                eventSystem.searchEvent(keyword);
                break;
            }
            case 3: {
                int eventID;
                eventSystem.browseEvents();
                cout << "Enter Event ID: ";
                cin >> eventID;
                if (eventSystem.reduceTicket(eventID)) {
                    string eventName = eventSystem.getEventName(eventID);
                    ticketSystem.issueTicket(userName, eventName, "2026-05-07");
                    bookingSystem.bookEvent(userName, eventName);
                }
                break;
            }
            case 4:
                ticketSystem.viewMyTickets(userName);
                break;
            case 5:
                bookingSystem.viewBookings(userName);
                break;
            case 6: {
                int id;
                cout << "Enter Booking ID to cancel: ";
                cin >> id;
                bookingSystem.cancelBooking(id);
                break;
            }
            case 7:
                cout << "Logged out.\n";
                break;
            default:
                cout << "Invalid choice.\n";
            }
        } while (choice != 7);
    }
};

#endif
