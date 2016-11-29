#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <vector>
#include "person.h"

class PersonService
{
public:
    PersonService();

    vector<Person> getPersons(/* TODO: params, search, sort*/);
    void addPerson(Person newPerson);
};

#endif // PERSONSERVICE_H
