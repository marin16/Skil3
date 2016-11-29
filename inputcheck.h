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
    bool gender_check(char gender);
    bool komma_check(string word);
    bool birth_check(int birth);
    bool death_check(int death);
    friend ostream& operator << (ostream& out, inputcheck& input);

private:
    string _name;
    char _gender;
    string _word;
    int birth;
    int death;

};

#endif // INPUTCHECK_H
