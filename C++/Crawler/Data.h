#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
class Data
{

protected:
	string Article_Category= "";
	string Article_Title= "";
	string Date_Published= "";


public:
	Data();
	void setArticle_cat(string);
	void setArticle_Title(string);
	void setDate_published(string);
	string getArticle_cat();
	string getArticle_Title();
	string getDate_published();

};

