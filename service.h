#ifndef Service_H
#define Service_H

#include <vector>
#include "person.h"
#include "computer.h"
#include "dataaccess.h"

class Service
{
public:
    // Service for persons
    Service();
    vector<Person> getPersons(int sortBy);
    vector<Person> searchForPerson(string search);
    bool deletePerson(int id);
    bool addPerson(Person newPerson);
    bool editPerson(int id, Person editPerson);

    // Service for computers
    vector<Computer> getComputers(int sortBy);
    vector<Computer> searchForComputer(string search);
    bool deleteComputer(int id);
    bool addComputer(Computer newComputer);
    bool editComputer(int id, Computer editComputer);

    // Shared service
    void clearData();

private:
    // DataAccess
    DataAccess _dataAccess;
};

#endif // Service_H
