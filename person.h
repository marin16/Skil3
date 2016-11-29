#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string name, int age, char gender, int birth, int death, string country);

    string getName() const
    {
        return _name;
    }
    int getAge() const
    {
        return _age;
    }
    char getGender() const
    {
        return _gender;
    }
    int getBirth() const
    {
        return _birth;
    }
    int getDeath() const
    {
        return _death;
    }
    string getCountry() const
    {
        return _country;
    }

private:
    string _name;
    int _age;
    char _gender;
    int _birth;
    int _death;
    string _country;
};

#endif // PERSON_H
