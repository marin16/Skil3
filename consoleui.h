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
    /*
     * _add: Used if user wants to input a scientist.
     * Runs _createScientist() and displays the inputed information and asks for confirmation
     * from user before adding the information to a vector.
     */
    void _add();
    /*
     * _addCPU: Used if user wants to input a computer
     * Runs _createComputer() and displays the inputed information and asks for confirmation
     * from user before adding the information to a vector.
     */
    void _addCPU();
    /*
     * _search: Searches in the list of scientists based on user's input.
     * Displays the result.
     */
    void _search();
    /*
     * _search: Searches in the list of computers based on user's input.
     * Displays the result.
     */
    void _searchCPU();
    /*
     * _list: Displays menu of scientists for list. Displays list based on user's input.
     */
    void _listScientists();
    /*
     * _list: Displays menu of computers for list. Displays list based on user's input.
     */
    void _listCPU();
    //void _computers();
    //void _scientists();
    /*
     * _instructions(): Prints out instructions for the user informing him of what commands he has available.
     */
    void _instructions();
    /*
     * _delete: Deletes scientist from list.
     */
    void _delete();
    /*
     * _delete: Deletes computer from list.
     */
    void _deleteCPU();
    /*
     * _displayScientist: Displays one scientist.
     */
    void _displayScientist(Scientist scientist);
    /*
     * _displayScientists: Displays a list of scientists.
     */
    void _displayScientists(vector<Scientist> scientists);
    /*
     * _clear: Clears the data from the list of scientists.
     */
    void _clear();
    /*
     * _edit: Edits a person.
     */
    void _edit();
    /*
     * _link: Links scientist and computer together.
     */
    void _link();
    /*
     * _list: Displays menu of computers and scientists. Displays list based on user's input.
     */
    void _list();
    /*
     * _edit: Edits a computer.
     */
    void _editComputer();
    /*
     * _displayComputer: Displays one computer.
     */
    void _displayComputer(Computer computer);
    /*
     * _displayComputers: Displays a list of computers.
     */
    void _displayComputers(vector<Computer> computers);
    /*
     * _displayLinked: Displays linked computers and scientists.
     */
    void _displayLinked(vector<Linked> links);
    /*
     * _illegalInput: Writes out error message about illegal input.
     */
    void _illegalInput();
    /*
     * _create: Creates one scientist.
     */
    Scientist _createScientist();
    /*
     * _create: Creates one computer.
     */
    Computer _createComputer();
};

#endif // CONSOLEUI_H
