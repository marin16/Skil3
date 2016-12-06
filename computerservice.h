#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include <vector>
#include "computer.h"
#include "dataaccess.h"

class ComputerService
{
public:
    ComputerService();
    vector<Computer> getComputers(int sortBy);
    vector<Computer> searchForComputer(string search, string searchBy);
    bool deleteComputer(string deleteC);
    bool addComputer(Computer newComputer);
    void clearData();
private:
    DataAccess _dataAccess;
};
#endif // COMPUTERSERVICE_H
