#include "computerservice.h"
#include <algorithm>
#include <string>
#include <regex>

//http://stackoverflow.com/questions/14081335/algorithm-vector-sort-with-objects
bool sortByName(const Computer & p1, const Computer & p2)
{
   string p1string = p1.getName();
   string p2string = p2.getName();
   p1string[0] = toupper(p1string[0]);
   p2string[0] = toupper(p2string[0]);

   return p1string < p2string;
}

bool sortByBuilty(const Computer & p1, const Computer & p2)
{
   return p1.getBuilty() < p2.getBuilty();
}

bool sortByType(const Computer & p1, const Computer & p2)
{
    string p1string = p1.getType();
    string p2string = p2.getType();
    p1string[0] = toupper(p1string[0]);
    p2string[0] = toupper(p2string[0]);

    return p1string < p2string;
}

ComputerService::ComputerService()
{

}

vector<Computer> ComputerService::getComputers(int sortBy)
{
    vector<Computer> computers;

    // reads all persons from csv
    //computers = _dataAccess.readComputers();


    // TODO: logic sort search etc...
    if(sortBy == 1)
        sort(computers.begin(), computers.end(), sortByName);
    else if(sortBy == 2)
        sort(computers.begin(), computers.end(), sortByBuilty);
    else if(sortBy == 3)
        sort(computers.begin(), computers.end(), sortByType);

    return computers;
}

bool ComputerService::addComputer(Computer c)
{
    if(c.getName() != "" && c.getType() != "")
    {
        _dataAccess.writeComputer(c);
        return true;
    }
    else
        return false;
}

vector<Computer> ComputerService::searchForComputer(string search, string searchBy)
{
    vector<Computer> computers = getComputers(0);
    vector<Computer> results;
    for(size_t i = 0; i < computers.size(); ++i){
        if(searchBy == "name" && regex_match(computers[i].getName(),regex(search,regex_constants::icase))){
            results.push_back(computers[i]);
        }
        else if(searchBy == "type" && regex_match(computers[i].getType(),regex(search,regex_constants::icase))){
            results.push_back(computers[i]);
        }
        // http://www.cplusplus.com/reference/string/stoi/
        else if(searchBy == "builty" && computers[i].getBuilty() == stoi(search,nullptr,0)){
            results.push_back(computers[i]);
        }
    }
    return results;
}

void ComputerService::clearData()
{
    _dataAccess.clearList();
}


bool ComputerService::deleteComputer(string deleteC)
{
    vector<Computer> computers = getComputers(0);
    int orgSize = computers.size();
    for(size_t i = 0; i < computers.size(); ++i)
    {
        if(regex_match(computers[i].getName(), regex(deleteC,regex_constants::icase)))
        {
            computers.erase(computers.begin() + i);
        }
    }
    if(orgSize-1 == computers.size())
    {
        _dataAccess.clearList();
        for(size_t i  = 0; i < computers.size(); i++)
        {
           // _dataAccess.writeComputer(computers[i]);
        }
        return true;
    }
    else
    {
        return false;
    }
}

