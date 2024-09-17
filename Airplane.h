#pragma once
#include <string>
#include <vector>
#include "Ticket.h"

class Airplane {
private:
    std::string date;
    std::string flight;
    int seat;
    std::vector<std::pair<int, int>> rowPriceData;
    std::vector<std::vector<Ticket>> airplaneSeats;
public:
    Airplane(const std::string& date, const std::string& flight, int seat,
             const std::vector<std::pair<int, int>>& rowPriceData,
             const std::vector<std::vector<Ticket>>& airplaneSeats);

    void getAvailableSeats() const;
    std::vector<std::string> getBookedSeats() const;
    void bookTicket(const std::string& seat, int row, const std::string& username,
                    const std::string& flightNumber, const std::string& date,
                    const std::string& price, int ticketID);
    void returnTicket(int ticketID);
    Ticket* viewTicketByID(int ticketID);
    std::vector<Ticket> viewTicketsByUser() const;
    int getSeat() const;
};
