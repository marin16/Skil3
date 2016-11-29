#include <iostream>
#include <string>
#include <fstream>
#include "consoleui.h"
#include "person.h"
#include "inputcheck.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    do
    {
        cout << "=================================================" << endl;
        cout << "|| Please enter one of the following commands: ||" << endl;
        cout << "=================================================" << endl;
        cout << "|| \t add    - to add a new person \t       ||" << endl;
        cout << "|| \t list   - to get a list of persons     ||" << endl;
        cout << "|| \t search - to search list \t       ||" << endl;
        cout << "|| \t quit   - to exit program \t       ||" << endl;
        cout << "=================================================" << endl;

        string command;
        cin >> command;

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
            cout << "Please enter one of the following commands:" << endl;
            cout << "name - sort by name alphabeticaly" << endl;
            cout << "year - sort by year of birth" << endl;
            cout << "or press Enter to get unsorted list" << endl;
            string sort;
            cin >> sort;

            if (sort == "")
                vector<Person> persons = _service.getPersons(0);
            else if (sort == "name")
                vector<Person> persons = _service.getPersons(1);
            else if (sort == "year")
                vector<Person persons = _service.getPersons(2);
            else:
                cout << "Invalid sort command!" << endl;

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

// tester tester
