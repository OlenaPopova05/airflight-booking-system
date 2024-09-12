#pragma once
#include <string>
using namespace std;

class Ticket {
private:
    string username;
    int row;
    string seat;
    string flightNumber;
    string date;
    string price;
    int ticketID;
    bool availability;
public:
    Ticket(const string& username, int row, const string& seat, const string& flightNumber,
        const string& date, const string& price, int ticketID, bool availability);
};

