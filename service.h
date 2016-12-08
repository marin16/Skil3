#ifndef Service_H
#define Service_H

#include <vector>
#include "scientist.h"
#include "computer.h"
#include "dataaccess.h"
#include "linked.h"

class Service
{
public:
    // Service for scientists
    Service();
    vector<Scientist> getScientists(int sortBy);
    vector<Scientist> searchForScientist(string search);
    bool deleteScientist(int id);
    bool addScientist(Scientist newScientist);
    bool editScientist(int id, Scientist editScientist);

    // Service for computers
    vector<Computer> getComputers(int sortBy);
    vector<Computer> searchForComputer(string search);
    bool deleteComputer(int id);
    bool addComputer(Computer newComputer);
    bool editComputer(int id, Computer editComputer);

    // Shared service
    void clearData();
    // Links computer and scientist
    bool link(int cId, int sId);
    // used to get list of links
    vector<Linked> getLinks(int sortBy);

private:
    // DataAccess
    DataAccess _dataAccess;
};

#endif // Service_H
