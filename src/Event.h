#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
using namespace std;

class Event {
public:
    struct EventRecord {
        int eventID;
        string name;
        string date;
        string location;
        int availableTickets;

        EventRecord(int id, string n, string d, string l, int t) {
            eventID = id;
            name = n;
            date = d;
            location = l;
            availableTickets = t;
        }
    };

private:
    struct Node {
        EventRecord data;
        Node* next;
        Node(EventRecord e) : data(e), next(nullptr) {}
    };

    Node* head = nullptr;
    int nextID = 1;

public:
    Event() : head(nullptr), nextID(1) {}

    ~Event() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void addEvent(string name, string date, string location, int tickets) {
        EventRecord e(nextID++, name, date, location, tickets);
        Node* newNode = new Node(e);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << " Event added successfully! ID: " << e.eventID << "\n";
    }

    void browseEvents() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "No events available.\n";
            return;
        }
        cout << "\n--- Available Events ---\n";
        while (temp != nullptr) {
            cout << "ID: " << temp->data.eventID
                 << " | " << temp->data.name
                 << " | " << temp->data.date
                 << " | " << temp->data.location
                 << " | Tickets: " << temp->data.availableTickets << "\n";
            temp = temp->next;
        }
    }

    void searchEvent(string keyword) {
        Node* temp = head;
        bool found = false;
        cout << "\n--- Search Results ---\n";
        while (temp != nullptr) {
            if (temp->data.name.find(keyword) != string::npos ||
                temp->data.location.find(keyword) != string::npos) {
                cout << "ID: " << temp->data.eventID
                     << " | " << temp->data.name
                     << " | " << temp->data.date
                     << " | " << temp->data.location
                     << " | Tickets: " << temp->data.availableTickets << "\n";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "No events found.\n";
    }

    bool reduceTicket(int eventID) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.eventID == eventID) {
                if (temp->data.availableTickets > 0) {
                    temp->data.availableTickets--;
                    return true;
                } else {
                    cout << "No tickets available.\n";
                    return false;
                }
            }
            temp = temp->next;
        }
        cout << "Event not found.\n";
        return false;
    }

    string getEventName(int eventID) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.eventID == eventID)
                return temp->data.name;
            temp = temp->next;
        }
        return "";
    }
};

#endif
