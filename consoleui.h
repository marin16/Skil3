#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "personservice.h"

class ConsoleUI
{
public:
    ConsoleUI();

    void run();

private:
    PersonService _service;
};

#endif // CONSOLEUI_H
