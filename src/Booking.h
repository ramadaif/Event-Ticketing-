#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKINGS = 500;

struct BookingRecord {
    int    bookingId;
    string userName;
    int    eventId;
    string eventName;
    string eventDate;
    int    ticketCount;
    double totalPrice;
    string status;
    string paymentMethod;
};

class Booking {
private:
    BookingRecord bookings[MAX_BOOKINGS];
    int count  = 0;
    int nextId = 1001;

    // print el booking el wad dah
    void printBooking(int i) {
        cout << "  Booking ID  : " << bookings[i].bookingId    << "\n"
             << "  Event       : " << bookings[i].eventName     << "\n"
             << "  Date        : " << bookings[i].eventDate     << "\n"
             << "  Tickets     : " << bookings[i].ticketCount   << "\n"
             << "  Total Paid  : $" << bookings[i].totalPrice   << "\n"
             << "  Payment     : " << bookings[i].paymentMethod << "\n"
             << "  Status      : " << bookings[i].status        << "\n"
             << "  ----------------------------------------\n";
    }

public:

    // el user book ticket - payment gwa hena kman
    int bookEvent(string userName, int eventId, string eventName, string eventDate, int qty, double pricePerTicket) {
        if (count >= MAX_BOOKINGS) { cout << "  el system msh fr gh.\n"; return -1; }

        // el user y5tar tary2et el daf3
        int payChoice = 0;
        string payment;
        cout << "\n--- ektar tary2et el daf3 ---\n";
        cout << "1. Cash\n";
        cout << "2. Credit Card\n";
        cout << "3. Online Transfer\n";
        cout << "Enter choice: ";
        cin >> payChoice;

        if      (payChoice == 1) payment = "Cash";
        else if (payChoice == 2) payment = "Credit Card";
        else if (payChoice == 3) payment = "Online Transfer";
        else { cout << "  el e5tyar dah msh sah, el booking etlgha.\n"; return -1; }

        // save el booking
        bookings[count].bookingId     = nextId++;
        bookings[count].userName      = userName;
        bookings[count].eventId       = eventId;
        bookings[count].eventName     = eventName;
        bookings[count].eventDate     = eventDate;
        bookings[count].ticketCount   = qty;
        bookings[count].totalPrice    = qty * pricePerTicket;
        bookings[count].status        = "Confirmed";
        bookings[count].paymentMethod = payment;
        count++;

        // confirmation - wry el tafasil
        cout << "\n========================================\n";
        cout << "         BOOKING CONFIRMED!\n";
        cout << "========================================\n";
        printBooking(count - 1);
        cout << "  7afz el booking ID (" << bookings[count - 1].bookingId << ") 3andak.\n";
        cout << "========================================\n";

        return bookings[count - 1].bookingId;
    }

    // wry bookings el user dah bas
    void viewBookings(string userName) {
        cout << "\n========== Your Bookings ==========\n";
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (bookings[i].userName == userName) {
                printBooking(i);
                found = true;
            }
        }
        if (!found) cout << "  mafish bookings lsa.\n";
    }

    // cancel el booking w rg3 el tickets
    bool cancelBooking(string userName, int bookingId, int& outEventId, int& outQty) {
        for (int i = 0; i < count; i++) {
            if (bookings[i].bookingId == bookingId && bookings[i].userName == userName) {
                if (bookings[i].status == "Cancelled") {
                    cout << "  el booking dah etlgha 3bl kdh.\n";
                    return false;
                }
                outEventId = bookings[i].eventId;
                outQty     = bookings[i].ticketCount;
                bookings[i].status = "Cancelled";
                cout << "  el booking etlgha tamam.\n";
                return true;
            }
        }
        cout << "  el booking msh mwgod aw msh bta3tak.\n";
        return false;
    }

    // dah lel admin - wry kol el bookings
    void viewAllBookings() {
        cout << "\n========== All Bookings ==========\n";
        if (count == 0) { cout << "  mafish bookings 5alas.\n"; return; }
        for (int i = 0; i < count; i++) {
            cout << "  User: " << bookings[i].userName << "\n";
            printBooking(i);
        }
    }
};

#endif
