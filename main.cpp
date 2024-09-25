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
                if (airplane->bookTicket(seatIndex, row, username, ticketID)) {
                    std::cout << "Ticket booked" <<  std::endl;
                    std::cout << "Ticket ID: " << ticketID << std::endl;
                }
                else {
                    std::cout << "Ticket not booked" << std::endl;
                }
            }
        }
        else if (command == "return") {
            int ticketID;
            std::cout << "Enter ticket ID: ";
            std::cin >> ticketID;
            for (const auto& airplane : manager.getManagingMap()) {
                airplane.second->returnTicket(ticketID);
            }
        }
        else if (command == "viewID") {
            int ticketID;
            std::cout << "Enter ticket ID: ";
            std::cin >> ticketID;
            bool found = false;
            for (const auto& airplane : manager.getManagingMap()) {
                Ticket* ticket = airplane.second->viewTicketByID(ticketID);
                if (ticket != nullptr) {
                    std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                    int seatIndex = ticket->getSeat();
                    char seat = letters[seatIndex - 1];
                    int row = ticket->getRow();
                    std::cout << "Flight: " << ticket->getFlightNumber() << std::endl;
                    std::cout << "Date: " << ticket->getDate() << std::endl;
                    std::cout << "Seat: " << row << seat << std::endl;
                    std::cout << "Price: " << ticket->getPrice() << "$" << std::endl;
                    std::cout << "User: " << ticket->getUsername() << std::endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Ticket not found" << std::endl;
            }
        }
        else if (command == "viewUser") {
            std::string username;
            std::cout << "Enter username: ";
            std::cin >> username;
            bool found = false;
            for (const auto& airplane : manager.getManagingMap()) {
                std::vector<Ticket> tickets = airplane.second->viewTicketsByUser();
                for (const auto& ticket : tickets) {
                    if (ticket.getUsername() == username) {
                        std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                        int seatIndex = ticket.getSeat();
                        char seat = letters[seatIndex - 1];
                        int row = ticket.getRow();
                        std::cout << "Flight: " << ticket.getFlightNumber() << std::endl;
                        std::cout << "Date: " << ticket.getDate() << std::endl;
                        std::cout << "Seat: " << row << seat << std::endl;
                        std::cout << "Price: " << ticket.getPrice() << "$" << std::endl;
                        found = true;
                    }
                }
            }
            if (!found) {
                std::cout << "No tickets found" << std::endl;
            }
        }
        else if (command == "viewBooked") {
            std::string date, flight;
            std::cout << "Enter date and flight: ";
            std::cin >> date >> flight;
            Airplane* airplane = manager.searchAirplane(date, flight);
            if (airplane == nullptr) {
                std::cout << "Airplane not found" << std::endl;
            }
            else {
                std::cout << "Booked seats: " << std::endl;
                airplane->getBookedSeats();
            }
        }
    }
    return 0;
}

