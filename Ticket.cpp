#include "Ticket.h"

Ticket::Ticket(int seat, int row, const std::string& username, const std::string& flightNumber,
    const std::string& date, int price, int ticketID, bool availability) {
    this->seat = seat;
    this->row = row;
    this->username = username;
    this->flightNumber = flightNumber;
    this->date = date;
    this->price = price;
    this->ticketID = ticketID;
    this->availability = availability;
}

bool Ticket::getAvailability() const {
    return availability;
}

void Ticket::setAvailability(bool availability) {
    this->availability = availability;
}

int Ticket::getTicketID() const {
    return ticketID;
}

std::string Ticket::getUsername() const {
    return username;
}

int Ticket::getRow() const {
    return row;
}

int Ticket::getSeat() const {
    return seat;
}

int Ticket::getPrice() const {
    return price;
}

std::string Ticket::getFlightNumber() const {
    return flightNumber;
}

std::string Ticket::getDate() const {
    return date;
}

void Ticket::setUsername(const std::string& username) {
    this->username = username;
}

void Ticket::setTicketID(int ticketID) {
    this->ticketID = ticketID;
}

