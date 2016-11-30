#include "inputcheck.h"
#include <string>

using namespace std;

inputcheck::inputcheck()
{

}

/*
 * Checks if name includes numbers
 */
bool inputcheck::nameCheck(const string &name)
{
    return !(name.find_first_of("0123456789") != string::npos);
}

/*
 * Checks if input is F, M, f or m
 */
bool inputcheck::genderCheck(char gender)
{
    if(gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
        return true;
    else
        return false;
}

/*
 * Check if there is a comma in the input
 */
bool inputcheck::commaCheck(string word)
{
    if(word.find(',')!=std::string::npos)
        return true;
    else
        return false;
}

