#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

#include "consoleui.h"
#include "person.h"
#include "computer.h"

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
            //_edit();
        }
        if(command == "add-s")
        {
            _add();
        }
        else if(command == "search-s")
        {
            _search();
        }
        else if(command == "list-s")
        {
            _list();
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
            //_link();
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

void ConsoleUI::_instructions()
{
    cout << "===================================================" << endl;
    cout << "||  Please enter one of the following commands:  ||" << endl;
    cout << "===================================================" << endl;
    cout << "||                                               ||" << endl;
    cout << "||    add-c    - to add a new computer           ||" << endl;
    cout << "||    list-c   - to get a list of computers      ||" << endl;
    cout << "||    search-c - to search for computer          ||" << endl;
    cout << "||    edit-c   - to edit an computer             ||" << endl;
    cout << "||    delete-c - to delete a computer            ||" << endl;
    cout << "||                                               ||" << endl;
    cout << "||    add-s    - to add a new person             ||" << endl;
    cout << "||    list-s   - to get a list of scientsits     ||" << endl;
    cout << "||    search-s - to search for scientist         ||" << endl;
    cout << "||    edit-s   - to edit an scientist            ||" << endl;
    cout << "||    delete-s - to delete a scientist           ||" << endl;
    cout << "||                                               ||" << endl;
    cout << "||    link     - to link scientist and computer  ||" << endl;
    cout << "||    clear    - to clear all data               ||" << endl;
    cout << "||    help     - to view this again              ||" << endl;
    cout << "||    quit     - to exit program                 ||" << endl;
    cout << "||                                               ||" << endl;
    cout << "===================================================" << endl;
}

/*
 * _add: Takes user input and adds to vector
 */
void ConsoleUI::_add()
{
    string name;
    char gender;
    string birth;
    string death;
    string country;
    char charname[100];
    char charcountry[100];
    char answer;


    cout << "=======================================================" << endl;
    cout << "||Please add the parameters for the scientists       ||" << endl;
    cout << "||if you input invalid data you will be asked again. ||" << endl;
    cout << "=======================================================" << endl;


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
    Person newPerson(name, gender, birthint, deathint, country);

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
            cout << "Could not write this data to database" << endl;
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
    string cpuname;
    string buildy;
    string type;
    char built;
    char charcpuname[100];
    char charcputype[100];
    char answer;
    bool boolbuilt = false;

    cout << "=======================================================" << endl;
    cout << "||Please add the parameters for the computer         ||" << endl;
    cout << "||if you input invalid data you will be asked again. ||" << endl;
    cout << "=======================================================" << endl;


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
    Computer newComputer(cpuname, buildyint, type, boolbuilt);

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
    string searchBy;
    string search;
    char charsearch[100];

    cout << "=================================================" << endl;
    cout << "||             Enter search parameter:         ||" << endl;
    cout << "=================================================" << endl;
    cout << "||   name    - to search by full name          ||" << endl;
    cout << "||   gender  - to search by gender             ||" << endl;
    cout << "||   birth   - to search by year of birth      ||" << endl;
    cout << "||   death   - to search by year of death      ||" << endl;
    cout << "||   country - to search by country of origin  ||" << endl;
    cout << "=================================================" << endl;

    do{
        cout << "Parameter: ";
        cin >> searchBy;
    }while(searchBy != "name" && searchBy != "gender" && searchBy != "birth" && searchBy != "death" && searchBy != "country");

    cout << "Value: ";

    cin.ignore();
    cin.getline(charsearch,sizeof(charsearch));
    search = string(charsearch);

    results = _service.searchForPerson(search, searchBy);

    _displayPersons(results);
}

/*
 * _search: search computers based on user's input
 */

void ConsoleUI::_searchCPU()
{
    vector<Computer> results;
    string searchBy;
    string search;
    char charsearch[100];

    cout << "=================================================" << endl;
    cout << "||             Enter search parameter:         ||" << endl;
    cout << "=================================================" << endl;
    cout << "||   name    - to search by full name          ||" << endl;
    cout << "||   type    - to search by typer              ||" << endl;
    cout << "||   buildy  - to search by built year         ||" << endl;
    cout << "=================================================" << endl;

    do{
        cout << "Parameter: ";
        cin >> searchBy;
    }while(searchBy != "name" && searchBy != "type" && searchBy != "buildy");

    cout << "Value: ";

    cin.ignore();
    cin.getline(charsearch,sizeof(charsearch));
    search = string(charsearch);

    results = _service.searchForComputer(search, searchBy);

    _displayComputers(results);
}

/*
 * _delete: deletes from list
 */
void ConsoleUI::_delete()
{
    bool deleteResult;
    string deleteP;
    char chardeleteP[100];

    cout << "=================================================" << endl;
    cout << "||     Please enter a full name to delete:     ||" << endl;
    cout << "=================================================" << endl;

    cout << "Name: ";
    cin.ignore();
    cin.getline(chardeleteP,sizeof(chardeleteP));
    deleteP = string(chardeleteP);

    deleteResult = _service.deletePerson(deleteP);

    if(deleteResult)
    {
        cout << "Success!" << endl;
    }
    else
    {
        cout << "Failed. (nothing found to delete or multiple results found)" << endl;
    }
}

/*
 * _delete: deletes from list
 */
void ConsoleUI::_deleteCPU()
{
    bool deleteResult;
    string deleteC;
    char chardeleteC[100];

    cout << "=================================================" << endl;
    cout << "||     Please enter a cpu name to delete:      ||" << endl;
    cout << "=================================================" << endl;

    cout << "Name: ";
    cin.ignore();
    cin.getline(chardeleteC,sizeof(chardeleteC));
    deleteC = string(chardeleteC);

    deleteResult = _service.deleteComputer(deleteC);

    if(deleteResult)
    {
        cout << "Success!" << endl;
    }
    else
    {
        cout << "Failed. (nothing found to delete or multiple results found)" << endl;
    }
}

/*
 * _list: Displays menu of scientists for list. Displays list based on user's input.
 */
void ConsoleUI::_list()
{
    cout << "=================================================" << endl;
    cout << "|| Please enter one of the following commands: ||" << endl;
    cout << "=================================================" << endl;
    cout << "||    name     - sort by name alphabeticaly    ||" << endl;
    cout << "||    year     - sort by year of birth         ||" << endl;
    cout << "||    country  - sort by nationality           ||" << endl;
    cout << "||    unsorted - get unsorted list (default)   ||" << endl;
    cout << "=================================================" << endl;

    string sort;
    cin >> sort;
    vector<Person> persons;

    if (sort == "name")
        persons = _service.getPersons(1);
    else if (sort == "year")
        persons = _service.getPersons(2);
    else if (sort == "country")
        persons = _service.getPersons(3);
    else //if (sort == "unsorted")
        persons = _service.getPersons(0);

    _displayPersons(persons);
}

/*
 * _list: Displays menu of computers for list. Displays list based on user's input.
 */
void ConsoleUI::_listCPU()
{
    cout << "=================================================" << endl;
    cout << "|| Please enter one of the following commands: ||" << endl;
    cout << "=================================================" << endl;
    cout << "||    name     - sort by name alphabeticaly    ||" << endl;
    cout << "||    buildy   - sort by built year            ||" << endl;
    cout << "||    type     - sort by type                  ||" << endl;
    cout << "||    unsorted - get unsorted list (default)   ||" << endl;
    cout << "=================================================" << endl;

    string sort;
    cin >> sort;
    vector<Computer> computers;

    if (sort == "name")
        computers = _service.getComputers(1);
    else if (sort == "buildy")
        computers = _service.getComputers(2);
    else if (sort == "type")
        computers = _service.getComputers(3);
    else //if (sort == "unsorted")
        computers = _service.getComputers(0);

    _displayComputers(computers);
}

/*
 * _edit: edits a pearson
 */
void ConsoleUI::_edit()
{
    Person newPerson;
    vector<Person> results;
    bool deleteResult;
    string deleteP;
    char chardeleteP[100];
    string name;
    char gender;
    string birth;
    string death;
    string country;
    char charname[100];
    char charcountry[100];
    char answer;

    cout << "=================================================" << endl;
    cout << "||      Please enter a full name to edit:      ||" << endl;
    cout << "=================================================" << endl;
    cout << "Name: ";
    cin.ignore();
    cin.getline(chardeleteP,sizeof(chardeleteP));
    deleteP = string(chardeleteP);

    results = _service.searchForPerson(deleteP, "name");
    deleteResult = _service.deletePerson(deleteP);

    if(deleteResult)
    {
        Person orgPers = results[0];
        string edit;
        cout << "=================================================" << endl;
        cout << "||            Enter parameter to edit:         ||" << endl;
        cout << "=================================================" << endl;
        cout << "||   name    - to edit name                    ||" << endl;
        cout << "||   gender  - to edit gender                  ||" << endl;
        cout << "||   birth   - to edit year of birth           ||" << endl;
        cout << "||   death   - to edit year of death           ||" << endl;
        cout << "||   country - to edit Nationality             ||" << endl;
        cout << "=================================================" << endl;
        do
        {
            cout << "Value: ";
            cin >> edit;
        }while(edit != "name" && edit != "gender" && edit != "birth" && edit != "death" && edit != "country");

        if(edit == "name")
        {
            do
            {
                cout << "Name: ";
                cin.ignore();
                cin.getline(charname,sizeof(charname));
                name = string(charname);
            }while(!_Valid.nameCheck(name));
            newPerson = Person(name, orgPers.getGender(), orgPers.getBirth(), orgPers.getDeath(), orgPers.getCountry());
        }
        else if(edit == "gender")
        {
            do
            {
                cout << "Gender (m/f): ";
                cin >> gender;
                gender = toupper(gender);
            }while(!_Valid.genderCheck(gender));
            newPerson = Person(orgPers.getName(), gender, orgPers.getBirth(), orgPers.getDeath(), orgPers.getCountry());
        }
        else if(edit == "birth" || edit == "death")
        {
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
            int birthint = atoi(birth.c_str());
            int deathint = atoi(death.c_str());
            newPerson = Person(orgPers.getName(), orgPers.getGender(), birthint, deathint, orgPers.getCountry());

        }
        else if(edit == "country")
        {
            do
            {
                cout << "Nationality: ";
                cin.ignore();
                cin.getline(charcountry,sizeof(charcountry));
                country = string(charcountry);
            }while(!_Valid.nameCheck(country));
            newPerson = Person(orgPers.getName(), orgPers.getGender(), orgPers.getBirth(), orgPers.getDeath(), country);
         }
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
                cout << "Success!" << endl;
            else
                cout << "Could not write this data to file" << endl;
        }
        else if (answer == 'n' || answer == 'N')
        {
            cin.ignore();
            _add();
        }
    }
    else
    {
        cout << "Failed. (nothing found to edit or multiple results found)" << endl;
    }
}

