#pragma once
#include <string>

using namespace std;

class FileReader {
private:
    string filename;
public:
    void read(const string& filename);
};