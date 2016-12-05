#include "computer.h"

#include <string>

using namespace std;

Computer::Computer()
{

}

Computer::Computer(string name, int builty, string type, bool built)
{
    _name = name;
    _builty = builty;
    _type = type;
    _built = built;
}
