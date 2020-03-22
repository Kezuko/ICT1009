#ifndef CRAWL_H
#define CRAWL_H
#include <string>
using namespace std;

class crawl{
private:
    string csvfilepath;
    int pagesToCrawl;
    string crawlSource;
    string keyword1;
    string keyword2;
public:
    crawl(string, int, string, string, string);
    int crawlTwitter();
    int crawlTheGuardian();
    int crawlCNA();
};

#endif // CRAWL_H
