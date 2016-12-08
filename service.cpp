#include <algorithm>
#include <string>
#include <regex>


#include "service.h"

//http://stackoverflow.com/questions/14081335/algorithm-vector-sort-with-objects
/*bool sortPersonByName(const Person & p1, const Person & p2)
{
   string p1string = p1.getName();
   string p2string = p2.getName();
   p1string[0] = toupper(p1string[0]);
   p2string[0] = toupper(p2string[0]);

   return p1string < p2string;
}

bool sortComputerByName(const Computer & p1, const Computer & p2)
{
   string p1string = p1.getName();
   string p2string = p2.getName();
   p1string[0] = toupper(p1string[0]);
   p2string[0] = toupper(p2string[0]);

   return p1string < p2string;
}

bool sortByBirth(const Person & p1, const Person & p2)
{
   return p1.getBirth() < p2.getBirth();
}

bool sortByCountry(const Person & p1, const Person & p2)
{
    string p1string = p1.getCountry();
    string p2string = p2.getCountry();
    p1string[0] = toupper(p1string[0]);
    p2string[0] = toupper(p2string[0]);

    return p1string < p2string;
}*/

//Fall sem breytir streng fyrir gender i char
char genderStr2Char(string fmale)
{
    if(regex_match(fmale,regex("male|m",regex_constants::icase)))
        return 'M';
    else if(regex_match(fmale,regex("female|f",regex_constants::icase)))
        return 'F';
    else
        return '0';
}

bool sortBybuildy(const Computer & p1, const Computer & p2)
{
   return p1.getbuildy() < p2.getbuildy();
}

bool sortByType(const Computer & p1, const Computer & p2)
{
    string p1string = p1.getType();
    string p2string = p2.getType();
    p1string[0] = toupper(p1string[0]);
    p2string[0] = toupper(p2string[0]);

    return p1string < p2string;
}

Service::Service()
{

}

vector<Person> Service::getPersons(int sortBy)
{
    vector<Person> persons;

    // TODO: logic sort search etc...
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
        _dataAccess.writePerson(p);
        return true;
    }
    else
        return false;
}

vector<Person> Service::searchForPerson(string search/*, string searchBy*/)
{
    vector<Person> persons = getPersons(0);
    vector<Person> results;
    /*for(size_t i = 0; i < persons.size(); ++i){
        if(searchBy == "name" && regex_match(persons[i].getName(),regex(search,regex_constants::icase))){
            results.push_back(persons[i]);
        }
        else if(searchBy == "gender" && (toupper(persons[i].getGender()) == genderStr2Char(search))){
            results.push_back(persons[i]);
        }
        // http://www.cplusplus.com/reference/string/stoi/
        else if(searchBy == "birth" && persons[i].getBirth() == stoi(search,nullptr,0)){
            results.push_back(persons[i]);
        }
        else if(searchBy == "death" && persons[i].getDeath() == stoi(search,nullptr,0)){
            results.push_back(persons[i]);
        }
        else if(searchBy == "country" && regex_match(persons[i].getCountry(), regex(search, regex_constants::icase))){
            results.push_back(persons[i]);
        }
    }*/
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

    // reads all persons from csv
    computers = _dataAccess.readComputers();


    // TODO: logic sort search etc...
    /*if(sortBy == 1)
        sort(computers.begin(), computers.end(), sortComputerByName);
    else if(sortBy == 2)
        sort(computers.begin(), computers.end(), sortBybuildy);
    else if(sortBy == 3)
        sort(computers.begin(), computers.end(), sortByType);*/

    return computers;
}

bool Service::addComputer(Computer c)
{
    if(c.getName() != "" && c.getType() != "")
    {
        _dataAccess.writeComputer(c);
        return true;
    }
    else
        return false;
}

vector<Computer> Service::searchForComputer(string search, string searchBy)
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
        else if(searchBy == "buildy" && computers[i].getbuildy() == stoi(search,nullptr,0)){
            results.push_back(computers[i]);
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
