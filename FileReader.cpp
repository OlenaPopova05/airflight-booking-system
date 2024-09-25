#include "FileReader.h"
#include "Manager.h"
#include "Airplane.h"
#include "Ticket.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

void FileReader::read(const std::string& filename, Manager& manager) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return;
    }

    std::string line;
    std::regex rowPriceRegex(R"((\d+)-(\d+)\s+(\d+)\$)");

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        std::string date, flight;
        int seatCount;

        ss >> date >> flight >> seatCount;

        std::vector<std::pair<int, int>> rowPriceData;

        std::string remaining;
        std::getline(ss, remaining);
        std::smatch match;

        while (std::regex_search(remaining, match, rowPriceRegex)) {
            int rowStart = std::stoi(match[1]);
            int rowEnd = std::stoi(match[2]);
            int price = std::stoi(match[3]);

            int numRows = rowEnd - rowStart + 1;

            rowPriceData.push_back({numRows, price});

            remaining = match.suffix().str();
        }

        std::vector<std::vector<Ticket>> airplaneSeats;
        int currentRow = 1;

        for (const auto& rowPrice : rowPriceData) {
            int numRows = rowPrice.first;
            int price = rowPrice.second;

            for (int row = 0; row < numRows; ++row) {
                std::vector<Ticket> seats;

                for (int seat = 0; seat < seatCount; ++seat) {
                    std::string username = "";
                    int ticketId = 0;
                    bool avaliability = true;
                    Ticket ticket(seat + 1,currentRow, username, flight, date, price, ticketId, avaliability);
                    seats.push_back(ticket);
                }

                airplaneSeats.push_back(seats);
                ++currentRow;
            }
        }

        Airplane* airplane = new Airplane(airplaneSeats);
        manager.addAirplane(date, flight, airplane);
    }
    file.close();
}
