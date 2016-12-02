#include <iostream>
#include <string>
#include <fstream>
#include "consoleui.h"
#include "person.h"
#include <algorithm>

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    _instructions();
    do
    {
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
        else if(command == "help")
        {
            _instructions();
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
            cout << "please try again." << endl;
        }
    }while(true);
}

void ConsoleUI::_instructions()
{
    cout << "=================================================" << endl;
    cout << "|| Please enter one of the following commands: ||" << endl;
    cout << "=================================================" << endl;
    cout << "||    add    - to add a new person             ||" << endl;
    cout << "||    list   - to get a list of scientsits     ||" << endl;
    cout << "||    search - to search list                  ||" << endl;
    cout << "||    help   - to view this again              ||" << endl;
    cout << "||    delete - to delete a scientist           ||" << endl;
    cout << "||    clear  - to clear all data               ||" << endl;
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
        cout << "Country of origin: ";
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

/*
 * TODO: add more search options
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

void ConsoleUI::_delete()
{
    bool deleteResult;
    string deleteP;
    char chardeleteP[100];

    cout << "=================================================" << endl;
    cout << "||      Please enter a full name to delete:       ||" << endl;
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

void ConsoleUI::_list()
{
    cout << "=================================================" << endl;
    cout << "|| Please enter one of the following commands: ||" << endl;
    cout << "=================================================" << endl;
    cout << "||    name     - sort by name alphabeticaly    ||" << endl;
    cout << "||    year     - sort by year of birth         ||" << endl;
    cout << "||    country  - sort by country               ||" << endl;
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

	cout << person.getName() << string(max(int(offset), int((5 - person.getName().length()) + offset)), ' ')
		 << (person.getGender() == 'M' ? "Male   " : "Female ") << string(offset, ' ');
	// Should probably use a logarithm.
	if (person.getBirth() < 10) {
		cout << person.getBirth() << string(offset+5, ' ');
	} else if (person.getBirth() < 100) {
		cout << person.getBirth() << string(offset+4, ' ');
	} else if (person.getBirth() < 1000) {
		cout << person.getBirth() << string(offset+3, ' ');
	} else {
		cout << person.getBirth() << string(offset+2, ' ');
	}
	if (person.getDeath() == 0) {
	} else if (person.getDeath() < 10) {
		cout << person.getDeath() << string(offset+5, ' ');
	} else if (person.getDeath() < 100) {
		cout << person.getDeath() << string(offset+4, ' ');
	} else if (person.getDeath() < 1000) {
		cout << person.getDeath() << string(offset+3, ' ');
	} else {
		cout << person.getDeath() << string(offset+2, ' ');
	}
	cout << person.getCountry() << endl;
}

// TODO: make this the same as the other.
void ConsoleUI::_displayPersons(vector<Person> persons)
{
    cout << "=================================================" << endl;
    for (size_t i = 0; i < persons.size(); ++i)
    {
        cout << "Name: " << persons[i].getName() << endl;
        cout << "Gender: " << persons[i].getGender() << endl;
        cout << "Birth: " << persons[i].getBirth() << endl;
        cout << "Death: " << persons[i].getDeath() << endl;
        cout << "Nationality: " << persons[i].getCountry() << endl;
        cout << "=================================================" << endl;
    }
}

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
