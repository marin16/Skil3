#include "inputcheck.h"
#include <string>

using namespace std;

inputcheck::inputcheck()
{

}

/*inputcheck::inputcheck(string name)
{
    _name = name;
}

ostream& operator << (ostream& out, inputcheck& input)
{
    out << input._name;

 return out;
}*/

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

/*
 * Check if input is under 0 or over 2016
 */
bool inputcheck::birthCheck(int birth)
{
    if( birth < 0 || birth > 2016 )
        return false;
    else
        return true;
}

/*
 * Checks if dod is over 2016 or under 0
 */
bool inputcheck::deathCheck(int death)
{
    if(death == 0 || (death <= 2016 && death > 0))
        return true;
    else
        return false;
}
