#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <algorithm>
#include <map>

class sentiment{
    private:
        // std::vector<std::string> postive;
        // std::vector<std::string> negative;
        std::vector<std::string> temp;
        std::map <std::string, double> result;
        std::string fileName;
        std::string line;
        double posCount=0;
        double negCount=0;
        double totalCount=0;
        double posPerc=0;
        double negPerc=0;

    public:
        sentiment();
        sentiment(std::string);
        std::vector<std::string> readText();
        std::string getFileName();
        std::map <std::string, double> checkSentiment(std::vector<std::string>,std::vector<std::string>,std::vector<std::string>);
        std::vector<std::string> getReadTextArr();
};

sentiment::sentiment(){

}

sentiment::sentiment(std::string fileName){
    this->fileName = fileName;
}

std::string sentiment::getFileName(){
    return fileName;
}

// std::vector<std::string> sentiment::getReadTextArr(){
//     return temp;
// }

std::vector<std::string> sentiment::readText(){
    std::string file = sentiment::getFileName();
    std::ifstream File(file.c_str());
    if (File.is_open()){
        while(getline(File,line)){
            temp.push_back(line);
        }

    File.close();
    }else{
        std::cout << "Unable to open file";
    }
    return temp;
}

std::vector<std::string> sentiment::getReadTextArr(){
    return temp;
}

std::map <std::string, double> sentiment::checkSentiment(std::vector<std::string> s,std::vector<std::string> pos,std::vector<std::string> neg){
    
    for(int x=0;x<s.size();x++){
        for (int i = 0, len = s[x].size(); i < len; i++){
            if (ispunct(s[x][i])){
                s[x].erase(i--, 1);
                len = s[x].size();
            }
            
            if (s[x][i] >= 'A' && s[x][i] <= 'Z'){  //checking for uppercase characters
                s[x][i]=tolower(s[x][i]);
            }

            if(!((s[x][i] >= 'a' && s[x][i] <= 'z') || (s[x][i] >= 'A' && s[x][i] <= 'Z') || (s[x][i] == '\0') || (s[x][i] == ' '))){
                s[x].erase(i--,1);
                len=s[x].size();      
            }
        }
        // std::cout << s[x] << std::endl;
    }
    
    for(int i =0; i<s.size();i++){

        std::istringstream iss(s[i]); 
        
        do { 
            std::string subs; 
    
            // Get the word from the istringstream 
            iss >> subs;

            for(int i=0;i<pos.size();i++){
                if(subs.compare(pos[i])==0){
                    posCount+=1;
                    // std::cout << subs << std::endl;
                }
            }

            for(int i=0;i<neg.size();i++){
                if(subs.compare(neg[i])==0){
                    negCount+=1;
                    // std::cout << subs << std::endl;
                }
            }

            totalCount+=1;
        }while(iss);
    }

    posPerc = (posCount/totalCount) * 100;
    negPerc = 100 - posPerc;
    // std::cout << posCount << std::endl;
    // std::cout << negCount << std::endl;
    result["Positive"] = posCount;
    result["Negative"] = negCount;
    result["Positive percentage"] = posPerc;
    result["Negative percentage"] = negPerc;

    return result;
    // return 0;
}



int main(){
    std::string s1 = "This 'is' a! good te@stin3g, and horrible string.";
    std::string s2 = "This 'is' shit lousy very good excellent.";
    
    sentiment sen;
    sentiment pos("positive.txt");
    sentiment neg("negative.txt");

    std::vector<std::string> positive;
    std::vector<std::string> negative;
    std::vector<std::string> strings;
    std::map<std::string, double> senResults;

    strings.push_back(s1);
    strings.push_back(s2);
    
    positive = pos.readText();
    negative = neg.readText();
    senResults = sen.checkSentiment(strings,positive,negative);

    // // senResults

    // for( auto const& [key, val] : senResults ){
    //     std::cout << key << ':' << val << std::endl ;
    // }
    for (std::pair<std::string, double> element : senResults) {
		// Accessing KEY from element
		std::string sentiment = element.first;
		// Accessing VALUE from element.
		double value = element.second;
		std::cout << sentiment << " :: " << value << std::endl;
	}
    return 0;
}