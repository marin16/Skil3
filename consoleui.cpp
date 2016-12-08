#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

#include "consoleui.h"
#include "person.h"
#include "computer.h"
#include "utilities.h"
#include "linked.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}


void ConsoleUI::run()
{
    bool separate = false;
    _instructions();
    do
    {
        if (separate) {
            cout << endl;
        }
        separate = true;

        cout << "Command: ";
        string command;
        cin >> command;

        if(command == "add-c")
        {
            _addCPU();
        }
        else if(command == "search-c")
        {
            _searchCPU();
        }
        else if(command == "list-c")
        {
            _listCPU();
        }
        else if(command == "delete-c")
        {
            _deleteCPU();
        }
        else if(command == "edit-c")
        {
            _editComputer();
        }
        else if(command == "add-s")
        {
            _add();
        }
        else if(command == "search-s")
        {
            _search();
        }
        else if(command == "list-s")
        {
            _listScientists();
        }
        else if(command == "delete-s")
        {
            _delete();
        }
        else if(command == "edit-s")
        {
            _edit();
        }
        else if(command == "link")
        {
            _link();
        }
        else if(command == "list")
        {
            _list();
        }
        else if(command == "help")
        {
            _instructions();
            separate = false;
        }
        else if(command == "clear")
        {
            _clear();
        }
        else if(command == "quit" || command == "q" || command == "exit")
        {
            break;
        }
        else
        {
            cout << "Unknown command: " << command << endl;
            cout << "please try again or write \"help\" for a list of commands." << endl;
            separate = false;
        }
    }while(true);
}

/*
 * _instructions(): prints out instructions for the user informing him of what commands he has available.
 */
void ConsoleUI::_instructions()
{
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
    cout << "||    add-s    - to add a new person                    ||" << endl;
    cout << "||    list-s   - to get a list of scientsits            ||" << endl;
    cout << "||    search-s - to search for scientist                ||" << endl;
    cout << "||    edit-s   - to edit an scientist                   ||" << endl;
    cout << "||    delete-s - to delete a scientist                  ||" << endl;
    cout << "||                                                      ||" << endl;
    cout << "||    link     - to link scientist and computer         ||" << endl;
    cout << "||    list     - to get linked scientists and computers ||" << endl;
    cout << "||    clear    - to clear all data                      ||" << endl;
    cout << "||    help     - to view this again                     ||" << endl;
    cout << "||    quit     - to exit program                        ||" << endl;
    cout << "||                                                      ||" << endl;
    cout << "==========================================================" << endl;
}

/*
 * _add: Takes user input and adds to vector
 */
void ConsoleUI::_add()
{
    char answer;

    cout << "=======================================================" << endl;
    cout << "||Please add the parameters for the scientists       ||" << endl;
    cout << "||if you input invalid data you will be asked again. ||" << endl;
    cout << "=======================================================" << endl;

    Person newPerson = _createPerson();

    do
    {
        _displayPerson(newPerson);
        cout << "Is the information correct?(Y/N) ";
        cin >> answer;
    }while(!_Valid.answerCheck(answer));

    if (answer == 'y' || answer == 'Y')
    {
        cin.ignore();
        if (_service.addPerson(newPerson))
        {
            cout << "Success!" << endl;
        }
        else
        {
            cout << "Could not write this data to the database." << endl;
        }
    }
    else if (answer == 'n' || answer == 'N')
    {
        cin.ignore();
        _add();
    }
}

/*
 * _add: Takes user input and adds to vector
 */
void ConsoleUI::_addCPU()
{
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

    if (answer == 'y' || answer == 'Y')
    {
        cin.ignore();
        if (_service.addComputer(newComputer))
            cout << "Success!" << endl;
        else
            cout << "Could not write this data to the database" << endl;
    }
    else if (answer == 'n' || answer == 'N')
    {
        cin.ignore();
        _addCPU();
    }
}

/*
 * _search: search scientists based on user's input
 */
void ConsoleUI::_search()
{
    vector<Person> results;
    string search;
    char charsearch[100];

    cout << "Value: ";
    cin.ignore();
    cin.getline(charsearch,sizeof(charsearch));
    search = string(charsearch);

    results = _service.searchForPerson(search);

    _displayPersons(results);
}

/*
 * _search: search computers based on user's input
 */

