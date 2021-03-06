// strngbad.cpp -- StringBad class methods
#include <cstring>                    // string.h for some
#include "strngbad.h"
using std::cout;

// initializing static class member
int StringBad::num_strings = 0;

// class methods

// construct StringBad from C string
StringBad::StringBad(const char * s)
{
    len = std::strlen(s);            
    str = new char[len + 1];          
    std::strcpy(str, s);              
    num_strings++;                   
    cout << num_strings << ": \"" << str
         << "\" object created\n";   
}

StringBad::StringBad(const StringBad & st)   //copy constructor
{
    len = st.len;             // set size
    str = new char[len + 1];          // allot storage   (+1是包含字串的作後一個都是NULL)
    std::strcpy(str, st.str);              // initialize pointer
    num_strings++;                    // set object count
    cout << num_strings << ": \"" << str
         << "\" object created\n";    // For Your Information
}

StringBad::StringBad()                // default constructor
{
    len = 4;                         //!!!  
    str = new char[len];
    std::strcpy(str, "C++");          // default string
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\" default object created\n";  // FYI
}

StringBad::~StringBad()               // necessary destructor
{
    cout << "\"" << str << "\" object deleted, ";    // FYI
    --num_strings;                    // required
    cout << num_strings << " left\n"; // FYI
    delete [] str;                    // required
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os; 
}
