#include "Airplane.h"
#include "Manager.h"
#include <iostream>

Airplane::Airplane(const std::string& date, const std::string& flight, int seat,
                   const std::vector<std::pair<int, int>>& rowPriceData,
                   const std::vector<std::vector<Ticket>>& airplaneSeats) {
    this->date = date;
    this->flight = flight;
    this->seat = seat;
    this->rowPriceData = rowPriceData;
    this->airplaneSeats = airplaneSeats;
}
void Airplane::getAvailableSeats() const {
    for (const auto& row : airplaneSeats) {
        for (const auto& seat : row) {
            if (seat.getAvailability()) {
                std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                std::cout << seat.getRow() << letters[seat.getSeat() - 1] << " " << seat.getPrice() << "$" << std::endl;
            }
        }
    }
}

int Airplane::getSeat() const {
    return seat;
}

bool Airplane::bookTicket(int seat, int row, const std::string& username,
                          const std::string& flightNumber, const std::string& date, int ticketID) {
    if (airplaneSeats[row][seat].getAvailability()) {
        airplaneSeats[row][seat].setAvailability(false);
        airplaneSeats[row][seat].setUsername(username);
        airplaneSeats[row][seat].setTicketID(ticketID);
        return true;
    }
    return false;
}
