#include <iostream>
#include "FileReader.h"
#include "Manager.h"

int main() {
    Manager manager;
    FileReader fileReader;
    fileReader.read("/Users/olenapopova/Documents/GitHub/untitled4/config.txt", manager);
    return 0;
}
