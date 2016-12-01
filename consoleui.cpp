#include <iostream>
#include <string>
#include <fstream>
#include "consoleui.h"
#include "person.h"

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
        else if(command == "help" || command == "instructuins")
        {
            _instructions();
        }
        else if(command == "quit" || command == "q" || command == "exit")
        {
            break;
        }
        else
        {

        }
    }while(true);
}

void ConsoleUI::_instructions()
{
    cout << "=================================================" << endl;
    cout << "|| Please enter one of the following commands: ||" << endl;
    cout << "=================================================" << endl;
    cout << "||    add    - to add a new person             ||" << endl;
    cout << "||    list   - to get a list of persons        ||" << endl;
    cout << "||    search - to search list                  ||" << endl;
    cout << "||    help   - to view this again              ||" << endl;
    cout << "||    quit   - to exit program                 ||" << endl;
    cout << "=================================================" << endl;
}

void ConsoleUI::_add()
{
    string name;
    char gender;
    int birth;
    int death;
    string country;
    char charname[50];
    char answer;


    cout << "=======================================================" << endl;
    cout << "||Please add the parameters for the scientists       ||" << endl;
    cout << "||if you input invalid data you will be asked again. ||" << endl;
    cout << "=======================================================" << endl;

    /*
     * TODO: debug why you cant enter a name that is more than one word
     */
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

    cout << "Year born: ";
    cin >> birth;
    while (birth < 0 || birth > 2016 || cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Year born: ";
            cin >> birth;
        }

        cout << "Year of death: ";
        cin >> death;
        while(death > 2016 || death < 0 || (death < birth && death != 0) || cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Year of death: ";
            cin >> death;
        }
    do
    {
        cout << "Country of origin: ";
        cin >> country;
    }while(!_Valid.nameCheck(country));

    Person newPerson(name, gender, birth, death, country);
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

    cout << "=================================================" << endl;
    cout << "||             Enter search parameter:         ||" << endl;
    cout << "=================================================" << endl;
    cout << "||   name    - to search by first name         ||" << endl;
    cout << "||   birth   - to search by year of birth      ||" << endl;
    cout << "||   death   - to search by year of death      ||" << endl;
    cout << "||   country - to search by country of origin  ||" << endl;
    cout << "=================================================" << endl;

    do{
        cout << "Parameter: ";
        cin >> searchBy;
    }while(searchBy != "name" && searchBy != "birth" && searchBy != "death" && searchBy != "country");

    cout << "Value: ";
    cin >> search;

    results = _service.searchForPerson(search, searchBy);

    _displayPersons(results);
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
    cout << "Name:" << "\t\t" << "Gender:" << "\t" << "DoB:" << "\t" << "DoD:" << "\t" << "Country:" << endl;
    cout << person.getName() << "\t\t" << person.getGender() << "\t" << person.getBirth() << "\t" << person.getDeath() << "\t" << person.getCountry() << endl;
}

void ConsoleUI::_displayPersons(vector<Person> persons)
{
    cout << "Name:" << "\t\t" << "Gender:" << "\t" << "DoB:" << "\t" << "DoD:" << "\t" << "Country:" << endl;
    for (size_t i = 0; i < persons.size(); ++i)
    {
        cout << persons[i].getName() << "\t\t" << persons[i].getGender() << "\t" << persons[i].getBirth() << "\t" << persons[i].getDeath() << "\t" << persons[i].getCountry() << endl;
    }
}
