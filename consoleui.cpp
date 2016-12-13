#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>

#include "consoleui.h"
#include "scientist.h"
#include "computer.h"
#include "utilities.h"
#include "linked.h"


using namespace std;

ConsoleUI::ConsoleUI(){

}


void ConsoleUI::run(){

    bool separate = false;
    _instructions();

    do{
        if (separate) {
            cout << endl;
        }
        separate = true;

        cout << "Command: ";
        string command;
        cin >> command;

        if(command == "add-c"){

            _addCPU();
        }
        else if(command == "search-c"){

            _searchCPU();
        }
        else if(command == "list-c"){

            _listCPU();
        }
        else if(command == "delete-c"){

            _deleteCPU();
        }
        else if(command == "edit-c"){

            _editComputer();
        }
        else if(command == "add-s"){

            _add();
        }
        else if(command == "search-s"){

            _search();
        }
        else if(command == "list-s"){

            _listScientists();
        }
        else if(command == "delete-s"){

            _delete();
        }
        else if(command == "edit-s"){

            _edit();
        }
        else if(command == "link"){

            _link();
        }
        else if(command == "unlink"){

            _unLink();
        }
        else if(command == "list"){

            _list();
        }
        else if(command == "help"){

            _instructions();
            separate = false;
        }
        else if(command == "clear"){

            _clear();
        }
        else if(command == "quit" || command == "q" || command == "exit"){

            break;
        }
        else{

            cout << "Unknown command: " << command << endl;
            cout << "please try again or write \"help\" for a list of commands." << endl;
            separate = false;
        }
    }while(true);
}

void ConsoleUI::_instructions(){

    cout << "Hello world" << endl;
    cout << "==========================================================" << endl;
    cout << "||     Please enter one of the following commands:      ||" << endl;
    cout << "==========================================================" << endl;
    cout << "||                                                      ||" << endl;
    cout << "||    add-c    - to add a new computer                  ||" << endl;
    cout << "||    list-c   - to get a list of computers             ||" << endl;
    cout << "||    search-c - to search for computer                 ||" << endl;
    cout << "||    edit-c   - to edit an computer                    ||" << endl;
    cout << "||    delete-c - to delete a computer                   ||" << endl;
    cout << "||                                                      ||" << endl;
    cout << "||    add-s    - to add a new scientist                 ||" << endl;
    cout << "||    list-s   - to get a list of scientists            ||" << endl;
    cout << "||    search-s - to search for scientist                ||" << endl;
    cout << "||    edit-s   - to edit an scientist                   ||" << endl;
    cout << "||    delete-s - to delete a scientist                  ||" << endl;
    cout << "||                                                      ||" << endl;
    cout << "||    link     - to link scientist and computer         ||" << endl;
    cout << "||    unlink   - to unlink scientist and computer       ||" << endl;
    cout << "||    list     - to get linked scientists and computers ||" << endl;
    cout << "||    clear    - to clear all data                      ||" << endl;
    cout << "||    help     - to view this again                     ||" << endl;
    cout << "||    quit     - to exit program                        ||" << endl;
    cout << "||                                                      ||" << endl;
    cout << "==========================================================" << endl;
}

void ConsoleUI::_add(){

    char answer;

    cout << "=======================================================" << endl;
    cout << "||Please add the parameters for the scientists       ||" << endl;
    cout << "||if you input invalid data you will be asked again. ||" << endl;
    cout << "=======================================================" << endl;

    Scientist newScientist = _createScientist();

    do{
        _displayScientist(newScientist);
        cout << "Is the information correct?(Y/N) ";
        cin >> answer;
    }while(!_Valid.answerCheck(answer));

    if (answer == 'y' || answer == 'Y'){

        cin.ignore();
        if (_service.addScientist(newScientist)){

            cout << "Success!" << endl;
        }
        else{

            cout << "Could not write this data to the database." << endl;
        }
    }
    else if (answer == 'n' || answer == 'N'){

        _add();
    }
}

