#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>
using namespace std;

class Booking {
private:
    struct BookingRecord {
        string userName;
        string eventName;
        int bookingID;
        int ticketCount;
        double totalPrice;
        string status;

        BookingRecord(string name, string event, int id, int tickets = 1) {
            userName = name;
            eventName = event;
            bookingID = id;
            ticketCount = tickets;
            totalPrice = 0.0;
            status = "Confirmed";
        }
    };

    struct Node {
        BookingRecord data;
        Node* next;
        Node(BookingRecord b) : data(b), next(nullptr) {}
    };

    Node* head = nullptr;
    int nextID = 1;

public:
    Booking() : head(nullptr), nextID(1) {}

    ~Booking() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void bookEvent(string userName, string eventName) {
        BookingRecord record(userName, eventName, nextID++);
        Node* newNode = new Node(record);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << " Booking confirmed! ID: " << record.bookingID << "\n";
    }

    void calculateTotal(double price_per_ticket) {
        Node* temp = head;
        while (temp != nullptr) {
            temp->data.totalPrice = temp->data.ticketCount * price_per_ticket;
            temp = temp->next;
        }
    }

    void updateStatus(int bookingID, string new_status) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.bookingID == bookingID) {
                temp->data.status = new_status;
                cout << " Booking status updated to: " << new_status << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << " Booking ID not found.\n";
    }

    void viewBookings(string userName) {
        Node* temp = head;
        bool found = false;
        cout << "\n--- Your Bookings ---\n";
        while (temp != nullptr) {
            if (temp->data.userName == userName) {
                cout << "ID: " << temp->data.bookingID
                     << " | Event: " << temp->data.eventName
                     << " | Tickets: " << temp->data.ticketCount
                     << " | Total: $" << temp->data.totalPrice
                     << " | Status: " << temp->data.status << "\n";
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
            cout << "No bookings found.\n";
    }

    void cancelBooking(int bookingID) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr) {
            if (temp->data.bookingID == bookingID) {
                if (prev == nullptr)
                    head = temp->next;
                else
                    prev->next = temp->next;
                delete temp;
                cout << " Booking cancelled.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << " Booking ID not found.\n";
    }

    int getNextID() const {
        return nextID;
    }
};

#endif
