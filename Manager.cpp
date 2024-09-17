#include "Manager.h"

using namespace std;

void Manager::addAirplane(const string& date, const string& flight, Airplane* airplane) {
    managingMap[pair(date, flight)] = airplane;
}

Airplane* Manager::searchAirplane(const string& date, const string& flight) {
    return managingMap[pair(date, flight)];
}

