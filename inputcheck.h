#ifndef INPUTCHECK_H
#define INPUTCHECK_H
#include <string>

using namespace std;

class inputcheck
{
public:
    inputcheck();
    bool nameCheck(const string &name);
    bool genderCheck(char gender);
    bool commaCheck(string word);
    bool answerCheck(char answer);
private:
    string _name;
    char _gender;
    string _word;
    int birth;
    int death;

};

#endif // INPUTCHECK_H
