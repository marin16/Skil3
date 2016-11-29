#ifndef INPUTCHECK_H
#define INPUTCHECK_H
#include <string>

using namespace std;

class inputcheck
{
public:
    inputcheck();
    inputcheck(string name);

    bool name_check(string name);
    friend ostream& operator << (ostream& out, inputcheck& input);

private:
    string _name;


};

#endif // INPUTCHECK_H
