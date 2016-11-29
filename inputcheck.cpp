#include "inputcheck.h"
#include <string>

using namespace std;

inputcheck::inputcheck()
{
    string name = _name;
}

/*operator << (ostream& out, const inputcheck& i)
{
    out << i.name;

 return out;
}*/

bool inputcheck::name_check(string _name)
{
    ///cout << "Enter string: ";
    ///cin >> _name;

    for (size_t n = 0; n < _name.length(); n++)
    {
        if (isdigit( _name[ n ] ))
        {
            return false;
        }
    }

return true;
}

