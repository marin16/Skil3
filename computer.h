#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, int builty, string type, bool built);
    string getName() const
    {
        return _name;
    }
    int getBuilty() const
    {
        return _builty;
    }
    string getType() const
    {
        return _type;
    }
    bool getBuilt() const
    {
        return _built;
    }
private:
    string _name;
    int _builty;
    string _type;
    bool _built;
};

#endif // COMPUTER_H
