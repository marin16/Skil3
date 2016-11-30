#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "personservice.h"
#include "inputcheck.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void instructions();
    void run();
    void add();
    void search();
    void list();
    void displayPerson(Person person);
    void displayPersons(vector<Person> persons);
private:
    PersonService _service;
    inputcheck _Valid;
};

#endif // CONSOLEUI_H
