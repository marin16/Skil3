#include <iostream>
#include <string>
#include "consoleui.h"
#include "performer.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    cout << "Please enter of the following commands:" << endl;
    cout << "list - This will list all performers in the ssytem" << endl;
    cout << "add - This will add a new performer" << endl;

    string command;
    cin >> command;

    if (command == "list")
    {
        vector<Performer> performers = _service.getPerformers();

            for (size_t i = 0; i < performers.size(); ++i)
            {
                cout << performers[i].getName() << endl;
            }
    }
    else if (command == "add")
    {
        // TODO;
    }
}
