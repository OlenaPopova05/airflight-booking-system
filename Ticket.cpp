#include "Ticket.h""
#include <string>

Ticket :: Ticket(const string& username, const string& seat, const string& flightNumber, const string& date, const string& price, int ticketID) {
    this->username = username;
    this->seat = seat;
    this->flightNumber = flightNumber;
    this->date = date;
    this->price = price;
    this->ticketID = ticketID;
}

int Ticket::getTicketID() {return ticketID;}

string Ticket::getSeat() {return seat;}

string Ticket::getFlightNumber() {return flightNumber;}

string Ticket::getDate() {return date;}

string Ticket::getPrice() {return price;}
