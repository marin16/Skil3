#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "personservice.h"
#include "inputcheck.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run();
private:
    PersonService _service;
    inputcheck _Valid;
    void _add();
    void _search();
    void _list();
    void _instructions();
    void _delete();
    // Displays a single person to the display from parameter
    void _displayPerson(Person person);
    // Takes in a vector of persons and prints them to the display
    void _displayPersons(vector<Person> persons);
    void _clear();
};

#endif // CONSOLEUI_H
