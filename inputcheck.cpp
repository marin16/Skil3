#include "inputcheck.h"
#include <string>
#include <iostream>

using namespace std;

inputcheck::inputcheck()
{

}


bool inputcheck::nameCheck(const string &name)
{
    return !(name.find_first_of("0123456789") != string::npos) && name.length() < 100;
}


bool inputcheck::genderCheck(char gender)
{
    if(gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
        return true;
    else
        return false;
}

bool inputcheck::birthCheck(int& birth)
{
    if(birth < 0 || birth > 2016 || birth == isdigit(birth))
        return false;
    else
        return true;
}


bool inputcheck::deathCheck(int death, int& birth)
{
    if(death == 0 || (death <= 2016 && death > birth))
        return true;
    else if(death == isdigit(death) || (death != 0 && (death < birth || death > 2016)))
        return false;
}


bool inputcheck::commaCheck(string word)
{
    if(word.find(',')!=std::string::npos)
        return true;
    else
        return false;
}


bool inputcheck::answerCheck(char answer)
{
    if(answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
        return true;
    else
        return false;
}