void ConsoleUI::_addCPU(){

    char answer;

    cout << "=======================================================" << endl;
    cout << "||Please add the parameters for the computer         ||" << endl;
    cout << "||if you input invalid data you will be asked again. ||" << endl;
    cout << "=======================================================" << endl;

    Computer newComputer = _createComputer();

    do
    {
        _displayComputer(newComputer);
        cout << "Is the information correct?(Y/N) ";
        cin >> answer;
    }while(!_Valid.answerCheck(answer));

    if (answer == 'y' || answer == 'Y'){

        cin.ignore();
        if (_service.addComputer(newComputer)){

            cout << "Success!" << endl;
        }
        else{

            cout << "Could not write this data to the database" << endl;
        }
    }
    else if (answer == 'n' || answer == 'N'){

        _addCPU();
    }
}

void ConsoleUI::_search(){

    vector<Scientist> results;

    string search;
    char charsearch[100];

    cout << "Value: ";
    cin.ignore();
    cin.getline(charsearch,sizeof(charsearch));
    search = string(charsearch);

    //results = _service.searchForScientist(search);

    _displayScientists(results);
}

void ConsoleUI::_searchCPU(){

    vector<Computer> results;

    string search;
    char charsearch[100];

    cout << "Value: ";

    cin.ignore();
    cin.getline(charsearch,sizeof(charsearch));
    search = string(charsearch);

    results = _service.searchForComputer(search);

    _displayComputers(results);
}

void ConsoleUI::_delete(){

    vector<Scientist> scientists;
    scientists = _service.getScientists(0);

    int delId;

    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the scientist     ||" << endl;
    cout << "||              you want to delete:             ||" << endl;
    cout << "==================================================" << endl;

    cout << "ID: ";
    std::cin >> delId;

    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Wrong input, try again: ";
        std::cin >> delId;
    }

    if(_Valid.idCheck(delId, scientists)){

        if(_service.deleteScientist(delId))
            cout << "Success!" << endl;
        else
            cout << "Failed." << endl;
    }
    else{
        _illegalInput();
    }
}

void ConsoleUI::_deleteCPU(){

    vector<Computer> computers;
    computers = _service.getComputers(0);

    int delId;

    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the computer      ||" << endl;
    cout << "||              you want to delete:             ||" << endl;
    cout << "==================================================" << endl;

    cout << "ID: ";
    cin >> delId;

    while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong input, try again: ";
            std::cin >> delId;
    }

    if(_Valid.cpuIdCheck(delId, computers)){

        if(_service.deleteComputer(delId))
            cout << "Success!" << endl;
        else
            cout << "Failed." << endl;
    }
    else{
        _illegalInput();
    }
}

void ConsoleUI::_listScientists(){

    cout << "===============================================================" << endl;
    cout << "||        Please enter one of the following commands:        ||" << endl;
    cout << "===============================================================" << endl;
    cout << "||                                                           ||" << endl;
    cout << "||    name-asc      - sort by name alphabetically ascending  ||" << endl;
    cout << "||    birth-asc     - sort by year of birth ascending        ||" << endl;
    cout << "||    death-asc     - sort by year of death ascending        ||" << endl;
    cout << "||    country-asc   - sort by nationality ascending          ||" << endl;
    cout << "||                                                           ||" << endl;
    cout << "||    name-desc     - sort by name alphabetically descending ||" << endl;
    cout << "||    birth-desc    - sort by year of birth descending       ||" << endl;
    cout << "||    death-desc    - sort by year of birth descending       ||" << endl;
    cout << "||    country-desc  - sort by nationality descending         ||" << endl;
    cout << "||                                                           ||" << endl;
    cout << "||    unsorted      - get unsorted list (default)            ||" << endl;
    cout << "||                                                           ||" << endl;
    cout << "===============================================================" << endl;

    string sort;
    cin >> sort;

    vector<Scientist> scientists;

    if (sort == "name-asc")
        scientists = _service.getScientists(1);
    else if (sort == "birth-asc")
        scientists = _service.getScientists(2);
    else if (sort == "death-asc")
        scientists = _service.getScientists(3);
    else if (sort == "country-asc")
        scientists = _service.getScientists(4);
    else if (sort == "name-desc")
        scientists = _service.getScientists(5);
    else if (sort == "birth-desc")
        scientists = _service.getScientists(6);
    else if (sort == "death-desc")
        scientists = _service.getScientists(7);
    else if (sort == "country-desc")
        scientists = _service.getScientists(8);
    else
        scientists = _service.getScientists(0);

    _displayScientists(scientists);
}

