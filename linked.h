#ifndef LINKED_H
#define LINKED_H

#include "scientist.h"
#include "computer.h"

/*
 * Linked is used to manage linked Computers and Scientists
 */
class Linked
{
public:
    Linked();
    Linked(Scientist scientist, Computer computer);
    Scientist getScientist() const
    {
        return _scientist;
    }
    Computer getComputer() const
    {
        return _computer;
    }
private:
    Scientist _scientist;
    Computer _computer;
};

#endif // LINKED_H