/*
 * _displayPerson: Displays one person
 */
void ConsoleUI::_displayPerson(Person person)
{
    size_t nameLength = person.getName().length();

    // nameLength cant be shorter than "Name: " (6)
    if (nameLength < 6)
        nameLength == 6;

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
    if (persons.size() > 0) {
        size_t longestName = 0;
        // Get the longest name, dob, dod, so we can determine with of columns in table.
        for (size_t i = 0; i < persons.size(); ++i)
        {
            if (persons[i].getName().length() > longestName)
                longestName = persons[i].getName().length();
        }

        // longest name cant be shorter than "Name: " (6)
        if (longestName < 6)
            longestName == 6;

        // Labels for table
        cout << setw(longestName+1) << left << "Name:";
        cout << setw(8) << left << "Gender:";
        cout << setw(7) << left << "Born:";
        cout << setw(7) << left << "Died:";
        cout << "Country:" << endl;

        // Display every person from the list
        for(size_t i = 0; i < persons.size(); i++)
        {
            cout << setw(longestName+1) << left << persons[i].getName();
            cout << setw(8) << left << persons[i].getGender();
            cout << setw(7) << left << persons[i].getBirth();
            cout << setw(7) << left << persons[i].getDeath();
            cout << persons[i].getCountry() << endl;
        }
    }
}

void ConsoleUI::_displayComputer(Computer computers)
{

}

/*
 * _displayPersons: Displays multiple persons
 */
void ConsoleUI::_displayComputers(vector<Computer> computers)
{

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
