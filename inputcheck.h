#ifndef INPUTCHECK_H
#define INPUTCHECK_H
#include <string>

using namespace std;

class inputcheck
{
public:
    inputcheck();
    bool nameCheck(const string &name);
    bool cpuCheck(const string &cpuname);
    bool genderCheck(const string &genderstring);
    bool birthCheck(string birth);
    bool deathCheck(string death, string birth);
    bool commaCheck(string word);
    bool answerCheck(char answer);
    bool buildyCheck(string buildy);
    bool builtCheck(bool built);
};

#endif // INPUTCHECK_H
