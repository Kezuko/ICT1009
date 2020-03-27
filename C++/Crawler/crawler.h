#pragma once
#include "Data.h"
#include <string>
#include <vector>
#define CURL_STATICLIB
#include <iostream>
#include <string>
#include <curl/curl.h>
#include "Data.h"
#include "crawler.h"
#include <boost/lambda/lambda.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <regex> 
#include <math.h>
#include <sstream>


using namespace std;
class crawler
{
protected:
	vector<Data> dataList;
	vector<string> URLs;
	vector<string> URLsToScrape;
	vector<string> URLs_Visited;
	int maxPages= 30;
	int error = 0;
	string baseweb = "https://www.channelnewsasia.com/";

public:
	crawler();
	crawler(int);
	~crawler();
	void setMaxPages(int);
	int getMaxPages();
	vector<string> crawl(string);
	
};