void ConsoleUI::_searchCPU()
{
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

/*
 * _delete: deletes from list
 */
void ConsoleUI::_delete()
{
    int delId;

    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the scientist     ||" << endl;
    cout << "||              you what to delete:             ||" << endl;
    cout << "==================================================" << endl;

    cout << "ID: ";
    cin >> delId;

    if(_service.deletePerson(delId))
        cout << "Success!" << endl;
    else
        cout << "Failed." << endl;
}

/*
 * _delete: deletes from list
 */
void ConsoleUI::_deleteCPU()
{
    int delId;

    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the computer      ||" << endl;
    cout << "||              you what to delete:             ||" << endl;
    cout << "==================================================" << endl;

    cout << "ID: ";
    cin >> delId;

    if(_service.deleteComputer(delId))
        cout << "Success!" << endl;
    else
        cout << "Failed." << endl;
}

/*
 * _list: Displays menu of scientists for list. Displays list based on user's input.
 */
void ConsoleUI::_listScientists()
{
    cout << "==============================================================" << endl;
    cout << "||        Please enter one of the following commands:       ||" << endl;
    cout << "==============================================================" << endl;
    cout << "||    name-asc      - sort by name alphabeticaly ascending  ||" << endl;
    cout << "||    birth-asc     - sort by year of birth ascending       ||" << endl;
    cout << "||    death-asc     - sort by year of death ascending       ||" << endl;
    cout << "||    country-asc   - sort by nationality ascending         ||" << endl;
    cout << "||    name-desc     - sort by name alphabeticaly descending ||" << endl;
    cout << "||    birth-desc    - sort by year of birth descending      ||" << endl;
    cout << "||    death-desc    - sort by year of birth descending      ||" << endl;
    cout << "||    country-desc  - sort by nationality descending        ||" << endl;
    cout << "||    unsorted      - get unsorted list (default)           ||" << endl;
    cout << "==============================================================" << endl;

    string sort;
    cin >> sort;
    vector<Person> persons;

    if (sort == "name-asc")
        persons = _service.getPersons(1);
    else if (sort == "birth-asc")
        persons = _service.getPersons(2);
    else if (sort == "death-asc")
        persons = _service.getPersons(3);
    else if (sort == "country-asc")
        persons = _service.getPersons(4);
    else if (sort == "name-desc")
        persons = _service.getPersons(5);
    else if (sort == "birth-desc")
        persons = _service.getPersons(6);
    else if (sort == "death-desc")
        persons = _service.getPersons(7);
    else if (sort == "country-desc")
        persons = _service.getPersons(8);
    else
        persons = _service.getPersons(0);

    _displayPersons(persons);
}

/*
 * _list: Displays menu of computers for list. Displays list based on user's input.
 */
void ConsoleUI::_listCPU()
{
    cout << "=================================================================" << endl;
    cout << "||         Please enter one of the following commands:         ||" << endl;
    cout << "=================================================================" << endl;
    cout << "||    name-asc      - sort by name alphabeticaly ascending     ||" << endl;
    cout << "||    buildy-asc    - sort by built year ascending             ||" << endl;
    cout << "||    type-asc      - sort by type ascending                   ||" << endl;
    cout << "||    name-desc     - sort by name alphabeticaly descending    ||" << endl;
    cout << "||    buildy-desc   - sort by built year descending            ||" << endl;
    cout << "||    type-desc     - sort by type descending                  ||" << endl;
    cout << "||    unsorted      - get unsorted list (default)              ||" << endl;
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

void ConsoleUI::_list()
{
    vector<Linked> links;
    cout << "============================================================================" << endl;
    cout << "||              Please enter one of the following commands:               ||" << endl;
    cout << "============================================================================" << endl;
    cout << "||    computer-asc      - sort by computer name alphabeticaly ascending   ||" << endl;
    cout << "||    scientist-asc     - sort by scientist nameyear ascending            ||" << endl;
    cout << "||    computer-desc     - sort by computer name alphabeticaly descending  ||" << endl;
    cout << "||    scientist-desc    - sort by scientist nameyear descending           ||" << endl;
    cout << "||    unsorted          - get unsorted list (default)                     ||" << endl;
    cout << "============================================================================" << endl;

    string sort;
    cin >> sort;

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

/*
 * _edit: edits a pearson
 */
void ConsoleUI::_edit()
{
    int editId;
    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the scientist     ||" << endl;
    cout << "||              you what to delete:             ||" << endl;
    cout << "==================================================" << endl;
    cout << "ID: ";
    cin >> editId;

    if(_service.editPerson(editId,_createPerson()))
        cout << "Person successfully edited." << endl;
    else
        cout << "Failed." << endl;
}

void ConsoleUI::_editComputer()
{
    int editId;
    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the computer      ||" << endl;
    cout << "||              you what to delete:             ||" << endl;
    cout << "==================================================" << endl;
    cout << "ID: ";
    cin >> editId;

    if(_service.editComputer(editId,_createComputer()))
        cout << "Computer successfully edited." << endl;
    else
        cout << "Failed." << endl;
}

/*
 * _displayPerson: Displays one person
 */
void ConsoleUI::_displayPerson(Person person)
{
    size_t nameLength = person.getName().length();

    // nameLength cant be shorter than "Name: " (6)
    if (nameLength < 6)
        nameLength = 6;

    // Labels
    cout << setw(nameLength+1) << left << "Name:";
    cout << setw(8) << left << "Gender:";
    cout << setw(7) << left << "Born:";
    cout << setw(7) << left << "Died:";
    cout << "Country:" << endl;

    // Print the person
    cout << setw(nameLength+1) << left << person.getName();
    cout << setw(8) << left << person.getGender();
    cout << setw(7) << left << person.getBirth();
    cout << setw(7) << left << person.getDeath();
    cout << person.getCountry() << endl;
}

/*
 * _displayPersons: Displays multiple persons
 */
void ConsoleUI::_displayPersons(vector<Person> persons)
{
    // If there is no person in list we do not want to display anything.
    if (persons.size() > 0)
    {
        size_t longestName = 0;
        size_t longestId = 5;
        // Get the longest name, so we can determine with of columns in table.
        for (size_t i = 0; i < persons.size(); ++i)
        {
            if (persons[i].getName().length() > longestName)
                longestName = persons[i].getName().length();
            if (utils::intToString(persons[i].getId()).length() > longestId)
                longestId = utils::intToString(persons[i].getId()).length();
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

        // Display every person from the list
        for(size_t i = 0; i < persons.size(); i++)
        {
            cout << setw(longestId+1) << left << persons[i].getId();
            cout << setw(longestName+1) << left << persons[i].getName();
            cout << setw(8) << left << persons[i].getGender();
            cout << setw(7) << left << persons[i].getBirth();
            cout << setw(7) << left << persons[i].getDeath();
            cout << persons[i].getCountry() << endl;
        }
    }
    cout << "The list contains: " << persons.size() << " scientists." << endl;
}

void ConsoleUI::_displayComputer(Computer computer)
{
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
    cout << computer.getBuilt() << endl;
}

/*
 * _displayPersons: Displays multiple persons
 */
void ConsoleUI::_displayComputers(vector<Computer> computers)
{
    // If there is no computer in list we do not want to display anything.
    if (computers.size() > 0)
    {
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

        // Display every person from the list
        for(size_t i = 0; i < computers.size(); i++)
        {
            cout << setw(longestId+1) << left << computers[i].getId();
            cout << setw(longestName+1) << left << computers[i].getName();
            cout << setw(longestType+1) << left << computers[i].getType();
            cout << setw(13) << left << computers[i].getBuildy();
            cout << computers[i].getBuilt() << endl;
        }
    }
    cout << "The list contains: " << computers.size() << " computers." << endl;
}

void ConsoleUI::_displayLinked(vector<Linked> links)
{
    if (links.size() > 0 )
    {
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
            if(links[i].getPerson().getName().length() > longestScientistName)
                longestScientistName = links[i].getComputer().getName().length();
            if(utils::intToString(links[i].getPerson().getId()).length() > longestScientistId)
                longestScientistId = utils::intToString(links[i].getPerson().getId()).length();
        }

        // Labels for table
        cout << setw(longestScientistId+1) << left << "Scientist ID:";
        cout << setw(longestScientistName+1) << left << "Scientist Name:";
        cout << setw(longestComputerId+1) << left << "Computer ID:";
        cout << setw(longestComputerName+1) << left << "Computer Name:" << endl;

        for (size_t i = 0; i < links.size(); i++)
        {
            cout << setw(longestScientistId+1) << left << links[i].getPerson().getId();
            cout << setw(longestScientistName+1) << left << links[i].getPerson().getName();
            cout << setw(longestComputerId+1) << left << links[i].getComputer().getId();
            cout << setw(longestComputerName+1) << left << links[i].getComputer().getName() << endl;
        }
    }
    cout << "The list contains: " << links.size() << " links of computer and scientist." << endl;
}

void ConsoleUI::_link()
{
    int compId;
    int sciId;
    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the computer      ||" << endl;
    cout << "||              you what to link  :             ||" << endl;
    cout << "==================================================" << endl;
    cout << "ID: ";
    cin >> compId;
    cout << "==================================================" << endl;
    cout << "||     Please enter the ID of the scientist     ||" << endl;
    cout << "||              you what to link  :             ||" << endl;
    cout << "==================================================" << endl;
    cout << "ID: ";
    cin >> sciId;

    if(_service.link(compId,sciId))
        cout << "Successfully linked." << endl;
    else
        cout << "Failed to link." << endl;
}

/*
 * _clear: Clears the data from the list of scientists
 */
void ConsoleUI::_clear()
{
    string confirm;
    cout << "******************   WARNING   ******************" << endl;
    cout << "*        you are about to clear all data        *" << endl;
    cout << "*                                               *" << endl;
    cout << "*     confirm  - if you want to clear all data  *" << endl;
    cout << "*     cancel   - if you dont want to continue   *" << endl;
    cout << "*                                               *" << endl;
    cout << "******************   WARNING   ******************" << endl;
    do{
        cout << "confirm / cancel: ";
        cin >> confirm;
        if(confirm == "confirm")
        {
            _service.clearData();
            cout << "All data was erased." << endl;
        }
        else if(confirm == "cancel")
        {
            cout << "No data was erased." << endl;
        }
    }while(confirm != "confirm" && confirm != "cancel");
}

Person ConsoleUI::_createPerson()
{
    string name;
    char gender;
    string birth;
    string death;
    string country;
    char charname[100];
    char charcountry[100];

    do
    {
        cout << "Name: ";
        cin.ignore();
        cin.getline(charname,sizeof(charname));
        name = string(charname);
    }while(!_Valid.nameCheck(name));

    do
    {
        cout << "Gender (m/f): ";
        cin >> gender;
        gender = toupper(gender);
    }while(!_Valid.genderCheck(gender));

    do
    {
        cin.clear();
        cin.ignore();
        cout << "Year of birth: ";
        cin >> birth;
    }while(!_Valid.birthCheck(birth));

    do
    {
        cin.clear();
        cin.ignore();
        cout << "Year of death (0 if alive): ";
        cin >> death;
    }while(!_Valid.deathCheck(death, birth));

    do
    {
        cout << "Nationality: ";
        cin.ignore();
        cin.getline(charcountry,sizeof(charcountry));
        country = string(charcountry);
    }while(!_Valid.nameCheck(country));

    int birthint = atoi(birth.c_str());
    int deathint = atoi(death.c_str());
    return Person(name, gender, birthint, deathint, country);
}

Computer ConsoleUI::_createComputer()
{
    string cpuname;
    string buildy;
    string type;
    char built;
    char charcpuname[100];
    char charcputype[100];
    bool boolbuilt = false;

    do
    {
        cout << "Computer name: ";
        cin.ignore();
        cin.getline(charcpuname,sizeof(charcpuname));
        cpuname = string(charcpuname);
    }while(!_Valid.cpuCheck(cpuname));

    do
    {
        cin.clear();
        //cin.ignore();
        cout << "Build year: ";
        cin >> buildy;
    }while(!_Valid.buildyCheck(buildy));

    do
    {
        cout << "Type of computer: ";
        cin.ignore();
        cin.getline(charcputype,sizeof(charcputype));
        type = string(charcputype);
    }while(!_Valid.nameCheck(type));

    do
    {
        cout << "Was the computer built (Y/N)?: ";
        cin >> built;
        built = toupper(built);
        if (built == 'Y')
            boolbuilt = true;
    }while(!_Valid.answerCheck(built));

    int buildyint = atoi(buildy.c_str());
    return Computer(cpuname, buildyint, type, boolbuilt);
}
