#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
 
using namespace std;  
 
template <class T>
struct less_second : std::binary_function<T,T,bool>  
{  
    inline bool operator()( const T& lhs, const T& rhs )  
    {  
        return lhs.second.value < rhs.second.value;  
    }  
};  
 
class WordCounter  
{  
public:  
    int value;  
    WordCounter() : value( 0 ) {}  
 
    void operator++ (int) { value++; }  
};  
 
ostream& operator<<(ostream& st, WordCounter& wc )  
{  
    return st << wc.value;  
}  
 
// Remove unwanted characters from a string  
bool filter(char c)  
{  
    return isalpha( c ) == 0;  
}  
 
const string path = "PROS.txt";  
 
int main()  
{  
    typedef std::pair< string, WordCounter > word_mapping;  
 
    map<string, WordCounter> counter;  
 
    ifstream input;  
    input.open( path.c_str() );  
 
    if ( !input )  
    {  
        cout << "Error in opening file\n";  
        return 0;  
    }  
 
    string tok;       
 
    while ( true )  
    {  
        input >> tok;  
 
        // Remove ?, !, , characters etc from string  
        tok.resize( remove_if( tok.begin(), tok.end(), filter) - tok.begin() );  
 
        if ( input )  
        {  
            counter[ tok ]++;  
        }  
        else break;       
    }  
 
    map< string, WordCounter,less<string> >::iterator it = counter.begin();  
 
    for ( ; it != counter.end(); it++ )  
    {  
        cout << std::setw (15)   
             << (*it).first              
             << "\t" 
             << (*it).second  
             << endl;  
    }  
 
    // And then sort and display the result:
    std::vector< word_mapping > result( counter.begin(), counter.end() );         
    std::sort( result.begin(), result.end(), less_second<word_mapping>() );    
 
    for ( std::vector< word_mapping >::const_iterator mit  = result.begin();  
          mit != result.end();  
          mit++ )  
    {  
        cout << std::setw (15)   
             << (*mit).first              
             << "\t" 
             << (*mit).second.value 
             << endl;  
    }  
 
 
    return 0;  
}  
