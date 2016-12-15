#include <algorithm>
#include <string>
#include <regex>


#include "service.h"

Service::Service(){

}

vector<Scientist> Service::getScientists(){

    vector<Scientist> scientists;
    scientists = _dataAccess.readScientists();
    return scientists;
}

bool Service::addScientist(Scientist p){

    if(p.getName() != "" && p.getGender() != 0 && p.getCountry() != ""){

        return _dataAccess.writeScientist(p);
    }
    else
        return false;
}

vector<Scientist> Service::searchForScientist(string search){

    vector<Scientist> scientists = getScientists();
    vector<Scientist> results;

    for (size_t i = 0; i < scientists.size(); i++){

        if (scientists.at(i).contains(search)){

            results.push_back(scientists.at(i));
        }
    }
    return results;
}

void Service::clearData(){

    _dataAccess.clearList();
}

bool Service::deleteScientist(int id){

    return _dataAccess.deleteScientist(id);
}

vector<Computer> Service::getComputers(){

    vector<Computer> computers;
    computers = _dataAccess.readComputers();
    return computers;
}

vector<Linked> Service::getLinks(){

    vector<Linked> links;
    links =_dataAccess.readLinked();
    return links;
}

bool Service::addComputer(Computer c){

    if(c.getName() != "" && c.getType() != ""){

        return _dataAccess.writeComputer(c);
    }
    else
        return false;
}

vector<Computer> Service::searchForComputer(string search){

    vector<Computer> computers = getComputers();
    vector<Computer> results;

    for (size_t i = 0; i < computers.size(); i++){

        if (computers.at(i).contains(search)){

            results.push_back(computers.at(i));
        }
    }
    return results;
}

bool Service::deleteComputer(int id){

    return _dataAccess.deleteComputer(id);
}

bool Service::editScientist(int id, Scientist editScientist){

    return _dataAccess.editScientist(id, editScientist);
}

bool Service::editComputer(int id, Computer editComputer){

    return _dataAccess.editComputer(id, editComputer);
}

bool Service::link(int cId, int sId){

    return _dataAccess.link(cId, sId);
}

bool Service::unLink(int cId, int sId){

    return _dataAccess.unLink(cId, sId);
}
