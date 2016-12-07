#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <vector>
#include "person.h"
#include "computer.h"
#include "dataaccess.h"

class PersonService
{
public:
// Service for persons
    PersonService();
    vector<Person> getPersons(int sortBy);
    vector<Person> searchForPerson(string search, string searchBy);
    bool deletePerson(string deleteP);
    bool addPerson(Person newPerson);

// Service for computers
    vector<Computer> getComputers(int sortBy);
    vector<Computer> searchForComputer(string search, string searchBy);
    bool deleteComputer(string deleteC);
    bool addComputer(Computer newComputer);

// Shared
    void clearData();

private:
    // DataAccess
    DataAccess _dataAccess;
};

#endif // PERSONSERVICE_H
