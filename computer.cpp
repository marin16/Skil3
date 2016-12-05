#include "computer.h"

#include <string>

using namespace std;

Computer::Computer()
{

}

Computer::Computer(int id, string name, int builty, string type, bool built)
{
    _name = name;
    _bulty = builty;
    _type = type;
    _built = built;
}
