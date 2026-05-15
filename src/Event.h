#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_EVENTS = 100;

struct EventRecord {
    int    id;
    string name;
    string category;
    string date;
    string location;
    double price;
    int    totalTickets;
    int    availableTickets;
};

class Event {
private:
    EventRecord events[MAX_EVENTS];
    int count  = 0;
    int nextId = 1;

    // print el event el wad dah
    void printEvent(int i) {
        cout << "  [ID: "        << events[i].id               << "] " << events[i].name << "\n"
             << "   Category  : " << events[i].category        << "\n"
             << "   Date      : " << events[i].date            << "\n"
             << "   Location  : " << events[i].location        << "\n"
             << "   Price     : $" << events[i].price          << "\n"
             << "   Available : " << events[i].availableTickets
             << " / "              << events[i].totalTickets    << " tickets\n"
             << "  ----------------------------------------\n";
    }

    // dawer bel id
    int findById(int id) {
        for (int i = 0; i < count; i++)
            if (events[i].id == id) return i;
        return -1;
    }

public:

    Event() {
        // el events el mab2alsh 3aleha - data aslya
        addEventDirect("Tech Conference 2026",  "Technology", "2026-07-15", "Cairo Convention Centre", 150.00, 200);
        addEventDirect("Summer Music Festival", "Music",      "2026-08-01", "El-Sawy Culturewheel",     80.00, 500);
        addEventDirect("Startup Pitch Night",   "Business",   "2026-06-20", "GrEEK Campus, Cairo",      50.00, 100);
        addEventDirect("Art Exhibition",        "Arts",       "2026-07-05", "Cairo Opera House",         30.00, 300);
        addEventDirect("Football Tournament",   "Sports",     "2026-06-28", "Cairo Stadium",             25.00, 1000);
    }

    // dah bndeh mn el constructor w mn el admin
    void addEventDirect(string name, string category, string date, string location, double price, int tickets) {
        if (count >= MAX_EVENTS) return;
        events[count].id               = nextId++;
        events[count].name             = name;
        events[count].category         = category;
        events[count].date             = date;
        events[count].location         = location;
        events[count].price            = price;
        events[count].totalTickets     = tickets;
        events[count].availableTickets = tickets;
        count++;
    }

    // wry kol el events
    void browseEvents() {
        cout << "\n========== All Events ==========\n";
        if (count == 0) { cout << "  mafish events.\n"; return; }
        for (int i = 0; i < count; i++) printEvent(i);
    }

    // search bel esm aw el category
    void searchEvent() {
        string keyword;
        cin.ignore();
        cout << "\nSearch by event name or pick a category:\n";
        cout << "  Categories: Technology | Music | Business | Arts | Sports\n";
        cout << "Enter keyword or category: ";
        getline(cin, keyword);

        // 5ali el search case insensitive
        string kwLower = keyword;
        for (char& c : kwLower) c = tolower(c);

        cout << "\n========== Search Results ==========\n";
        bool found = false;
        for (int i = 0; i < count; i++) {
            string nameLower = events[i].name;
            string catLower  = events[i].category;
            for (char& c : nameLower) c = tolower(c);
            for (char& c : catLower)  c = tolower(c);

            if (nameLower.find(kwLower) != string::npos || catLower.find(kwLower) != string::npos) {
                printEvent(i);
                found = true;
            }
        }
        if (!found) cout << "  mafish 7aga bel esm dah.\n";
    }

    // wry el event bel id bta3to
    void viewDetails() {
        int id;
        cout << "Enter Event ID: ";
        cin >> id;
        int i = findById(id);
        if (i == -1) { cout << "  el event msh mwgod.\n"; return; }
        cout << "\n========== Event Details ==========\n";
        printEvent(i);
    }

    // filter bel category
    void browseByCategory() {
        cout << "\nAvailable categories:\n";
        cout << "  1. Technology\n";
        cout << "  2. Music\n";
        cout << "  3. Business\n";
        cout << "  4. Arts\n";
        cout << "  5. Sports\n";
        string cat;
        cin.ignore();
        cout << "Enter category name: ";
        getline(cin, cat);

        string catLower = cat;
        for (char& c : catLower) c = tolower(c);

        cout << "\n========== Events in \"" << cat << "\" ==========\n";
        bool found = false;
        for (int i = 0; i < count; i++) {
            string eLower = events[i].category;
            for (char& c : eLower) c = tolower(c);
            if (eLower == catLower) { printEvent(i); found = true; }
        }
        if (!found) cout << "  mafish events f el category di.\n";
    }

    // admin bydef event gdid
    void adminAddEvent() {
        if (count >= MAX_EVENTS) { cout << "  el lista 3andaha limit.\n"; return; }
        string name, category, date, location;
        double price;
        int tickets;
        cin.ignore();
        cout << "\n--- Event Gdid ---\n";
        cout << "Event Name: ";        getline(cin, name);
        cout << "Category: ";          getline(cin, category);
        cout << "Date (YYYY-MM-DD): "; getline(cin, date);
        cout << "Location: ";          getline(cin, location);
        cout << "Ticket Price ($): ";  cin >> price;
        cout << "Total Tickets: ";     cin >> tickets;

        if (name.empty() || category.empty()) {
            cout << "  lazm tektb el esm wel category.\n";
            return;
        }
        addEventDirect(name, category, date, location, price, tickets);
        cout << "  el event etdaf tamam, ID bta3to: " << (nextId - 1) << ".\n";
    }

    // admin bymsh al event
    void adminRemoveEvent() {
        int id;
        cout << "Enter Event ID to remove: ";
        cin >> id;
        int i = findById(id);
        if (i == -1) { cout << "  el event msh mwgod.\n"; return; }
        // rg3 el ba2y l wara
        for (int j = i; j < count - 1; j++) events[j] = events[j + 1];
        count--;
        cout << "  el event etmsha.\n";
    }

    // n2s mn el tickets lma 7ad ybook
    bool reduceTicket(int id, int qty) {
        int i = findById(id);
        if (i == -1) { cout << "  el event msh mwgod.\n"; return false; }
        if (events[i].availableTickets < qty) {
            cout << "  mafish tickets kfaya, el mwgod: " << events[i].availableTickets << ".\n";
            return false;
        }
        events[i].availableTickets -= qty;
        return true;
    }

    // rg3 el tickets lma 7ad ycancel
    void restoreTicket(int id, int qty) {
        int i = findById(id);
        if (i != -1) events[i].availableTickets += qty;
    }

    double getPrice(int id) {
        int i = findById(id);
        if (i == -1) { cout << "  el event msh mwgod.\n"; return -1; }
        return events[i].price;
    }

    string getName(int id) {
        int i = findById(id);
        if (i == -1) return "Unknown Event";
        return events[i].name;
    }

    string getDate(int id) {
        int i = findById(id);
        if (i == -1) return "Unknown Date";
        return events[i].date;
    }
};

#endif
