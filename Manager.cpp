#include "Manager.h"

Manager::Manager(int ticketID) : ticketID(ticketID) {}

void Manager::addAirplane(const std::string& date, const std::string& flight, Airplane* airplane) {
    managingMap[std::pair(date, flight)] = airplane;
}

Airplane* Manager::searchAirplane(const std::string& date, const std::string& flight) {
    return managingMap[std::pair(date, flight)];
}

int Manager::getTicketID() {
    return ticketID++;
}