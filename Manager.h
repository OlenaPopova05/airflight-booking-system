#pragma once
#include <string>
#include <map>
#include "Airplane.h"

using namespace std;

class Manager {
private:
    map<pair<string, string>, Airplane> managingMap;
public:
    void addAirplane(const string& date, const string& flight, const string& seat, int row, Ticket airplaneSeats[seat][row]);
    Airplane* searchAirplane(const string& date, const string& flight);
};
