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
    // Reads all persons from the datafile and returns them in a vector
    vector<Person> readPersons();
<<<<<<< HEAD
    vector<Computer> readComputers();
=======
    //Writes a single computer to the datafile
    void writeComputer(Computer computer);
>>>>>>> dfaeadec602f4ea2c3a09c443b2e3edadd9e4bff
    void clearList();
private:
    QSqlDatabase _db;
};

#endif // DATAACCESS_H
