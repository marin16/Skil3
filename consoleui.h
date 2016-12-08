#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "service.h"
#include "inputcheck.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run();
private:
    Service _service;
    inputcheck _Valid;
    void _add();
    void _addCPU();
    void _search();
    void _searchCPU();
    void _listScientists();
    void _listCPU();
    void _computers();
    void _scientists();
    void _instructions();
    void _delete();
    void _deleteCPU();
    void _displayScientist(Scientist scientist);
    void _displayScientists(vector<Scientist> scientists);
    void _clear();
    void _edit();
    void _link();
    void _list();
    void _editComputer();
    void _displayComputer(Computer computer);
    void _displayComputers(vector<Computer> computers);
    void _displayLinked(vector<Linked> links);
    void _illegalInput();
    // creates a new scientist from user input
    Scientist _createScientist();
    // creates a new computer from user input
    Computer _createComputer();
};

#endif // CONSOLEUI_H
