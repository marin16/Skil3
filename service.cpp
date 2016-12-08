#include <algorithm>
#include <string>
#include <regex>


#include "service.h"

Service::Service()
{

}

vector<Scientist> Service::getScientists(int sortBy)
{
    vector<Scientist> scientists;

    if(sortBy == 1)
        scientists = _dataAccess.readScientistsFromQuery("select * from Scientists order by name asc");
    else if(sortBy == 2)
        scientists = _dataAccess.readScientistsFromQuery("select * from Scientists order by dob asc");
    else if(sortBy == 3)
        scientists = _dataAccess.readScientistsFromQuery("select * from Scientists order by dod asc");
    else if(sortBy == 4)
        scientists = _dataAccess.readScientistsFromQuery("select * from Scientists order by country asc");
    else if(sortBy == 5)
        scientists = _dataAccess.readScientistsFromQuery("select * from Scientists order by name desc");
    else if(sortBy == 6)
        scientists = _dataAccess.readScientistsFromQuery("select * from Scientists order by dob desc");
    else if(sortBy == 7)
        scientists = _dataAccess.readScientistsFromQuery("select * from Scientists order by dod desc");
    else if(sortBy == 8)
        scientists = _dataAccess.readScientistsFromQuery("select * from Scientists order by country desc");
    else
        scientists = _dataAccess.readScientists();
    return scientists;
}

bool Service::addScientist(Scientist p)
{
    if(p.getName() != "" && p.getGender() != 0 && p.getCountry() != "")
    {
        return _dataAccess.writeScientist(p);
    }
    else
        return false;
}

vector<Scientist> Service::searchForScientist(string search/*, string searchBy*/)
{
    vector<Scientist> scientists = getScientists(0);
    vector<Scientist> results;

    for (size_t i = 0; i < scientists.size(); i++)
    {
        if (scientists.at(i).contains(search))
        {
            results.push_back(scientists.at(i));
        }
    }
    return results;
}



void Service::clearData()
{
    _dataAccess.clearList();
}

bool Service::deleteScientist(int id)
{
    return _dataAccess.deleteScientist(id);
}

vector<Computer> Service::getComputers(int sortBy)
{
    vector<Computer> computers;

    if(sortBy == 1)
        computers = _dataAccess.readComputersFromQuery("select * from Computers order by name asc");
    else if(sortBy == 2)
        computers = _dataAccess.readComputersFromQuery("select * from Computers order by buildy asc");
    else if(sortBy == 3)
        computers = _dataAccess.readComputersFromQuery("select * from Computers order by type asc");
    else if(sortBy == 4)
        computers = _dataAccess.readComputersFromQuery("select * from Computers order by name desc");
    else if(sortBy == 5)
        computers = _dataAccess.readComputersFromQuery("select * from Computers order by buildy desc");
    else if(sortBy == 6)
        computers = _dataAccess.readComputersFromQuery("select * from Computers order by type desc");
    else
        computers = _dataAccess.readComputers();
    return computers;
}

vector<Linked> Service::getLinks(int sortBy)
{
    vector<Linked> links;

    if(sortBy == 1)
        links = _dataAccess.readLinkedFromQuery("select * from SC_view order by name asc");
    else if(sortBy == 2)
        links = _dataAccess.readLinkedFromQuery("select * from SC_view order by name:1 asc");
    else if(sortBy == 3)
        links = _dataAccess.readLinkedFromQuery("select * from SC_view order by name desc");
    else if(sortBy == 4)
        links = _dataAccess.readLinkedFromQuery("select * from SC_view order by name:1 desc");
    else
        links =_dataAccess.readLinked();
    return links;
}

bool Service::addComputer(Computer c)
{
    if(c.getName() != "" && c.getType() != "")
    {
        return _dataAccess.writeComputer(c);

    }
    else
        return false;
}

vector<Computer> Service::searchForComputer(string search)
{
    vector<Computer> computers = getComputers(0);
    vector<Computer> results;

    for (size_t i = 0; i < computers.size(); i++)
    {
        if (computers.at(i).contains(search))
        {
            results.push_back(computers.at(i));
        }
    }
    return results;
}

bool Service::deleteComputer(int id)
{
    return _dataAccess.deleteComputer(id);
}

bool Service::editScientist(int id, Scientist editScientist)
{
    return _dataAccess.editScientist(id, editScientist);
}

bool Service::editComputer(int id, Computer editComputer)
{
    return _dataAccess.editComputer(id, editComputer);
}

bool Service::link(int cId, int sId)
{
    return _dataAccess.link(cId, sId);
}