void ConsoleUI::_listCPU(){

    cout << "=================================================================" << endl;
    cout << "||         Please enter one of the following commands:         ||" << endl;
    cout << "=================================================================" << endl;
    cout << "||                                                             ||" << endl;
    cout << "||    name-asc      - sort by name alphabetically ascending    ||" << endl;
    cout << "||    buildy-asc    - sort by built year ascending             ||" << endl;
    cout << "||    type-asc      - sort by type ascending                   ||" << endl;
    cout << "||                                                             ||" << endl;
    cout << "||    name-desc     - sort by name alphabetically descending   ||" << endl;
    cout << "||    buildy-desc   - sort by built year descending            ||" << endl;
    cout << "||    type-desc     - sort by type descending                  ||" << endl;
    cout << "||                                                             ||" << endl;
    cout << "||    unsorted      - get unsorted list (default)              ||" << endl;
    cout << "||                                                             ||" << endl;
    cout << "=================================================================" << endl;

    string sort;
    cin >> sort;

    vector<Computer> computers;

    if (sort == "name-asc")
        computers = _service.getComputers(1);
    else if (sort == "buildy-asc")
        computers = _service.getComputers(2);
    else if (sort == "type-asc")
        computers = _service.getComputers(3);
    else if (sort == "name-desc")
        computers = _service.getComputers(4);
    else if (sort == "buildy-desc")
        computers = _service.getComputers(5);
    else if (sort == "type-desc")
        computers = _service.getComputers(6);
    else
        computers = _service.getComputers(0);

    _displayComputers(computers);
}

void ConsoleUI::_list(){

    cout << "============================================================================" << endl;
    cout << "||              Please enter one of the following commands:               ||" << endl;
    cout << "============================================================================" << endl;
    cout << "||                                                                        ||" << endl;
    cout << "||    computer-asc      - sort by computer name alphabetically ascending  ||" << endl;
    cout << "||    scientist-asc     - sort by scientist nameyear ascending            ||" << endl;
    cout << "||                                                                        ||" << endl;
    cout << "||    computer-desc     - sort by computer name alphabetically descending ||" << endl;
    cout << "||    scientist-desc    - sort by scientist nameyear descending           ||" << endl;
    cout << "||                                                                        ||" << endl;
    cout << "||    unsorted          - get unsorted list (default)                     ||" << endl;
    cout << "||                                                                        ||" << endl;
    cout << "============================================================================" << endl;

    string sort;
    cin >> sort;

    vector<Linked> links;

    if (sort == "computer-asc")
        links = _service.getLinks(1);
    else if (sort == "scientist-asc")
        links = _service.getLinks(2);
    else if (sort == "computer-desc")
        links = _service.getLinks(3);
    else if (sort == "scientist-desc")
        links = _service.getLinks(4);
    else
        links = _service.getLinks(0);

    _displayLinked(links);
}

void ConsoleUI::_edit(){

    vector<Scientist> scientists;
    scientists = _service.getScientists(0);

    int editId;

    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the scientist     ||" << endl;
    cout << "||              you want to edit:               ||" << endl;
    cout << "==================================================" << endl;

    cout << "ID: ";
    cin >> editId;

    while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong input, try again: ";
            std::cin >> editId;
    }

    if(_Valid.idCheck(editId, scientists)){

        if(_service.editScientist(editId,_createScientist()))
            cout << "Scientist successfully edited." << endl;
        else
            cout << "Failed." << endl;
    }
    else{
        _illegalInput();
    }
}

