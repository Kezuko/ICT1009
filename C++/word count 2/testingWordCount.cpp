#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <iostream>

class wordCount{
	
	friend std::ostream& operator<<(std::ostream&, wordCount&);

	private:
		std::map <std::string, int> wordMap;
		unsigned long int countWordsInFile;
		unsigned long int numOfSent;
		unsigned long int avgNumOfWordsPerSent;

	public:
		wordCount();
		bool buildMap();
		void writeIndex();
		void AddWordtoMap(std::string);
		std::map <std::string, int> getWordMap();
		unsigned long int getCountWordsInFile();
		unsigned long int getNumOfSent();
		unsigned long int getAvgNumOfWordsPerSent();
		unsigned long int setAvgNumOfWordsPerSent(unsigned long int);
		unsigned int avgWordLength();
};

wordCount::wordCount(){
	countWordsInFile = 0;
	numOfSent = 0;
	avgNumOfWordsPerSent = 0;
}

unsigned long int wordCount::getCountWordsInFile(){
	return countWordsInFile;
}

unsigned long int wordCount::getNumOfSent(){
	return numOfSent;
}

unsigned long int wordCount::getAvgNumOfWordsPerSent(){
	return avgNumOfWordsPerSent;
}

unsigned long int wordCount::setAvgNumOfWordsPerSent(unsigned long int avgNumOfWordsPerSent){
	this->avgNumOfWordsPerSent = avgNumOfWordsPerSent;
}

std::map <std::string, int> wordCount::getWordMap(){
	return wordMap;
}

bool wordCount::buildMap(){
	const std::string filename ="PROS.txt";

	std::ifstream inputFile(filename.c_str());
	std::string line;

	if(inputFile.is_open()){
		std::cout<<"File opened Successfully...\n";

		while(getline(inputFile, line)){
			numOfSent++;
			std::size_t prev =0, pos;

				while((pos =  line.find_first_of("~`=!@#$%^&*)/\?-_|[,. }] (_-+{;':""></", prev)) != std::string::npos){
					if(pos>prev){
						AddWordtoMap(line.substr(prev, pos-prev));
					}
					prev= pos+1;
				}
				
				if(prev< line.length()){
					AddWordtoMap(line.substr(prev, std::string::npos));
				}
			}

		inputFile.close();

	}else{
		std::cout<<"\n-Unable to open file-"<<filename<<"\n"<<std::endl;
		return false;
	}

	return true;
}

void wordCount::AddWordtoMap(std:: string str){
	std::map<std::string, int> ::iterator it = wordMap.find(str);

	if(it!=wordMap.end()){
		it->second = it->second + 1;
	}else{
		wordMap.insert(std::make_pair(str, 1));
	}
	
	//increment word count
	countWordsInFile++;

}

void wordCount::writeIndex(){
	for(std::map<std::string, int> ::iterator itr = wordMap.begin(); itr!=wordMap.end(); ++itr){
		std::cout<<"\n  "<< std::setw(30) <<itr->first<< std::setw(10)<<itr->second;
	}	
}

unsigned int wordCount::avgWordLength(){
	unsigned int calculatelength = 0;
	for(std::map<std::string, int> ::iterator itr = wordMap.begin(); itr!=wordMap.end(); ++itr){
		calculatelength +=  (itr->first).length();
	}	

	if(calculatelength){
		return calculatelength/wordMap.size();
	}else{
		return 0;
	}	
}

std::ostream& operator <<(std::ostream &out, wordCount& wc){
		out<<"The file has "<< wc.getWordMap().size() << " words ";
		
		wc.writeIndex();

		out<<"\n\n Average Word Length is : " << wc.avgWordLength();
		out<<"\n Total Number of Words in file : " << wc.getCountWordsInFile();
		out<<"\n Total Number of Sentences in file : "<<wc.getNumOfSent();
		
		wc.setAvgNumOfWordsPerSent(wc.getCountWordsInFile()/wc.getNumOfSent());
		
		out<<"\n Average Number of Words in one sentence : "<< wc.getAvgNumOfWordsPerSent();

    return out;
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
	wordCount wc;
	if (wc.buildMap()){
		std::cout << wc;
	}
  
  int topCount = 0;
  for(int i = 0; i < 5; i++)
    cout << findTop(wc) << " " << " " wc << endl
  
	return 0;
}
