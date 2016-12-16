#ifndef Service_H
#define Service_H

#include <vector>

#include "scientist.h"
#include "computer.h"
#include "dataaccess.h"
#include "linked.h"

class Service{
public:
    Service();

    /*
     * getScientists: Used to get a (optionaly: sorted) list of Scientists.
     * params: int sortBy (determens how the list should be sorted).
     * returns: vector<Scientists> sorted list
     */
    vector<Scientist> getScientists();

    /*
     * searchForScientist: Used to search for a scientist.
     * params: string search (search string that is compared with all scientists).
     * returns: vector<Scientist> all matches.
     */
    vector<Scientist> searchForScientist(string search);

    /*
     * deleteScientist: Used when deleteing scientist.
     * params: int id (id of Scientist that is to be deleted).
     * returns: true if deletion completed, false if it failed.
     */
    bool deleteScientist(int id);

    /*
     * getScientistById: Used when getting scientist by ID.
     * params: int id (id of Scientist that is to be found).
     * returns: scientist.
     */
    Scientist getScientistById(int id);

    /*
     * getComputerById: Used when getting computer by ID.
     * params: int id (id of Computer that is to be found).
     * returns: computer.
     */
    Computer getComputerById(int id);

    /*
     * addScientist: Used when adding a new scientist.
     * params: Scientist newScientist (Scientist containing valuse to be added).
     * returns: true if addition completed, false if it failed.
     */
    bool addScientist(Scientist newScientist);

    /*
     * editScientist: Used when editing a scientist from the database.
     * params: int id (id of the scientist that is to be edited), Scientist editScientist (Scientist containing new values).
     * returns: true if the edit succeded, false if it failed.
     */
    bool editScientist(int id, Scientist editScientist);

    /*
     * getComputers: Used to get a (optionaly: sorted) list of Computers.
     * params: int sortBy (determens how the list should be sorted).
     * returns: vector<Computer> sorted list
     */
    vector<Computer> getComputers();

    /*
     * searchForComputer: Used to search for a computer.
     * params: string search (search string that is compared with all computers).
     * returns: vector<Scientist> all matches.
     */
    vector<Computer> searchForComputer(string search);

    /*
     * deleteComputer: Used when deleteing computer.
     * params: int id (id of computer that is to be deleted).
     * returns: true if deletion completed, false if it failed.
     */
    bool deleteComputer(int id);

    /*
     * addComputer: Used when adding a new computer.
     * params: Computer newComputer (Computer containing valuse to be added).
     * returns: true if addition completed, false if it failed.
     */
    bool addComputer(Computer newComputer);

    /*
     * editComputer: Used when editing a computer from the database.
     * params: int id (id of the computer that is to be edited), Computer editComputer (Computer containing new values).
     * returns: true if the edit succeded, false if it failed.
     */
    bool editComputer(int id, Computer editComputer);

    /*
     * clearData(): Used when clearing all data from the database.
     */
    void clearData();

    /*
     * link: Used when linking computer and scientist.
     * params: int cId (id of computer to be linked), id sId (id of scientist to be linked).
     * returns: true if the link succeded, false if it failed.
     */
    bool link(int cId, int sId);

    /*
     * unlink: Used when unlinking computer and scientist.
     * params: int cId (id of computer to be unlinked), id sId (id of scientist to be unlinked).
     * returns: true if the unlink succeded, false if it failed.
     */
    bool unLink(int cId, int sId);

    /*
     * getLinks: Used to get a (optionaly: sorted) list of Linked Computers and Scientists.
     * params: int sortBy (determens how the list should be sorted).
     * returns: vector<Linked> sorted list.
     */
    vector<Linked> getLinks();

private:
    // DataAccess
    DataAccess _dataAccess;
};

#endif // Service_H
