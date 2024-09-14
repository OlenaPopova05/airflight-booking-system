#pragma once
#include <string>
#include "Manager.h"

class FileReader {
private:
    std::string filename;
public:
    void read(const std::string& filename, Manager& manager);
    void fillManager(Manager& manager);
};
