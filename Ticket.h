#pragma once
#include <string>

class Ticket {
private:
    std::string username;
    int row;
    int seat;
    std::string flightNumber;
    std::string date;
    int price;
    int ticketID;
    bool availability;
public:
    Ticket(int row, int seat, const std::string& username, const std::string& flightNumber,
        const std::string& date, int price, int ticketID, bool availability);

    bool getAvailability() const;
    void setAvailability(bool availability);
    int getTicketID() const;
    std::string getUsername() const;
    int getRow() const;
    int getSeat() const;
    int getPrice() const;
    void setUsername(const std::string& username);
    void setTicketID(int ticketID);
};


