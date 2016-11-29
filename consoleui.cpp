#include <iostream>
#include <string>
#include <fstream>
#include "consoleui.h"
#include "person.h"
#include "inputcheck.h"

using namespace std;

string Commands();

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    do
    {
        string command = Commands();

        if(command == "add")
        {
            string name;
            char gender;
            int birth;
            int death;
            string country;

            cout << "=================================================" << endl;
            cout << "||Please add the parameters for the scientists ||" << endl;
            cout << "=================================================" << endl;


            cout << "Name: ";
            cin >> name;
            cout << "Gender: ";
            cin >> gender;
            cout << "Year born: ";
            cin >> birth;
            cout << "Year of death: ";
            cin >> death;
            cout << "Country of origin: ";
            cin >> country;
            //TODO: check for invalid data

            Person newPerson(name, gender, birth, death, country);

            //TODO: error casting (enum _service.addPerson(new...))
            _service.addPerson(newPerson);
        }
        else if(command == "search")
        {
            //TODO: implement search
        }
        else if(command == "list")
        {
            // TODO: let user sort
            cout << "=================================================" << endl;
            cout << "|| Please enter one of the following commands: ||" << endl;
            cout << "=================================================" << endl;
            cout << "|| \t name - sort by name alphabeticaly     ||" << endl;
            cout << "|| \t year - sort by year of birth \t       ||" << endl;
            cout << "|| \t or press Enter to get unsorted list   ||" << endl;
            cout << "=================================================" << endl;
            string sort;
            cin >> sort;
            vector<Person> persons;

            if (sort == "name")
                persons = _service.getPersons(1);
            else if (sort == "year")
                persons = _service.getPersons(2);
            else
                persons = _service.getPersons(0);

            for (size_t i = 0; i < persons.size(); ++i)
            {
                // TODO: let user decide wich properties to show
                cout << "Name: " << persons[i].getName() << " Gender: " << persons[i].getGender() << " Date of birth: " << persons[i].getBirth() << " Date of death: " << persons[i].getDeath() << " Country: " << persons[i].getCountry() << endl;
            }
        }
        else if(command == "quit")
        {
            break;
        }
        else
        {
            // Unknown command handeling
            cout << "Unknown command: " << command << endl;
            cout << "please try again." << endl;
        }
    // TODO: loop
    }while(true);
}

string Commands()
{
    while(true)
        {
    string com;
        cout << "=================================================" << endl;
        cout << "|| Please enter one of the following commands: ||" << endl;
        cout << "=================================================" << endl;
        cout << "|| \t add    - to add a new person \t       ||" << endl;
        cout << "|| \t list   - to get a list of persons     ||" << endl;
        cout << "|| \t search - to search list \t       ||" << endl;
        cout << "|| \t quit   - to exit program \t       ||" << endl;
        cout << "=================================================" << endl;
    cin >> com;
    if(com == "add" || com == "list" || com == "search" || com == "quit")
    {
        return com;
        break;
    }
        }

}