void ConsoleUI::_editComputer(){

    vector<Computer> computers;
    computers = _service.getComputers(0);

    int editId;

    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the computer      ||" << endl;
    cout << "||              you want to edit:               ||" << endl;
    cout << "==================================================" << endl;

    cout << "ID: ";
    cin >> editId;

    while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong input, try again: ";
            std::cin >> editId;
    }

    if(_Valid.cpuIdCheck(editId, computers)){

        if(_service.editComputer(editId,_createComputer()))
            cout << "Computer successfully edited." << endl;
        else
            cout << "Failed." << endl;
    }
    else{
        _illegalInput();
    }
}

void ConsoleUI::_displayScientist(Scientist scientist){

    size_t nameLength = scientist.getName().length();

    // nameLength cant be shorter than "Name: " (6)
    if (nameLength < 6)
        nameLength = 6;

    // Labels
    cout << setw(nameLength+1) << left << "Name:";
    cout << setw(8) << left << "Gender:";
    cout << setw(7) << left << "Born:";
    cout << setw(7) << left << "Died:";
    cout << "Country:" << endl;

    // Print the scientist
    cout << setw(nameLength+1) << left << scientist.getName();
    cout << setw(8) << left << scientist.getGender();
    cout << setw(7) << left << scientist.getBirth();
    if (!scientist.getDeath())
        cout << setw(7) << left << "Alive";
    else
        cout << setw(7) << left << scientist.getDeath();
    cout << scientist.getCountry() << endl;
}

void ConsoleUI::_displayScientists(vector<Scientist> scientists){

    // If there is no scientist in list we do not want to display anything.
    if (scientists.size() > 0){

        size_t longestName = 0;
        size_t longestId = 5;
        // Get the longest name, so we can determine with of columns in table.
        for (size_t i = 0; i < scientists.size(); ++i)
        {

            if (scientists[i].getName().length() > longestName)
                longestName = scientists[i].getName().length();
            if (utils::intToString(scientists[i].getId()).length() > longestId)
                longestId = utils::intToString(scientists[i].getId()).length();
        }

        // longest name cant be shorter than "Name: " (6)
        if (longestName < 6)
            longestName = 6;

        // Labels for table
        cout << setw(longestId+1) << left << "ID:";
        cout << setw(longestName+1) << left << "Name:";
        cout << setw(8) << left << "Gender:";
        cout << setw(7) << left << "Born:";
        cout << setw(7) << left << "Died:";
        cout << "Country:" << endl;

        // Display every scientist from the list
        for(size_t i = 0; i < scientists.size(); i++)
        {

            cout << setw(longestId+1) << left << scientists[i].getId();
            cout << setw(longestName+1) << left << scientists[i].getName();
            cout << setw(8) << left << scientists[i].getGender();
            cout << setw(7) << left << scientists[i].getBirth();
            if (!scientists[i].getDeath())
                cout << setw(7) << left << "Alive";
            else
                cout << setw(7) << left << scientists[i].getDeath();
            cout << scientists[i].getCountry() << endl;      
        }
    }
    cout << "The list contains: " << scientists.size() << " scientists." << endl;
}

