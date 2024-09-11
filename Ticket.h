#pragma once
#include <string>
using namespace std;

class Ticket {
private:
    string username;
    string seat;
    string flightNumber;
    string date;
    string price;
    int ticketID;

public:
    Ticket(const string& username, const string& seat, const string& flightNumber, const string& date, const string& price, int ticketID);

    int getTicketID();
    string getSeat();
    string getFlightNumber();
    string getDate();
    string getPrice();
};
