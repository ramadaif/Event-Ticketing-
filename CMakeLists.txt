cmake_minimum_required(VERSION 3.10)
project(EventTicketingPlatform)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/Event.cpp
    src/Ticket.cpp
    src/User.cpp
    src/Booking.cpp
    src/TicketManager.cpp
)

add_executable(event_ticketing
    src/main.cpp
    ${SOURCES}
)

add_executable(run_tests
    tests/test_main.cpp
    ${SOURCES}
)

enable_testing()
add_test(NAME TicketingTests COMMAND run_tests)
