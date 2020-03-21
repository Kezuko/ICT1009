#ifndef SEARCH_H
#define SEARCH_H
#include <string>
#include <vector>
#include "sharedresource.h"
using namespace std;

class display : public sharedresource{
private:
    string csvfilepath;
    vector<string> csvReaderParsedData1;
    vector<string> csvReaderParsedData2;
    string keyword1;
    string keyword2;
public:
    display(string csvPath, string keyword1, string keyword2) : sharedresource(csvPath, keyword1, keyword2){
        this->csvfilepath = csvPath;
        this->keyword1 = keyword1;
        this->keyword2 = keyword2;
    }
    vector<string> displayFirstComparisonTable();
    vector<string> displaySecondComparisonTable();
};
#endif // SEARCH_H