void ConsoleUI::_displayComputer(Computer computer){

    size_t nameLenght = computer.getName().length();
    size_t typeLength = computer.getType().length();

    // longest name cant be shorter than "Name: " (6)
    if (nameLenght < 6)
        nameLenght = 6;
    // same for type
    if (typeLength < 6)
        typeLength = 6;

    // Labels for table
    cout << setw(nameLenght+1) << left << "Name:";
    cout << setw(typeLength+1) << left << "Type:";
    cout << setw(13) << left << "Year built:";
    cout << "Built:" << endl;

    cout << setw(nameLenght+1) << left << computer.getName();
    cout << setw(typeLength+1) << left << computer.getType();
    cout << setw(13) << left << computer.getBuildy();
    if (computer.getBuilt()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}

void ConsoleUI::_displayComputers(vector<Computer> computers){

    // If there is no computer in list we do not want to display anything.
    if (computers.size() > 0){

        size_t longestName = 6;
        size_t longestType = 6;
        size_t longestId = 5;
        // Get the longest name, dob, dod, so we can determine with of columns in table.
        for (size_t i = 0; i < computers.size(); ++i)
        {

            if (computers[i].getName().length() > longestName)
                longestName = computers[i].getName().length();
            if (computers[i].getType().length() > longestType)
                longestType = computers[i].getType().length();
            if (utils::intToString(computers[i].getId()).length() > longestId)
                longestId = utils::intToString(computers[i].getId()).length();
        }

        // Labels for table
        cout << setw(longestId+1) << left << "ID:";
        cout << setw(longestName+1) << left << "Name:";
        cout << setw(longestType+1) << left << "Type:";
        cout << setw(13) << left << "Year built:";
        cout << "Built:" << endl;

        // Display every computer from the list
        for(size_t i = 0; i < computers.size(); i++)
        {

            cout << setw(longestId+1) << left << computers[i].getId();
            cout << setw(longestName+1) << left << computers[i].getName();
            cout << setw(longestType+1) << left << computers[i].getType();
            cout << setw(13) << left << computers[i].getBuildy();
            if (computers[i].getBuilt())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    cout << "The list contains: " << computers.size() << " computers." << endl;
}

void ConsoleUI::_displayLinked(vector<Linked> links){

    if (links.size() > 0 ){

        size_t longestComputerName = 15;
        size_t longestComputerId = 13;
        size_t longestScientistName = 16;
        size_t longestScientistId = 14;

        for (size_t i = 0; i < links.size(); i++)
        {
            if(links[i].getComputer().getName().length() > longestComputerName)
                longestComputerName = links[i].getComputer().getName().length();
            if(utils::intToString(links[i].getComputer().getId()).length() > longestComputerId)
                longestComputerId = utils::intToString(links[i].getComputer().getId()).length();
            if(links[i].getScientist().getName().length() > longestScientistName)
                longestScientistName = links[i].getScientist().getName().length();
            if(utils::intToString(links[i].getScientist().getId()).length() > longestScientistId)
                longestScientistId = utils::intToString(links[i].getScientist().getId()).length();
        }

        // Labels for table
        cout << setw(longestScientistId+1) << left << "Scientist ID:";
        cout << setw(longestScientistName+1) << left << "Scientist Name:";
        cout << setw(longestComputerId+1) << left << "Computer ID:";
        cout << setw(longestComputerName+1) << left << "Computer Name:" << endl;

        for (size_t i = 0; i < links.size(); i++)
        {

            cout << setw(longestScientistId+1) << left << links[i].getScientist().getId();
            cout << setw(longestScientistName+1) << left << links[i].getScientist().getName();
            cout << setw(longestComputerId+1) << left << links[i].getComputer().getId();
            cout << setw(longestComputerName+1) << left << links[i].getComputer().getName() << endl;
        }
    }
    cout << "The list contains: " << links.size() << " links of computer and scientist." << endl;
}

void ConsoleUI::_link(){

    int compId;
    int sciId;

    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the computer      ||" << endl;
    cout << "||              you want to link  :             ||" << endl;
    cout << "==================================================" << endl;

    cout << "ID: ";
    cin >> compId;

    while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong input, try again: ";
            std::cin >> compId;
    }

    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the scientist     ||" << endl;
    cout << "||              you want to link  :             ||" << endl;
    cout << "==================================================" << endl;

    cout << "ID: ";
    cin >> sciId;

    while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong input, try again: ";
            std::cin >> sciId;
    }

    if(_service.link(compId,sciId))
        cout << "Successfully linked." << endl;
    else
        cout << "Failed to link." << endl;
}

void ConsoleUI::_unLink() {
    int compId;
    int sciId;

    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the computer      ||" << endl;
    cout << "||              you want to unlink  :           ||" << endl;
    cout << "==================================================" << endl;

    cout << "ID: ";
    cin >> compId;

    while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong input, try again: ";
            std::cin >> compId;
    }

    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the scientist     ||" << endl;
    cout << "||              you want to unlink  :           ||" << endl;
    cout << "==================================================" << endl;

    cout << "ID: ";
    cin >> sciId;

    while(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong input, try again: ";
            std::cin >> sciId;
    }

    if(_service.unLink(compId,sciId))
        cout << "Successfully unlinked." << endl;
    else
        cout << "Failed to unlink." << endl;
}

