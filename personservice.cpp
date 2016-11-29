#include <algorithm>

#include "personservice.h"

//http://stackoverflow.com/questions/14081335/algorithm-vector-sort-with-objects
bool cmd(const Person & p1, const Person & p2)
{
   if (p1.getName() != p2.getName()) return p1.getName() < p2.getName();
   //return s1.grade < s2.grade;
}

PersonService::PersonService()
{

}

vector<Person> PersonService::getPersons(int sortBy)
{
    vector<Person> persons;

    // reads all persons from csv
    persons = _dataAccess.readPersons();


    // TODO: logic sort search etc...
    if(sortBy == 1)
        sort(persons.begin(), persons.end(), cmd);

    return persons;
}

void PersonService::addPerson(Person newPerson)
{
    _dataAccess.writePerson(newPerson);
}

