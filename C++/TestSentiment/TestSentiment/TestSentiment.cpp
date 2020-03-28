#include "parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>
#include "read2.h"

using namespace std;

int main(){

	vector<string> sharedParsedData;
	vector<string> header;
	int size = 0;


	std::ifstream f("cna_24March.csv", ios::out | ios::app);
	using namespace aria::csv;
	CsvParser parser(f);
	parser.delimiter(',').quote('\"');

	/*
	 * Get the header of the table. Populate header vector<string> with header string
	 */
	std::string str = "";
	std::getline(f, str);
	istringstream iss(str);
	std::string token;
	while (std::getline(iss, token, ','))
	{
		// process each token
		header.push_back(token);
	}

	/*
	 * Populate the vector<string> based on whether (1) Twitter CSV, (2) TheGuardian/CNA CSV is displaying
	 */
	CsvParser::iterator i(&parser);
	for (i = parser.begin(); i != parser.end(); i++) {
		auto row = i->data();
		if (size == 0) {
			size = int(row->size());
		}
		if (header.size() == 3) {//TheGuardian/CNA has 3 headers

			sharedParsedData.push_back(row[1]);
		}
		else if (header.size() == 5) {//Twitter has 5 headers
			sharedParsedData.push_back(row[1]);

		}
	}
	sentiment sen;
	sentiment pos("positive.txt");
	sentiment neg("negative.txt");

	std::vector<std::string> positive;
	std::vector<std::string> negative;
	std::vector<std::string> strings;
	std::map<std::string, double> senResults;



	for (auto t = sharedParsedData.begin(); t != sharedParsedData.end(); ++t) {
		strings.push_back(*t);
	}

	cout << "What is in strings" << endl;
	for (auto t = strings.begin(); t != strings.end(); ++t) {
		cout << *t << endl;
	}
	cout << "Ends of strings troubleshooting\n\n\n\n" << endl;

	positive = pos.readText();
	negative = neg.readText();
	senResults = sen.checkSentiment(strings, positive, negative);

	for (std::pair<std::string, double> element : senResults) {
		// Accessing KEY from element
		std::string sentiment = element.first;


		// Accessing VALUE from element.
		int value = element.second;

		cout << "Sentiment = " << sentiment << endl;
		cout << "Value = " << value << endl;
	}

}