void ConsoleUI::_clear(){

    string confirm;

    cout << "******************   WARNING   ******************" << endl;
    cout << "*        you are about to clear all data        *" << endl;
    cout << "*                                               *" << endl;
    cout << "*     confirm  - if you want to clear all data  *" << endl;
    cout << "*     cancel   - if you don't want to continue  *" << endl;
    cout << "*                                               *" << endl;
    cout << "******************   WARNING   ******************" << endl;

    do{
        cout << "confirm / cancel: ";
        cin >> confirm;

        if(confirm == "confirm"){

            _service.clearData();
            cout << "All data was erased." << endl;
        }
        else if(confirm == "cancel"){

            cout << "No data was erased." << endl;
        }
    }while(confirm != "confirm" && confirm != "cancel");
}

Scientist ConsoleUI::_createScientist(){

    string name;
    string gender;
    string birth;
    string death;
    string country;
    char charname[100];
    char charcountry[100];
    bool valid;

    cin.ignore();

    do{
        cout << "Name: ";
        cin.getline(charname,sizeof(charname));
        name = string(charname);
        valid = _Valid.nameCheck(name);
        if (!valid) _illegalInput();
    }while(!valid);

    do{
        cout << "Gender (m/f): ";
        cin >> gender;
        valid = _Valid.genderCheck(gender);
        if (!valid) _illegalInput();
    }while(!valid);

    do{
        cin.clear();
        cin.ignore();
        cout << "Year of birth: ";
        cin >> birth;
        valid = _Valid.birthCheck(birth);
        if (!valid) _illegalInput();
    }while(!valid);

    do{
        cin.clear();
        cin.ignore();
        cout << "Year of death (0 if alive): ";
        cin >> death;
        valid = _Valid.deathCheck(death, birth);
        if (!valid) _illegalInput();
    }while(!valid);

    cin.ignore();

    do{
        cout << "Nationality: ";
        cin.getline(charcountry,sizeof(charcountry));
        country = string(charcountry);
        valid = _Valid.nameCheck(country);
        if (!valid) _illegalInput();
    }while(!valid);

    int birthint = atoi(birth.c_str());
    int deathint = atoi(death.c_str());
    return Scientist(name, toupper(gender.at(0)), birthint, deathint, country);
}

Computer ConsoleUI::_createComputer(){

    string cpuname;
    string buildy;
    string type;
    char built;
    char charcpuname[100];
    char charcputype[100];
    bool boolbuilt = false;
    bool valid;

    cin.ignore();

    do{
        cout << "Computer name: ";
        cin.getline(charcpuname,sizeof(charcpuname));
        cpuname = string(charcpuname);
        valid = _Valid.cpuCheck(cpuname);
        if (!valid) _illegalInput();
    }while(!valid);

    do{
        cin.clear();
        cout << "Build year: ";
        cin >> buildy;
        valid = _Valid.buildyCheck(buildy);
        if (!valid) _illegalInput();
    }while(!valid);

    cin.ignore();

    do{
        cout << "Type of computer: ";
        cin.getline(charcputype,sizeof(charcputype));
        type = string(charcputype);
        valid = _Valid.nameCheck(type);
        if (!valid) _illegalInput();
    }while(!valid);

    do{
        cout << "Was the computer built (Y/N)?: ";
        cin >> built;
        built = toupper(built);
        if (built == 'Y')
            boolbuilt = true;
        valid = _Valid.answerCheck(built);
        if (!valid) _illegalInput();
    }while(!valid);

    int buildyint = atoi(buildy.c_str());

    return Computer(cpuname, buildyint, type, boolbuilt);
}

void ConsoleUI::_illegalInput(){

    cout << "Illegal input. Please try again!" << endl;
}
