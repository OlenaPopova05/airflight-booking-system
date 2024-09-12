#pragma once
#include <string>
#include "Ticket.h"

using namespace std;

class Airplane {
private:
    string date;
    string flight;
    string seat;
    int row;
    Ticket airplaneSeats[seat][row];
public:
    Airplane(const string& date, const string& flight, const string& seat, int row, Ticket airplaneSeats[seat][row]);
    vector<string> getAvailableSeats();
    vector<string> getBookedSeats();
    void bookTicket(const string& seat, int row, const string& username, const string& flightNumber,
        const string& date, const string& price, int ticketID);
    void returnTicket(int ticketID);
    Ticket* viewTicketByID(int ticketID);
    vector<Ticket> viewTicketsByUser();
};
