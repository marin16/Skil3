#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <vector>
#include <QtSql>

#include "person.h"
#include "computer.h"

class DataAccess
{
public:
    DataAccess();
    // Writes a single person to the datafile
    void writePerson(Person person);
    // Reads all persons from the datafiel and returns them in a vector
    vector<Person> readPersons();
    vector<Computer> readComputers();
    void clearList();
private:
    QSqlDatabase _db;
};

#endif // DATAACCESS_H
