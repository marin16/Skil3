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
    do
    {
        cout << "Please enter one of the following commands:" << endl;
        cout << "add - add a new person" << endl;
        cout << "list - to get a list of persons" << endl;

        string command;
        cin >> command;

        if(command == "add")
        {
            //TODO: implement add performer
            string name;
            int age;
            cin >> name;
            cin >> age;
            //TODO: check for invalid data

            Person newPerson(name, age);

            //TODO: error casting (enum _service.addPerson(new...))
            _service.addPerson(newPerson);
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
        else
        {
            // Unknown command handeling
            cout << "Unknown command: " << command << endl;
            cout << "please try again." << endl;
        }
    // TODO: loop
    }while(true);
}
