#include <iostream>
#include "FileReader.h"
#include "Manager.h"


int main() {
    Manager manager(1);
    FileReader fileReader;
    fileReader.read("/Users/olenapopova/Documents/GitHub/untitled4/config.txt", manager);
    while (true) {
        std::cout << "Enter command: ";
        std::string command;
        std::cin >> command;
        if (command == "exit") {
            break;
        }
        if (command == "check") {
            std::string date, flight;
            std::cout << "Enter date and flight: ";
            std::cin >> date >> flight;
            Airplane* airplane = manager.searchAirplane(date, flight);
            if (airplane == nullptr) {
                std::cout << "Airplane not found" << std::endl;
            } else {
                std::cout << "Available seats: " << std::endl;
                airplane->getAvailableSeats();
            }
        }
        else if (command == "book") {
            std::string date, flight, username, place;
            std::cout << "Enter date, flight, place, username: ";
            std::cin >> date >> flight >> place >> username;
            Airplane* airplane = manager.searchAirplane(date, flight);
            if (airplane == nullptr) {
                std::cout << "Airplane not found" << std::endl;
            }
            else {
                int row = std::stoi(place) - 1;
                std::string seat = place.substr(place.size() - 1);
                std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                int seatIndex = letters.find(seat);
                int ticketID = manager.getTicketID();
                if (airplane->bookTicket(seatIndex, row, username, flight, date, ticketID)) {
                    std::cout << "Ticket booked" << std::endl;
                }
                else {
                    std::cout << "Ticket not booked" << std::endl;
                }
            }
        }
    }
    return 0;
}

