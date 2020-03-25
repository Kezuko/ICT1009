#include <string> 
using namespace std;

string convertToLowercase(string tok) {
    // Convert string to lowercase character by character
    for (int i=0; i<tok.length(); i++) {
        tok[i] = tolower(tok[i]);
    }
    return tok;
};