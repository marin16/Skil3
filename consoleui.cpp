#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>

#include "consoleui.h"
#include "person.h"
#include "computer.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}


void ConsoleUI::run()
{
    string oneTwo;
    _instructions();

    do
    {
        cout << "Command: ";
        cin >> oneTwo;

        if(oneTwo == "1")
        {
            runCom();
        }
        else if(oneTwo == "2")
        {
            runSci();
        }
        else if(oneTwo == "3")
        {
            //runCon();
        }
        else if(oneTwo == "4")
        {
            break;
        }
        else
        {
            cout << "Wrong input, please try again!" << endl;
        }
    }while(oneTwo != "1" && oneTwo != "2");
}

void ConsoleUI::runCom()
{
    bool separate = false;
    _computers();
    do
    {
        if (separate) {
            cout << endl;
        }
        separate = true;

        cout << "Command: ";
        string command;
        cin >> command;

        if(command == "add")
        {
            _addCPU();
        }
        else if(command == "search")
        {
            _searchCPU();
        }
        else if(command == "list")
        {
            _listCPU();
        }
        else if(command == "delete")
        {
            _deleteCPU();
        }
        else if(command == "edit")
        {
            //_edit();
        }
        else if(command == "help")
        {
            _computers();
            separate = false;
        }
        else if(command == "clear")
        {
            _clearCPU();
        }
        else if(command == "main")
        {
            run();
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

void ConsoleUI::runSci()
{
	bool separate = false;
    _scientists();
    do
    {
		if (separate) {
			cout << endl;
		}
		separate = true;

        cout << "Command: ";
        string command;
        cin >> command;

        if(command == "add")
        {
            _add();
        }
        else if(command == "search")
        {
            _search();
        }
        else if(command == "list")
        {
            _list();
        }
        else if(command == "delete")
        {
            _delete();
        }
        else if(command == "edit")
        {
            _edit();
        }
        else if(command == "help")
        {
            _scientists();
			separate = false;
        }
        else if(command == "clear")
        {
            _clear();
        }
        else if(command == "main")
        {
            run();
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
    cout << "=================================================" << endl;
    cout << "|| Please enter one of the following commands: ||" << endl;
    cout << "=================================================" << endl;
    cout << "=================================================" << endl;
    cout << "||       1 - to view the Computers menu        ||" << endl;
    cout << "||       2 - to view the Scientists menu       ||" << endl;
    cout << "||       3 - to link scientist and computer    ||" << endl;
    cout << "||       4 - to quit the program               ||" << endl;
    cout << "=================================================" << endl;
}


void ConsoleUI::_computers()
{
    cout << "=================================================" << endl;
    cout << "||              Famous Computers               ||" << endl;
    cout << "|| Please enter one of the following commands: ||" << endl;
    cout << "=================================================" << endl;
    cout << "||    add    - to add a new computer           ||" << endl;
    cout << "||    list   - to get a list of computers      ||" << endl;
    cout << "||    search - to search list                  ||" << endl;
    cout << "||    help   - to view this again              ||" << endl;
    cout << "||    edit   - to edit an entry                ||" << endl;
    cout << "||    delete - to delete a computer            ||" << endl;
    cout << "||    clear  - to clear all data               ||" << endl;
    cout << "||    main   - to go to main menu              ||" << endl;
    cout << "||    quit   - to exit program                 ||" << endl;
    cout << "=================================================" << endl;
}


/*
 * _instructions: Display instructions menu
 */
void ConsoleUI::_scientists()
{
    cout << "=================================================" << endl;
    cout << "||             Computer Scientists             ||" << endl;
    cout << "|| Please enter one of the following commands: ||" << endl;
    cout << "=================================================" << endl;
    cout << "||    add    - to add a new person             ||" << endl;
    cout << "||    list   - to get a list of scientsits     ||" << endl;
    cout << "||    search - to search list                  ||" << endl;
    cout << "||    help   - to view this again              ||" << endl;
    cout << "||    edit   - to edit an entry                ||" << endl;
    cout << "||    delete - to delete a scientist           ||" << endl;
    cout << "||    clear  - to clear all data               ||" << endl;
    cout << "||    main   - to go to main menu              ||" << endl;
    cout << "||    quit   - to exit program                 ||" << endl;
    cout << "=================================================" << endl;
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
    }while(!_Valid.nameCheck(cpuname));

    do
    {
        cin.clear();
        //cin.ignore();
        cout << "Built year: ";
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
	const int offset = 4;
    cout << "Name:" << string(max(int(offset), int((person.getName().length() - 5) + offset)), ' ')
		 << "Gender:" << string(offset, ' ')
		 << "Birth:" << string(offset, ' ');
	if (person.getDeath() != 0) {
		cout << "Death:" << string(offset, ' ');
	}
	cout << "Nationality:" << endl;

	cout << person.getName() << string(max(int(offset), int((5 - person.getName().length()) + offset)), ' ');
	// Properly prints the gender
	cout << (person.getGender() == 'M' ? "Male   " : "Female ") << string(offset, ' ');
	// Uses a logarithm to calculate the spacing
	cout << person.getBirth() << string(offset+(5-int(log10(person.getBirth()))), ' ');
	if (person.getDeath() != 0) {
		cout << person.getDeath() << string(offset+(5-int(log10(person.getDeath()))), ' ');
	}
	cout << person.getCountry() << endl;
}

void ConsoleUI::_displayComputer(Computer computer)
{
    const int offset = 4;
    cout << "Name:" << string(max(int(offset), int((computer.getName().length() - 5) + offset)), ' ')
         << "Built year:" << string(offset, ' ')
         << "Type:" << string(offset, ' ');
    cout << "Built:" << endl;

    cout << computer.getName() << string(max(int(offset), int((5 - computer.getName().length()) + offset)), ' ');
    cout << computer.getbuildy() << string(offset+(5-int(log10(computer.getbuildy()))), ' ');
    cout << computer.getType() << string(max(int(offset), int((5 - computer.getType().length()) + offset)), ' ');
    // Properly prints build status
    cout << (computer.getBuilt() == 0 ? "No     " : "Yes    ") << string(offset, ' ') << endl;
}

/*
 * _displayPersons: Displays multiple persons
 */
void ConsoleUI::_displayPersons(vector<Person> persons)
{
	if (persons.size() > 0) {
		size_t longestName = 0;
		bool hasDeadPerson = false;
		for (size_t i = 0; i < persons.size(); ++i) {
			if (persons[i].getName().length() > longestName) {
				longestName = persons[i].getName().length();
			}
			hasDeadPerson |= persons[i].getDeath() != 0;
		}

		const int offset = 4;
		cout << "Name:" << string(max(int(offset), int((longestName - 5) + offset)), ' ')
			 << "Gender:" << string(offset, ' ')
			 << "Birth:" << string(offset, ' ');
		if (hasDeadPerson) {
			cout << "Death:" << string(offset, ' ');
		}
		cout << "Nationality:" << endl;

		for (size_t i = 0; i < persons.size(); ++i) {

			cout << persons[i].getName() << string(max(int(offset), int((longestName - persons[i].getName().length()) + offset)), ' ');
			// Properly prints the gender
            cout << (persons[i].getGender() == 'M' ? "Male   " : "Female ") << string(offset, ' ');
			// Uses a logarithm to calculate the spacing
			cout << persons[i].getBirth() << string(offset+(5-int(log10(max(1, persons[i].getBirth())))), ' ');
			if (hasDeadPerson) {
				if (persons[i].getDeath() == 0) {
					cout << string(offset + 6, ' ');
				} else {
					cout << persons[i].getDeath() << string(offset+(5-int(log10(persons[i].getDeath()))), ' ');
				}
			}
			cout << persons[i].getCountry() << endl;

		}
	}
	cout << "The list contains: " << persons.size() << " scientists." << endl;
}

/*
 * _displayPersons: Displays multiple persons
 */
void ConsoleUI::_displayComputers(vector<Computer> computers)
{
    if (computers.size() > 0) {
        size_t longestName = 0;
        bool wasBuilt = false;
        for (size_t i = 0; i < computers.size(); ++i) {
            if (computers[i].getName().length() > longestName) {
                longestName = computers[i].getName().length();
            }
            wasBuilt |= computers[i].getBuilt() != 0;
        }

        const int offset = 4;
        cout << "Name:" << string(max(int(offset), int((longestName - 5) + offset)), ' ')
             << "Type" << string(offset, ' ');
        if (wasBuilt) {
            cout << "Built in the year:" << string(offset, ' ');
        }
        else {
            cout << "Was not built!" << string(offset, ' ');
        }

        for (size_t i = 0; i < computers.size(); ++i) {

            cout << computers[i].getName() << string(max(int(offset), int((longestName - computers[i].getName().length()) + offset)), ' ');
            cout << computers[i].getType() << string(max(int(offset), int((5 - computers[i].getType().length()) + offset)), ' ');
            // Uses a logarithm to calculate the spacing
            if (wasBuilt) {
                if (computers[i].getBuilt() == 0) {
                    cout << string(offset + 6, ' ');
                } else {
                    cout << computers[i].getbuildy() << string(offset+(5-int(log10(computers[i].getbuildy()))), ' ');
                }
            }
            cout << endl;
        }
    }
    cout << "The list contains: " << computers.size() << " computers." << endl;
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

/*
 * _clear: Clears the data from the list of computers
 */
void ConsoleUI::_clearCPU()
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
