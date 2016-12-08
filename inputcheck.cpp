#include "inputcheck.h"
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;

inputcheck::inputcheck()
{

}


bool inputcheck::nameCheck(const string &name)
{
    for(size_t i = 0; i < name.length(); i++)
    {
        if (ispunct(name[i]) || isspace(name[0]))
                return false;
    }
    return !(name.find_first_of("0123456789") != string::npos) && name.length() < 100;
}

bool inputcheck::cpuCheck(const string &cpuname)
{

    for(size_t i = 0; i < cpuname.length(); i++)
    {
        if (ispunct(cpuname[i]) || cpuname.empty() || isspace(cpuname[0]))
            return false;
    }
    return cpuname.length() < 100;
}


bool inputcheck::genderCheck(const string &genderstring)
{
    return (genderstring[0] == 'm' || genderstring[0] == 'M' || genderstring[0] == 'f' || genderstring[0] == 'F') && genderstring.length() == 1;
}

bool inputcheck::birthCheck(string birth)
{
    for(size_t i = 0; i < birth.length(); i++)
        if(!isdigit(birth[i]) || ispunct(birth[i]))
            return false;
    int birthint = atoi(birth.c_str());
    return !(birthint < 0 || birthint > 2016);
}


bool inputcheck::deathCheck(string death, string birth)
{
    for(size_t i = 0; i < death.length(); i++)
        if(!isdigit(death[i]) || ispunct(birth[i]))
            return false;
    int birthint = atoi(birth.c_str());
    int deathint = atoi(death.c_str());
    return (deathint == 0 || (deathint <= 2016 && deathint > birthint));
}


bool inputcheck::commaCheck(string word)
{
    return (word.find(',')!=std::string::npos);
}


bool inputcheck::answerCheck(char answer)
{
    return (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N');
}

bool inputcheck::buildyCheck(string buildy)
{
    for(size_t i = 0; i < buildy.length(); i++)
        if(!isdigit(buildy[i]) || ispunct(buildy[i]))
            return false;
    int buildyint = atoi(buildy.c_str());
    return (buildyint <= 2016);
}

bool inputcheck::builtCheck(bool built)
{
    return (built == 1 || built == 0);
}
