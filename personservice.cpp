#include <algorithm>
#include <string>


#include "personservice.h"

//http://stackoverflow.com/questions/14081335/algorithm-vector-sort-with-objects
bool sortByName(const Person & p1, const Person & p2)
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
}

PersonService::PersonService()
{

}

vector<Person> PersonService::getPersons(int sortBy)
{
    vector<Person> persons;

    // reads all persons from csv
    persons = _dataAccess.readPersons();


    // TODO: logic sort search etc...
    if(sortBy == 1)
        sort(persons.begin(), persons.end(), sortByName);
    else if(sortBy == 2)
        sort(persons.begin(), persons.end(), sortByBirth);
    else if(sortBy == 3)
        sort(persons.begin(), persons.end(), sortByCountry);

    return persons;
}

bool PersonService::addPerson(Person p)
{
    if(p.getName() != "" && p.getGender() != NULL && p.getCountry() != "")
    {
        _dataAccess.writePerson(p);
        return true;
    }
    else
        return false;
}

vector<Person> PersonService::searchForPerson(string search, string searchBy)
{
    vector<Person> persons = getPersons(0);
    vector<Person> results;
    for(size_t i = 0; i < persons.size(); ++i){
        if(searchBy == "name" && persons[i].getName() == search){
            results.push_back(persons[i]);
        }
        else if(searchBy == "gender" && persons[i].getGender() == search.at(0)){
            results.push_back(persons[i]);
        }
        // http://www.cplusplus.com/reference/string/stoi/
        else if(searchBy == "birth" && persons[i].getBirth() == stoi(search,nullptr,0)){
            results.push_back(persons[i]);
        }
        else if(searchBy == "death" && persons[i].getDeath() == stoi (search,nullptr,0)){
            results.push_back(persons[i]);
        }
        else if(searchBy == "country" && persons[i].getCountry() == search){
            results.push_back(persons[i]);
        }
    }
    return results;
}

void PersonService::clearData()
{
    _dataAccess.clearList();
}

vector<Person> PersonService::deletePerson(string deleteP)
{
    vector<Person> persons = getPersons(0);
    vector<Person> deleteResult;
    for(size_t i = 0; i < persons.size(); ++i){
        if(persons[i].getName() == deleteP){
            persons.erase(persons.begin() + i);
            continue;
        }
    }
    return deleteResult;
}
