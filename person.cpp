#include "person.h"

Person::Person()
{

}
Person::Person(string name, int age, char gender, int birth, int death, string country)
{
    _name = name;
    _age = age;
    _gender = gender;
    _birth = birth;
    _death = death;
    _country = country;
}
