#include "computer.h"
#include "utilities.h"

#include <string>

using namespace std;

Computer::Computer()
{

}

Computer::Computer(string name, int buildy, string type, bool built)
{
    _name = name;
    _buildy = buildy;
    _type = type;
    _built = built;
}

bool Computer::contains(string searchTerm)
{
    string searchTermLower = utils::stringToLower(searchTerm);

    string nameLower = utils::stringToLower(_name);
    if (nameLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    string typeLower = utils::stringToLower(_type);
    if (typeLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    string buildyString = utils::intToString(_buildy);

    if (buildyString.find(searchTerm) != string::npos)
    {
        return true;
    }

    if (searchTermLower == "built" && _built == true)
    {
        return true;
    }

    return false;
}
