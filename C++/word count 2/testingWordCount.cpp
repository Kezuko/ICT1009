#include <iostream>
#include <fstream>
#include <string>

const int MAX = 10000;
string words[MAX];
int instances[MAX];
int count = 0;

int insert(string input)
{
	for(int i = 0; i < count; i++)
		if(input == words[i]){
			instances[i]++;
			return;
		}
	if(count < MAX) {
		words[count] = input;
		instances[count] = 1;
		count++;
	}
	else
		cerr << "Too many unique words in input file."
}

int findTop(string &word) {

  	int topCount = instances[0];
  	int topIndex = 0;
	int count = 0;
	
	for(int = 1 ; i < count; i++)
		if (instances[i] > topCount){
			topCount = instances[i];
			topIndex = i;
		}
	instances[topIndex] = 0;
	word = words[topIndex];
	
	return topCount;
}


int main(int argc, char** argv) {
	string word;
	ifstream input("PROS.txt");
	while (input >> word)
		cout << word << endl;
		
	int topCount = 0;
	for(int i = 0; i < 10; i++)
		cout << findTop(wc) << " " << " " wc << endl
		
		return 0;
}
