#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <vector>
#include <QtSql>

#include "scientist.h"
#include "computer.h"
#include "linked.h"

/*
 * DataAccess manages all communications with the database
 */
class DataAccess
{
public:
    DataAccess();
    // Writes a single scientist to the database
    bool writeScientist(Scientist scientist);
    // Reads all Scientists from the datafile and returns them in a vector
    vector<Scientist> readScientists();
    vector<Computer> readComputers();
    //Writes a single computer to the database
    bool writeComputer(Computer computer);
    void clearList();
    // Returs Scientists returned from the databasequery
    vector<Scientist> readScientistsFromQuery(string q);
    // returns vector of computers returned by the database query
    vector<Computer> readComputersFromQuery(string q);
    // deletes a scientist from the database by ID
    bool deleteScientist(int id);
    // deletes a computer from the database by ID
    bool deleteComputer(int id);
    // edits a scientist by ID
    bool editScientist(int id, Scientist scientist);
    // edits computer by ID
    bool editComputer(int id, Computer computer);
    // links computer and scientist
    bool link(int cId, int sId);
    // reads from scientist_has_computer into vector of links
    vector<Linked> readLinked();
    // reads from scientist_has_computer query results into vector of links
    vector<Linked> readLinkedFromQuery(string q);
private:
    QSqlDatabase _db;
};

#endif // DATAACCESS_H
