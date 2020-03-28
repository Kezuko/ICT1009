#include <iostream>
#include <fstream>
#include <string>
#define MAXNUM 10000
//const int MAXNUM = 10000;
//string words[MAXNUM];
//int instances[MAXNUM];
//int count = 0;

using namespace std;
class WordCount {
private:
	int count = 0;
	string words[MAXNUM];
	int instances[MAXNUM];
public:
	int insert(string input)
	{
		
		for (int i = 0; i < count; i++)
			if (input == words[i]) {
				instances[i]++;
				return 0;
			}
		if (count < MAXNUM) {
			words[count] = input;
			instances[count] = 1;
			count++;
		}
		else
			cerr << "Too many unique words in input file.";
	}

	int findTop(string& word) {
		
		int topCount = instances[0];
		int topIndex = 0;

		for (int i = 1; i < count; i++)
			if (instances[i] > topCount) {
				topCount = instances[i];
				topIndex = i;
			}
		instances[topIndex] = 0;
		word = words[topIndex];

		return topCount;
	}
};



int main(int argc, char** argv) {
	string word;
	ifstream input("sentiment.txt");
	WordCount wc;

	while (input >> word)
		wc.insert(word);

	int topCount = 0;
	for (int i = 0; i < 10; i++)
		cout << wc.findTop(word) << " " << word << endl;

	return 0;
}
