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

