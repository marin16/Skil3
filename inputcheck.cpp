#include "inputcheck.h"
#include <string>

using namespace std;

inputcheck::inputcheck()
{

}

inputcheck::inputcheck(string name)
{
    _name = name;
}

ostream& operator << (ostream& out, inputcheck& input)
{
    out << input._name;

 return out;
}

///Checks if name is legal (does not include numbers)
bool inputcheck::name_check(string name)
{

    for (size_t n = 0; n < name.length(); n++)
    {
        if (isdigit( name[ n ] ))
        {
            return false;
        }
    }

    return true;
}

bool inputcheck::gender_check(char gender)
{
    if(gender != 'm' || gender != 'M' || gender != 'f' || gender != 'F')
        return false;
    else
        return true;
}

bool inputcheck::komma_check(string word)
{
    if(word.find(',')!=std::string::npos)
        {
           /// cout << "Thad er komma (,) i ordinu, reyndu aftur";
            return true;
        }
        else
        {
           /// cout << "Thad er ekki komma (,) i ordinu";
            return false;
        }
}

bool inputcheck::birth_check(int birth)
{
    if(birth<0||birth>2016)
        return false;
    else
        return true;
}

bool inputcheck::death_check(int death)
{
    if(death == 0 || (death>=birth && death <=2016))
        return true;
    else
        return false;
}
