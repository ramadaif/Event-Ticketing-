Sprint 3 — Review
Review Date:
End of Week 6

Attendees:
Full team (7 members) + course instructor representative

Completed Stories
Story ID	User Story	Status	Notes
US-08	View Booking History	Done	Booking list renders with event details and status; accessible at any time.
US-09	Cancel Booking	Done	Cancellation flow complete; booking status updates correctly after confirmation.
US-10	Manage User Profile	Done	Name, phone, and password editable; validation and confirmation message working.
US-12	Event Categories	Done	Category grouping and filter working; filtered results display correctly.

Sprint 3 Demo Summary
The team demonstrated the completed platform end-to-end. Starting from registration and login, the demo walked through event browsing with category filters, ticket booking, payment, and confirmation, followed by viewing booking history and successfully cancelling a booking. The profile management screen was shown with live field validation. All four stories were accepted by the product owner with no critical defects. The product owner noted the category filter as a particularly smooth addition to the browsing experience. Minor copy wording suggestions were logged for post-sprint polish.

Velocity Achieved:
14 Story Points (target: 14 SP) — 100% completion rate.

Overall Project Velocity Summary:
Sprint 1: 18 SP  |  Sprint 2: 16 SP  |  Sprint 3: 14 SP  |  Total: 48 SP across 6 weeks.

Sprint 3 — Retrospective
What Went Well
•	The shared UI component library established mid-sprint significantly reduced duplication across the profile and booking history screens.
•	Integration tests written alongside features caught a booking-cancellation edge case before the demo, saving last-minute debugging time.
•	Team coordination improved over the three sprints; blockers raised in stand-ups were resolved the same day without escalation.
•	Clear acceptance criteria (action item from Sprint 2) meant no ambiguity during the sprint review — all stories passed on first review.

What Could Be Improved
•	The category filter feature required late-stage coordination between the backend and frontend teams that could have been addressed earlier with a shared API contract document.
•	Some edge cases for cancellation (e.g., cancelling an event that has already passed) were discovered during testing rather than during planning.
•	API endpoint documentation was deferred to post-sprint, adding pressure during the final week.

Action Items for Future Reference
Action Item	Owner	Due
Conduct a full end-to-end regression test covering all three sprints before final release	All developers	Post-Sprint 3
Consolidate shared UI components into the component library established in Sprint 3	Karim & Hana	Ongoing
Document all API endpoints and update the project README for final submission	Scrum Master (Mahmoud)	Final Week
