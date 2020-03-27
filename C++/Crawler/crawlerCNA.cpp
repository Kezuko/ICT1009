#include "crawlerCNA.h"


// constructors and desctructors 
crawlerCNA::crawlerCNA() {

}
crawlerCNA::crawlerCNA(int maxPage) {
    this->maxPages = maxPage;
}
crawlerCNA::~crawlerCNA() {

}


static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{

    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int crawlerCNA::mainCrawl() {
    vector<string> FirsthtmlData;
    // first run.
    FirsthtmlData = this->crawl("https://www.channelnewsasia.com/news/international");
    if (this->error == -1) {
        return -1;
    }
       
    this->crawlFirst(FirsthtmlData);

    //clear elements inside the vector 
    FirsthtmlData.clear();

    // counter for how many times i will loop inside the websites 
    int counter = 0;

    // iterator to loop through the vector to find the URL's to scrap the data

    vector<string>::iterator it;
    for (it = URLs.begin(); it != URLs.end(); it++)
    {

        if (counter <= ceil(maxPages/100) +1) {
            FirsthtmlData = this->crawl(*it);
            if (this->error == -1) {
                return -1;
            }
            this->URLs_Visited.push_back(*it);
            this->crawl_URL_For_Scrap(FirsthtmlData);
            FirsthtmlData.clear();
            counter++;
        }
        else
            break;

    }
    // scrapping
    vector<string>::iterator it2;
    int visited = 0;
    int NumVisited = 0;
    int error = 0;
    for (it2 = URLsToScrape.begin(); it2 != URLsToScrape.end(); it2++)
    {
        if (NumVisited < this->maxPages) {
            visited = 0;
            for (int i = 0; i < URLs_Visited.size(); i++) {
                if (URLs_Visited[i] == *it2) {
                    visited = 1;
                    break;
                }

            }
            if (visited == 0) {
                error = this->scrap(*it2);
                URLs_Visited.push_back(*it2);
                if(error == 0)
                    NumVisited++;
            }
        }
        else
            break;




    }
    cout << "Number of pages Visited = " << NumVisited << endl;

    
    // saving to file probably comes here. 
    ofstream myfile;
    myfile.open("exampleTESTING.csv");
    int count = 1;
    for (const auto& value : this->dataList) {
        Data obj = value;
        myfile << count << "," << obj.getArticle_cat() << "," << obj.getArticle_Title() << "," << obj.getDate_published() << endl;
        count++;
    }


    myfile.close();
    return 0;
}

string crawlerCNA::santizeTitle(string s) {
    int flag = 0;
    while (flag == 0) {
        auto found_amber = s.find('&');
        if (found_amber != std::string::npos) {
            auto found_semiCol = s.find(';', found_amber + 1);
            if (found_semiCol != std::string::npos) {
                s.erase(found_amber, (found_semiCol - found_amber) + 1);
            }
        }
        else
            flag = 1;
    }

    flag = 0;
    while (flag == 0) {
        auto found_Comma = s.find(',');
        if (found_Comma != std::string::npos) {
            s.replace(found_Comma, 1, "{");
        }
        else
            flag = 1;
    }
    flag = 0;
    stringstream result;
    const regex rgx("([^a-z,A-Z,0-9-$:.{()?\! ])");
    regex_replace(std::ostream_iterator<char>(result), s.begin(), s.end(), rgx, "");
    return result.str();
}

// just to get website URL's
void crawlerCNA::crawlFirst(vector<string> htmlLines) {
    std::size_t foundhttp;
    for (const auto& value : htmlLines) {
        const string s = value;
        const regex rgx("(\".*?\")");
        smatch match;

        if (std::regex_search(s.begin(), s.end(), match, rgx)) {
            //std::cout << "match: " << match.str(1) << '\n';
            foundhttp = match.str(1).find("http");
            if (foundhttp != std::string::npos) {
                URLs.push_back(match.str(1));
            }
        }
    }
}


// to find URL's that are articles 
void crawlerCNA::crawl_URL_For_Scrap(vector<string> htmlLines) {
    std::size_t foundhttp;
    std::size_t foundslash;
    for (const auto& value : htmlLines) {
        const string s = value;
        const regex rgx("(\".*?\")");
        smatch match;

        if (std::regex_search(s.begin(), s.end(), match, rgx)) {
            foundslash = match.str(1).find("\/");
            if (foundslash != std::string::npos) {
                foundhttp = match.str(1).find("http");
                if (foundhttp == std::string::npos) {
                    URLsToScrape.push_back(match.str(1));
                    //std::cout << "match: " << match.str(1) << '\n';
                }

            }

        }

    }
}


int crawlerCNA::scrap(string url_Scrap) {

    boost::erase_all(url_Scrap, "\"");
    cout << url_Scrap << endl;
    url_Scrap = this->baseweb + url_Scrap;
    if (url_Scrap.find("video") == std::string::npos) {


        CURL* curlScrap; CURLcode resScrap; string readBufferScrap;
        vector<string> htmlScrap; vector<string> htmlScrap2;
        std::size_t found;
        std::size_t found2;
        Data obj = Data();
        curlScrap = curl_easy_init();
        if (curlScrap) {
            curl_easy_setopt(curlScrap, CURLOPT_URL, url_Scrap.c_str());
            curl_easy_setopt(curlScrap, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curlScrap, CURLOPT_WRITEDATA, &readBufferScrap);
            resScrap = curl_easy_perform(curlScrap);
            curl_easy_cleanup(curlScrap);
        }
        else
            return -1;





        boost::split(htmlScrap, readBufferScrap, boost::is_any_of(">"));
        //cout << "* size of the vector 2 before erase: " << htmlScrap.size() << endl;

        htmlScrap2 = htmlScrap;
        //cout << "* size of the vector 2 before erase: " << htmlScrap2.size() << endl;
        //sanitize to get the values that i want only.

        vector<string>::iterator it = htmlScrap.begin();
        while (it != htmlScrap.end())
        {
            found = (*it).find("<time");
            if (found == std::string::npos) {
                it = htmlScrap.erase(it);
            }
            else {
                ++it;
                ++it;
            }
        }
        //cout << "* size of the vector 1 after erase: " << htmlScrap.size() << endl;

        vector<string>::iterator it2 = htmlScrap2.begin();
        while (it2 != htmlScrap2.end())
        {
            found2 = (*it2).find("<h1");
            if (found2 == std::string::npos) {
                it2 = htmlScrap2.erase(it2);
            }
            else {
                ++it2;
                ++it2;

            }
        }

        //cout << "* size of the vector 2 after erase: " << htmlScrap2.size() << endl;

        // finding for title
        if (htmlScrap2.size() != 0 && htmlScrap.size() != 0) {
            string temp_title = htmlScrap2[1];
            found = temp_title.find("</");
            string Title = temp_title.substr(0, found);

            // finding for date
            string temp_date = htmlScrap[1];
            found = temp_date.find("</");
            string Date = temp_date.substr(0, found);
            // finding for category of article
            vector<string> url_Split;
            boost::split(url_Split, url_Scrap, boost::is_any_of("/"));
            string Category = url_Split[5];

            string New_Title;
            New_Title = this->santizeTitle(Title);
            //cout << Category << endl;
            //cout << New_Title << endl;
            //cout << Date << endl;

            obj.setArticle_Title(New_Title);
            obj.setDate_published(Date);
            obj.setArticle_cat(Category);

            dataList.push_back(obj);
        }
        else
            return -1;

    }

    return 0;

}