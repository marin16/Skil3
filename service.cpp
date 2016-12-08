#include <algorithm>
#include <string>
#include <regex>


#include "service.h"

Service::Service()
{

}

vector<Person> Service::getPersons(int sortBy)
{
    vector<Person> persons;

    if(sortBy == 1)
        persons = _dataAccess.readPersonsFromQuery("select * from Scientists order by name asc");
    else if(sortBy == 2)
        persons = _dataAccess.readPersonsFromQuery("select * from Scientists order by dob asc");
    else if(sortBy == 3)
        persons = _dataAccess.readPersonsFromQuery("select * from Scientists order by dod asc");
    else if(sortBy == 4)
        persons = _dataAccess.readPersonsFromQuery("select * from Scientists order by country asc");
    else if(sortBy == 5)
        persons = _dataAccess.readPersonsFromQuery("select * from Scientists order by name desc");
    else if(sortBy == 6)
        persons = _dataAccess.readPersonsFromQuery("select * from Scientists order by dob desc");
    else if(sortBy == 7)
        persons = _dataAccess.readPersonsFromQuery("select * from Scientists order by dod desc");
    else if(sortBy == 8)
        persons = _dataAccess.readPersonsFromQuery("select * from Scientists order by country desc");
    else
        persons = _dataAccess.readPersons();
    return persons;
}

bool Service::addPerson(Person p)
{
    if(p.getName() != "" && p.getGender() != NULL && p.getCountry() != "")
    {
        return _dataAccess.writePerson(p);
    }
    else
        return false;
}

vector<Person> Service::searchForPerson(string search/*, string searchBy*/)
{
    vector<Person> persons = getPersons(0);
    vector<Person> results;

    for (size_t i = 0; i < persons.size(); i++)
    {
        if (persons.at(i).contains(search))
        {
            results.push_back(persons.at(i));
        }
    }
    return results;
}



void Service::clearData()
{
    _dataAccess.clearList();
}

bool Service::deletePerson(string deleteP)
{
    vector<Person> persons = getPersons(0);
    int orgSize = persons.size();
    for(size_t i = 0; i < persons.size(); ++i)
    {
        if(regex_match(persons[i].getName(), regex(deleteP,regex_constants::icase)))
        {
            persons.erase(persons.begin() + i);
        }
    }
    if(orgSize-1 == persons.size())
    {
        _dataAccess.clearList();
        for(size_t i  = 0; i < persons.size(); i++)
        {
            _dataAccess.writePerson(persons[i]);
        }
        return true;
    }
    else
    {
        return false;
    }
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

bool Service::addComputer(Computer c)
{
    if(c.getName() != "" && c.getType() != "")
    {
        return _dataAccess.writeComputer(c);

    }
    else
        return false;
}

vector<Computer> Service::searchForComputer(string search/*, string searchBy*/)
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

bool Service::deleteComputer(string deleteC)
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
        //_dataAccess.clearList();
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
