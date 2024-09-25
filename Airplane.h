#pragma once
#include <string>
#include <vector>
#include "Ticket.h"

class Airplane {
private:
    std::vector<std::vector<Ticket>> airplaneSeats;
public:
    Airplane(const std::vector<std::vector<Ticket>>& airplaneSeats):
             airplaneSeats(airplaneSeats) {};

    void getAvailableSeats() const;
    void getBookedSeats() const;
    bool bookTicket(int seat, int row, const std::string& username, int ticketID);
    void returnTicket(int ticketID);
    Ticket* viewTicketByID(int ticketID);
    std::vector<Ticket> viewTicketsByUser() const;
};
