#include <iostream>
#include "FileReader.h"
#include "Manager.h"

std::string convertRowToLetter(int rowNumber) {
    std::string result;
    while (rowNumber > 0) {
        rowNumber--;
        result = char('A' + (rowNumber % 26)) + result;
        rowNumber /= 26;
    }
    return result;
}

int main() {
    Manager manager;
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
            std::cout << "Checking for date: " << date << " and flight: " << flight << std::endl;  // Debugging line

            Airplane* airplane = manager.searchAirplane(date, flight);
            if (airplane == nullptr) {
                std::cout << "Airplane not found" << std::endl;
            } else {
                std::cout << "Available seats: " << std::endl;
                airplane->getAvailableSeats();
            }
        }
    }
    return 0;
}

