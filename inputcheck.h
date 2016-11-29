#ifndef INPUTCHECK_H
#define INPUTCHECK_H
#include <string>

using namespace std;

class inputcheck
{
public:
    inputcheck();

    bool name_check(string _name);
    friend ostream& operator << (ostream& out, const inputcheck& i);

private:
    string _name;


};

#endif // INPUTCHECK_H
