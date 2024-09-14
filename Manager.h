#pragma once
#include <string>
#include <map>
#include "Airplane.h"

class Manager {
private:
    std::map<std::pair<std::string, std::string>, Airplane*> managingMap;
public:
    void addAirplane(const std::string& date, const std::string& flight, Airplane* airplane);
    Airplane* searchAirplane(const std::string& date, const std::string& flight);
};

