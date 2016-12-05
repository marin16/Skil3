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
    void runSci();
    void runCom();
    void _add();
    void _search();
    void _list();
    void _computers();
    void _scientists();
    void _instructions();
    void _delete();
    void _displayPerson(Person person);
    void _displayPersons(vector<Person> persons);
    void _clear();
    void _edit();
};

#endif // CONSOLEUI_H
