//#include "csv.h"
#include <iostream>
#include <vector>
#include "parser.h"
using namespace aria::csv;
//int main(){




//    std::ifstream f("D:/Eclipse Workspace/JavaSwingnot7/Grp32/Grp32_code/twitter - Copy 5.csv");
//    CsvParser parser(f);
//    parser.delimiter(',').quote('\"');
//// delimited by ; instead of ,
//// quoted fields use ' instead of "
//// terminated by \0 instead of by \r\n, \n, or \r;
//    std::vector<std::string> usernameCol;
//    std::vector<std::string> tweetCol;
//    std::vector<std::string> retweetCol;
//    std::vector<std::string> favouriteCol;
//    std::vector<std::string> dateCol;
//    for (auto& row : parser) {
////        for (auto& field : row) {
////            std::cout << field << " | ";
////        }
//        usernameCol.push_back(row[0]);
//        tweetCol.push_back(row[1]);
//        retweetCol.push_back(row[2]);
//        favouriteCol.push_back(row[3]);
//        dateCol.push_back(row[4]);
////        std::cout << std::endl;
//    }
//    using namespace std;
//    for(std::string u : usernameCol){
//        cout << "U=" << u << endl;
//    }
//    for(std::string t : tweetCol){
//        cout << "T=" << t << endl;
//    }
//    for(std::string r : retweetCol){
//        cout << "R=" << r << endl;
//    }
//    for(std::string f : favouriteCol){
//        cout << "F=" << f << endl;
//    }
//    for(std::string d : dateCol){
//        cout << "D=" << d << endl;
//    }





////    io::CSVReader<5> in("D:/Eclipse Workspace/JavaSwingnot7/Grp32/Grp32_code/twitter - Copy 5.csv");
////    in.read_header(io::ignore_extra_column, "Username", "Tweet", "Retweet_Count", "Favourite_Count", "Date");

////    using namespace std;
////    std::string username; std::string tweet; std::string retweet; std::string favourite; std::string date;
////    std::vector<std::string> usernameCol;
////    std::vector<std::string> tweetCol;
////    std::vector<std::string> retweetCol;
////    std::vector<std::string> favouriteCol;
////    std::vector<std::string> dateCol;
////    while(in.read_row(username, tweet, retweet, favourite, date)){




////        usernameCol.push_back(username);


////        tweetCol.push_back(tweet);


////        retweetCol.push_back(retweet);


////        favouriteCol.push_back(favourite);


////        dateCol.push_back(date);
////    }

////    for(std::string u: usernameCol){
////        cout << u << endl;
////    }
////    for(std::string u: tweetCol){
////        cout << u << endl;
////    }
////    for(std::string u: retweetCol){
////        cout << u << endl;
////    }
////    for(std::string u: favouriteCol){
////        cout << u << endl;
////    }
////    for(std::string u: dateCol){
////        cout << u << endl;
////    }
//    return 0;
//}
