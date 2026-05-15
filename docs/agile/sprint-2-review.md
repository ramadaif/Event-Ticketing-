Sprint 2 — Review
Review Date:
End of Week 4

Attendees:
Full team (7 members) + course instructor representative

Completed Stories
Story ID	User Story	Status	Notes
US-06	Book Ticket	Done	Ticket booking flow complete; confirmation message displayed.
US-07	Payment Process	Done	Cash and online payment options working; status updates correctly.
US-11	Receive Booking Confirmation	Done	Confirmation sent after booking; viewable in dashboard.
US-04	Search for Events	Done	Search by name and category working; empty-result message shown.

Sprint 2 Demo Summary
The team demonstrated the end-to-end ticket booking flow: a logged-in user browsed events, selected a ticket quantity, proceeded to payment, chose a payment method, and received an on-screen confirmation. The search feature was also showcased with both keyword and category filters, including the empty-result message. All four stories were accepted by the product owner with no critical defects. Minor UI alignment issues on the payment screen were noted and logged as backlog refinements.

Velocity Achieved:
16 Story Points (target: 16 SP) — 100% completion rate.

Sprint 2 — Retrospective
What Went Well
•	The UI review checklist introduced in Sprint 2 improved screen consistency and caught layout issues before demo day.
•	Writing tests during development (action item from Sprint 1) reduced last-minute bug fixes and gave the team more confidence during the demo.
•	Clear API contracts between frontend and backend teams allowed parallel development with minimal blocking.
•	Payment and booking logic were completed ahead of schedule, leaving time for thorough manual testing.

What Could Be Improved
•	Integration between the booking and payment modules required more coordination than expected; a shared integration test was missing until late in the sprint.
•	Some UI components (buttons, form inputs) were duplicated across screens instead of reused, causing minor inconsistency.
•	The search feature acceptance criteria did not specify pagination behavior, leading to a last-minute design decision.

Action Items for Sprint 3
Action Item	Owner	Due
Add integration tests for booking and payment flows before sprint end	All developers	Ongoing
Establish a shared UI component library to reduce design inconsistency	Karim & Hana	Sprint 3 Day 1
Review and finalize acceptance criteria with the team before Sprint 3 planning	Scrum Master (Mahmoud)	Sprint Planning

