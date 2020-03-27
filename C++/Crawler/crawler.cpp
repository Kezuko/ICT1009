#include "crawler.h"
#include <string>
using namespace std;

crawler::crawler() {

}

crawler::crawler(int maxPage) {
	this->maxPages = maxPage;
}
crawler::~crawler() {

}

void crawler::setMaxPages(int key) {
    this->maxPages = key;
}


int crawler::getMaxPages() {
	return this->maxPages;
}


static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{

    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

vector<string> crawler::crawl(string url) {
    this->error = 0;
    boost::erase_all(url, "\"");
    CURL* curl;
    CURLcode res;
    string readBuffer;
    //Data obj = Data();
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    else
        this->error = -1;

    vector<string> htmlLines;
    //vector<string> URLs;
    boost::split(htmlLines, readBuffer, boost::is_any_of(">"));
    cout << "* size of the vector before erase: " << htmlLines.size() << endl;
    std::size_t found;
    std::size_t found2;
    std::size_t found3;
    std::size_t found4;
    std::size_t found5;
    //sanitize to get the values that i want only.
    vector<string>::iterator it = htmlLines.begin();
    while (it != htmlLines.end())
    {
        found = (*it).find("href");
        if (found == std::string::npos) {
            it = htmlLines.erase(it);
        }
        else {
            found2 = (*it).find("<a");
            if (found2 == std::string::npos) {
                it = htmlLines.erase(it);
            }
            else {
                found3 = (*it).find("script");
                if (found3 != std::string::npos) {
                    it = htmlLines.erase(it);
                }
                else {
                    found4 = (*it).find("#");
                    if (found4 != std::string::npos) {
                        it = htmlLines.erase(it);
                    }
                    else {
                        found5 = (*it).find("?");
                        if (found5 != std::string::npos)
                            it = htmlLines.erase(it);
                        else
                            ++it;
                    }



                }
            }
        }
    }
    return htmlLines;
}




