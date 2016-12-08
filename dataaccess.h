#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <vector>
#include <QtSql>

#include "person.h"
#include "computer.h"


/*
 * DataAccess manages all communications with the database
 */
class DataAccess
{
public:
    DataAccess();
    // Writes a single person to the database
    bool writePerson(Person person);
    // Reads all persons from the datafile and returns them in a vector
    vector<Person> readPersons();
    vector<Computer> readComputers();
    //Writes a single computer to the database
    bool writeComputer(Computer computer);
    void clearList();
    // Returs persons returned from the databasequery
    vector<Person> readPersonsFromQuery(string q);
    // returns vector of computers returned by the database query
    vector<Computer> readComputersFromQuery(string q);
    // deletes a person from the database by ID
    bool deletePerson(int id);
    // deletes a computer from the database by ID
    bool deleteComputer(int id);
    // edits a person by ID
    bool editPerson(int id, Person person);
    // edits computer by ID
    bool editComputer(int id, Computer computer);
private:
    QSqlDatabase _db;
};

#endif // DATAACCESS_H
