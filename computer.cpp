#include "computer.h"

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
