#pragma once
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <vector>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include "../utils/project_utils.h"

using namespace rapidjson;
using namespace std;

// Class is used to get the word count of all words in the platform (Twitter, News, etc).
class WordCountAnalyzer { 
    public: 
    // Apply stopword to get rid of the most commonly used words which will
    // not be useful for our analysis
    // @return vector<string>: vector of all stop words
    static vector<string> getStopWords() {
        Document base;
        // Read from the pre-generated stopwords json file
        ifstream ifs("data/stopwords-en.json");
        vector<string> stopwords;
        bool exists = true;
        // Check whether the file can be opened for reading
        if(!ifs.is_open()) {
            exists = false;
            std::cerr << "Could not open file for reading\n";
            return stopwords;
        }
        IStreamWrapper isw {ifs};
        base.ParseStream(isw);
        // Loop through all the brands that have been retrieved
        for (auto const &stopword: base.GetArray()) {
            string stopword_text = stopword.GetString();
            stopwords.push_back(stopword_text);
        }
        // Return the list of stopwords as a vector
        return stopwords;
    }
    template<class T>
    // Used to analyze the word count
    // @param 
    // - vector<T*> 
    // - T::*fn - Address of the method that will be invoked by each T* in vector<T*>. The method must be 
    // a method in the T class and return a string data type
    //
    // @return
    // map<string, int> - Word / Count key pair
    static map<string, int> analyzeWordCount(vector<T*> item_list, string (T::*fn)() ) {
        try {
            // Get the list of stop words
            vector<string> stopwords = WordCountAnalyzer::getStopWords();
            map<string, int> word_count_map = {};
            // Loop through each T in vector<T*>
            for(T* item: item_list) {
                string word = (item->*fn)();
                stringstream ss(word);
                string tok;
                // Split by the space and loop through each index separated by the space
                while(getline(ss, tok, ' ')) {
                    // Convert to lowercase to ensure consistency in the result
                    tok = convertToLowercase(tok);
                    vector<string>::iterator stopwords_it = std::find(stopwords.begin(), stopwords.end(), tok);
                    // Create a new key in the map if the word does not exist in map.
                    // Ignore if the word is a stopword
                    if(stopwords_it == stopwords.end()) {
                        if(word_count_map.find(tok) == word_count_map.end()) {
                            word_count_map[tok] = 1;
                        } else {
                            word_count_map[tok]++;
                        }
                    }
                }
            }
            return word_count_map;


        } catch(exception e) {
            cout << "Error in analyzeSentiment()";
            cout << e.what();
            map<string, int> word_count_map = {};
            return word_count_map;

        }
    }
};