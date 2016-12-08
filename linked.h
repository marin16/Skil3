#ifndef LINKED_H
#define LINKED_H

#include "person.h"
#include "computer.h"

/*
 * Linked is used to manage linked Computers and Scientists
 */
class Linked
{
public:
    Linked();
    Linked(Person person, Computer computer);
    Person getPerson() const
    {
        return _person;
    }
    Computer getComputer() const
    {
        return _computer;
    }
private:
    Person _person;
    Computer _computer;
};

#endif // LINKED_H
