#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <vector>
#include "person.h"

class DataAccess
{
public:
    DataAccess();

    void writePerson(Person person);
    vector<Person> readPersons();
};

#endif // DATAACCESS_H
