#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "service.h"
//#include "computerservice.h"
#include "inputcheck.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run();
private:
    Service _service;
    //ComputerService _computerservice;
    inputcheck _Valid;
    void runSci();
    void runCom();
    void _add();
    void _addCPU();
    void _search();
    void _searchCPU();
    void _list();
    void _listCPU();
    void _computers();
    void _scientists();
    void _instructions();
    void _delete();
    void _deleteCPU();
    void _displayPerson(Person person);
    void _displayPersons(vector<Person> persons);
    void _clear();
    void _clearCPU();
    void _edit();
    void _displayComputer(Computer computer);
    void _displayComputers(vector<Computer> computers);
};

#endif // CONSOLEUI_H
