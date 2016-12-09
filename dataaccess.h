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
class DataAccess{
public:
    DataAccess();
    /*
     * writeScientist: Used to write scientist to database.
     * params: Scientist scientist (scientist to be written).
     * returns: true if query execuded successfuly, otherwise false.
     */
    bool writeScientist(Scientist scientist);

    /*
     * readScientists: Used to get a vector of all Scientists from the database.
     * returns: vector<Scientist>
     */
    vector<Scientist> readScientists();

    /*
     * readScientistsFromQuery: Used to get a vector of Scientists from the results of input query.
     * params: string q (query string that is executed)
     * returns: vector<Scientist>
     */
    vector<Scientist> readScientistsFromQuery(string q);

    /*
     * readComputers: Used to get a vector of all Computers from the database.
     * returns: vector<Computer>
     */
    vector<Computer> readComputers();

    /*
     * writeComputer: Used to write a computer to the database.
     * params: Computer computer (computer to be written)
     * returns: true if query execuded successfuly, otherwise false.
     */
    bool writeComputer(Computer computer);

    /*
     * clearList(): Used to remove all data from the database.
     */
    void clearList();

    /*
     * readComputersFromQuery: Used to get a vector of Computers from the results of input query.
     * params: string q (query string that is executed)
     * returns: vector<Computer>
     */
    vector<Computer> readComputersFromQuery(string q);

    /*
     * deleteScientist: Used to remove a scientist from the database.
     * params: int id (id of the scientist that is to be removed).
     * returns: true if query execuded successfuly, otherwise false.
     */
    bool deleteScientist(int id);

    /*
     * deleteComputer: Used to remove a computer from the database.
     * params: int id (id of the computer that is to be removed).
     * returns: true if query execuded successfuly, otherwise false.
     */
    bool deleteComputer(int id);

    /*
     * editScientist: Used to updata a certain scientist in the database.
     * params: int id (id of the scientist that is to be updated), Scientist scientist (scientist data that is to be set)
     * returns: true if query execuded successfuly, otherwise false.
     */
    bool editScientist(int id, Scientist scientist);

    /*
     * editComputer: Used to updata a certain computer in the database.
     * params: int id (id of the computer that is to be updated), Computer computer (computer data that is to be set)
     * returns: true if query execuded successfuly, otherwise false.
     */
    bool editComputer(int id, Computer computer);

    /*
     * link: Used to add a link beetween a scientist and a computer.
     * params: int cId (id of computer that is to be linked), int sId (id of the scientist that is to be linked)
     * returns: true if query execuded successfuly, otherwise false.
     */
    bool link(int cId, int sId);

    /*
     * unlink: Used to delete a link beetween a scientist and a computer.
     * params: int cId (id of computer that is to be unlinked), int sId (id of the scientist that is to be unlinked)
     * returns: true if query execuded successfuly, otherwise false.
     */
    bool unLink(int cId, int sId);

    /*
     * readLinked: Used to get a vector of all linked computers and scientists.
     * returns: vector<Linked>
     */
    vector<Linked> readLinked();

    /*
     * readLinkedFromQuery: Used to get a vector of Linked computers and scientists from the results of input query.
     * params: string q (query string that is executed)
     * returns: vector<Linked>
     */
    vector<Linked> readLinkedFromQuery(string q);

private:
    QSqlDatabase _db;
};

#endif // DATAACCESS_H
