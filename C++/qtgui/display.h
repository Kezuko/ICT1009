#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>
#include <vector>
#include "sharedresource.h"
using namespace std;

class display : public sharedresource{
private:
    string csvfilepath;
    vector<string> csvReaderParsedData;

public:
    display(string csvPath) : sharedresource(csvPath){
        this->csvfilepath = csvPath;
    }
    vector<string> displayTable();
};
#endif // DISPLAY_H
