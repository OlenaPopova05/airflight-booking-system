#include "Manager.h"

using namespace std;

void Manager::addAirplane(const string& date, const string& flight, Airplane* airplane) {
    managingMap[pair(date, flight)] = airplane;
}



