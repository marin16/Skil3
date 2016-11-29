#include "personservice.h"

PersonService::PersonService()
{

}

vector<Person> PersonService::getPersons(/* TODO: params, search, sort*/)
{
    vector<Person> persons;

    // reads all persons from csv
    persons = _dataAccess.readPersons();


    // TODO: logic sort search etc...

    return persons;
}

void PersonService::addPerson(Person newPerson)
{
    _dataAccess.writePerson(newPerson);
}
