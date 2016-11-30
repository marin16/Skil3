#include <algorithm>
#include <string>


#include "personservice.h"

//http://stackoverflow.com/questions/14081335/algorithm-vector-sort-with-objects
bool sortByName(const Person & p1, const Person & p2)
{
   string p1string = p1.getName();
   string p2string = p2.getName();
   p1string[0] = toupper(p1string[0]);
   p2string[0] = toupper(p2string[0]);

   return p1string < p2string;
}

bool sortByBirth(const Person & p1, const Person & p2)
{
   return p1.getBirth() < p2.getBirth();
}

bool sortByCountry(const Person & p1, const Person & p2)
{
    string p1string = p1.getCountry();
    string p2string = p2.getCountry();
    p1string[0] = toupper(p1string[0]);
    p2string[0] = toupper(p2string[0]);

    return p1string < p2string;
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

bool PersonService::addPerson(Person newPerson)
{
    _dataAccess.writePerson(newPerson);
    return true;
}

