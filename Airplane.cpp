#include "Airplane.h"
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
