#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
using namespace std;

class Ticket {
public:
    struct TicketRecord {
        int ticketID;
        string userName;
        string eventName;
        string date;

        TicketRecord(int id, string name, string event, string d) {
            ticketID = id;
            userName = name;
            eventName = event;
            date = d;
        }
    };

private:
    struct Node {
        TicketRecord data;
        Node* next;
        Node(TicketRecord t) : data(t), next(nullptr) {}
    };

    Node* head = nullptr;
    int nextID = 1;

public:
    Ticket() : head(nullptr), nextID(1) {}

    ~Ticket() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void issueTicket(string userName, string eventName, string date) {
        TicketRecord t(nextID++, userName, eventName, date);
        Node* newNode = new Node(t);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << " Ticket issued! Ticket ID: " << t.ticketID << "\n";
    }

    void viewMyTickets(string userName) {
        Node* temp = head;
        bool found = false;
        cout << "\n--- My Tickets ---\n";
        while (temp != nullptr) {
            if (temp->data.userName == userName) {
                cout << "Ticket ID: " << temp->data.ticketID
                     << " | Event: " << temp->data.eventName
                     << " | Date: " << temp->data.date << "\n";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "No tickets found.\n";
    }
};

#endif
