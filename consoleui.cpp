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
        cout << "Please enter one of the following commands:" << endl;
        cout << "add - add a new person" << endl;
        cout << "list - to get a list of persons" << endl;
        cout << "search - search" << endl;
        cout << "quit - Exit program" << endl;

        string command;
        cin >> command;

        if(command == "add")
        {
            string name;
            char gender;
            int birth;
            int death;
            string country;

            cout << "Please add the parameters for the scientists" << endl;
            cout << "Name:";
            cin >> name;

            cout << "Gender:";
            cin >> gender;
            cout << "Year born:";
            cin >> birth;
            cout << "Year of death:";
            cin >> death;
            cout << "Country of origin:";
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
            // cout << "Please enter one of the following commands:" << endl;
            // cout << "alpha - to sorth alphabeticaly" << endl;
            // cout << "dob - sort by date of birth" << endl;
            // ....

            vector<Person> persons = _service.getPersons();
            for (size_t i = 0; i < persons.size(); ++i)
            {
                // TODO: let user decide wich properties to show
                cout << persons[i].getName() << endl;
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
