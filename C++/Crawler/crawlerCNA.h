#pragma once
#include "crawler.h"
class crawlerCNA :
	public crawler
{
public:
	crawlerCNA();
	crawlerCNA(int);
	~crawlerCNA();
	void crawlFirst(vector<string>);
	void crawl_URL_For_Scrap(vector<string>);
	int scrap(string);
	int mainCrawl();
	string santizeTitle(string);
};

