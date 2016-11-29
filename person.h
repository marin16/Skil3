#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string name, int age);

    string getName() const
    {
        return _name;
    }
    int getAge() const
    {
        return _age;
    }
private:
    // TODO: more properties
    string _name;
    int _age;
};

#endif // PERSON_H
