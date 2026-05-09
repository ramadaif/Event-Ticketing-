Code Smells Report

All six members of BookingRecord are assigned in the constructor body. This causes each member to be default-initialized first, then overwritten — wasted work. Members like const-qualified or reference types cannot be initialized this way at all.
// ❌ Before 
BookingRecord(string name, string event, int id, int tickets = 1) { userName = name; bookingID = id; eventName = event; ticketCount = tickets; totalPrice = 0.0; status = "Confirmed"; } // ✅ After BookingRecord(string name, string event, int id, int tickets = 1) : userName(name), eventName(event), bookingID(id), ticketCount(tickets), totalPrice(0.0), status("Confirmed") {}


head and nextID already have in-class initializers (= nullptr and = 1). Repeating the same values in the initializer list is redundant noise — the two sites can drift out of sync over time.
// ❌ Before — duplicates what the in-class initializer already does 
Node* head = nullptr; int nextID = 1; ... Booking() : head(nullptr), nextID(1) {} // ✅ After — trust the in-class initializer Node* head = nullptr; int nextID = 1; ... Booking() = default;


A hand-rolled singly linked list adds hundreds of lines of bug-prone boilerplate. std::vector<BookingRecord> or std::list provides the same capabilities with far less code, no manual memory management, and exception safety.
// ❌ Before — manual node + head pointer + delete loop in destructor 
struct Node { BookingRecord data; Node* next; ... }; Node* head = nullptr; // ✅ After #include <vector> std::vector<BookingRecord> bookings;


