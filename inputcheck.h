#ifndef INPUTCHECK_H
#define INPUTCHECK_H
#include <string>
#include <vector>
#include "scientist.h"
#include "computer.h"

using namespace std;

class inputcheck
{
public:
    inputcheck();
    /*
     * nameCheck: Used to check if a name is acceptable.
     * params: const string &name (name to be checked)
     * returns: true if only letters and shorter than 100 letters.
     */
    bool nameCheck(const string &name);
    /*
     * cpuCheck: Used to check if computer's name is acceptable.
     * params: Const string &cpuname (name of computer to be checked)
     * returns: False if space or dot appears, name longer than 100 or input is empty
     */
    bool cpuCheck(const string &cpuname);
    /*
     * genderCheck: Check if gender input is acceptable
     * params: const string &genderstring (String for gender)
     * returns: true if string length is 1 and string = "f"||"F"||"m"||"M"
     */
    bool genderCheck(const string &genderstring);
    /*
     * birthCheck: Check if date of birth is acceptable
     * params: string birth (scientist's year of birth)
     * returns: true if 0<birth<2016 and contains only digits
     */
    bool birthCheck(string birth);
    /*
     * deathCheck: Check if date of death is acceptable
     * params: string death and string birth (date of birth and death)
     * returns: returns true if birth<death<2016 and contains only digits
     */
    bool deathCheck(string death, string birth);
    /*
     * commaCheck: Check if a comma is in a input
     * params: string word (word to check for comma)
     * returns: false if word contains ','
     */
    bool commaCheck(string word);
    /*
     * answerCheck: Check for yes and no questions
     * params: char answer (answer to a y/n question)
     * returns: true if answer = "y"||"Y"||"n"||"N||
     */
    bool answerCheck(char answer);
    /*
     * buildyCheck: Check if the year a computer was built is acceptable
     * params: string buildy (year computer was built)
     * returns: false if contains '.', not a digit or buildy>2016
     */
    bool buildyCheck(string buildy);
    /*
     * builtCheck: Check if computer was built or not
     * params: bool built (Was computer built or not)
     * returns: true if computer was built
     */
    bool builtCheck(bool built);
    /*
     * idCheck: Check if the id is in the database for scientists
     * params: int id (Scientist id), vector<Scientist> (vector containing scientists table)
     * returns: true if a mathcing id is in the database
     */
    bool idCheck(int id, vector<Scientist>);
    /*
     * cpuIdCheck: Check if the id is in the database for computers
     * params: int id (Computer id), vector<Computer> (vector containing computers table)
     * returns: true if a mathcing id is in the database
     */
    bool cpuIdCheck(int id, vector<Computer>);
};

#endif // INPUTCHECK_H
