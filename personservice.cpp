#include <algorithm>

#include "personservice.h"

//http://stackoverflow.com/questions/14081335/algorithm-vector-sort-with-objects
bool sortByName(const Person & p1, const Person & p2)
{
   if (p1.getName() != p2.getName()) return p1.getName() < p2.getName();
}

bool sortByBirth(const Person & p1, const Person & p2)
{
   if (p1.getBirth() != p2.getBirth()) return p1.getBirth() < p2.getBirth();
}

bool sortByCountry(const Person & p1, const Person & p2)
{
    if (p1.getCountry() != p2.getCountry()) return p1.getCountry() < p2.getCountry();
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
        sort(persons.begin(), persons.end(), sortByName);
    else if(sortBy == 2)
        sort(persons.begin(), persons.end(), sortByBirth);
    else if(sortBy == 3)
        sort(persons.begin(), persons.end(), sortByCountry);

    return persons;
}

void PersonService::addPerson(Person newPerson)
{
    _dataAccess.writePerson(newPerson);
}

