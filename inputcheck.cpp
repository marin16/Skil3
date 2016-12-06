#include "inputcheck.h"
#include <string>
#include <iostream>

using namespace std;

inputcheck::inputcheck()
{

}


bool inputcheck::nameCheck(const string &name)
{
    for(size_t i = 0; i < name.length(); i++)
    {
        if (ispunct(name[i]))
                return false;
    }
    return !(name.find_first_of("0123456789") != string::npos) && name.length() < 100;
}


bool inputcheck::genderCheck(char gender)
{
    if(gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
        return true;
    else
        return false;
}

bool inputcheck::birthCheck(string birth)
{
    for(size_t i = 0; i < birth.length(); i++)
        if(!isdigit(birth[i]) || ispunct(birth[i]))
            return false;
    int birthint = atoi(birth.c_str());
    if(birthint < 0 || birthint > 2016)
        return false;
    else
        return true;
}


bool inputcheck::deathCheck(string death, string birth)
{
    for(size_t i = 0; i < death.length(); i++)
        if(!isdigit(death[i]) || ispunct(birth[i]))
            return false;
    int birthint = atoi(birth.c_str());
    int deathint = atoi(death.c_str());
    if(deathint == 0 || (deathint <= 2016 && deathint > birthint))
        return true;
    else if((deathint != 0 && (deathint < birthint || deathint > 2016)))
        return false;
	else
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

bool inputcheck::builtyCheck(string builty)
{
    for(size_t i = 0; i < builty.length(); i++)
        if(!isdigit(builty[i]) || ispunct(builty[i]))
            return false;
    int builtyint = atoi(builty.c_str());
    if(builtyint > 2016)
        return false;
    else
        return true;
}

bool inputcheck::builtCheck(bool built)
{
    if(built == 1 || built == 0)
        return true;
    else
        return false;
}
