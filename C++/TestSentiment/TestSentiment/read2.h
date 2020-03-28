#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <algorithm>
#include <map>

class sentiment {
private:
	// std::vector<std::string> postive;
	// std::vector<std::string> negative;
	std::vector<std::string> temp;
	std::map <std::string, double> result;
	std::string fileName;
	std::string line;
	double posCount = 0;
	double negCount = 0;
	double totalCount = 0;
	double posPerc = 0;
	double negPerc = 0;

public:
	sentiment();
	sentiment(std::string);
	std::vector<std::string> readText();
	std::string getFileName();
	std::map <std::string, double> checkSentiment(std::vector<std::string>, std::vector<std::string>, std::vector<std::string>);
	std::vector<std::string> getReadTextArr();
};