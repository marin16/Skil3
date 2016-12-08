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
    if(p.getName() != "" && p.getGender() != 0 && p.getCountry() != "")
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

bool Service::deletePerson(int id)
{
    return _dataAccess.deletePerson(id);
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

bool Service::editPerson(int id, Person editPerson)
{
    return _dataAccess.editPerson(id, editPerson);
}

bool Service::editComputer(int id, Computer editComputer)
{
    return _dataAccess.editComputer(id, editComputer);
}

bool Service::link(int cId, int sId)
{
    return _dataAccess.link(cId, sId);
}
