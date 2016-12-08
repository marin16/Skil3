#ifndef Scientist_H
#define Scientist_H

#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();

    Scientist(int id, string name, char gender, int birth, int death, string country);
    Scientist(string name, char gender, int birth, int death, string country);

    int getId() const
    {
        return _id;
    }
    string getName() const
    {
        return _name;
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
    // Returns true if Scientist contains search Term (source: example solution for week 1 dabs)
    bool contains(string searchTerm);
private:
    int _id;
    string _name;
    char _gender;
    int _birth;
    int _death;
    string _country;
};

#endif // Scientist_H
