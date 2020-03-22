#ifndef SHAREDRESOURCE_H
#define SHAREDRESOURCE_H
#include <string>
#include <vector>
using namespace std;

class sharedresource{
protected:
    string csvfilepath;
    vector<string> csvReaderParsedData1;
    vector<string> csvReaderParsedData2;
    string keyword1;
    string keyword2;
public:
    sharedresource(string);
    sharedresource(string, string, string);
    void setCsvReaderParsedData1();
    void setCsvReaderParsedData2();
};
#endif // SHAREDRESOURCE_H
