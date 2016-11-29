#include "person.h"

Person::Person()
{

}
Person::Person(string name, char gender, int birth, int death, string country)
{
    _name = name;
    _gender = gender;
    _birth = birth;
    _death = death;
    _country = country;
}
