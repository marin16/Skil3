#include "scientist.h"
#include "utilities.h"

Scientist::Scientist(){

}

Scientist::Scientist(int id, string name, char gender, int birth, int death, string country){

    _id = id;
    _name = name;
    _gender = gender;
    _birth = birth;
    _death = death;
    _country = country;
}

Scientist::Scientist(string name, char gender, int birth, int death, string country){

    _name = name;
    _gender = gender;
    _birth = birth;
    _death = death;
    _country = country;
}

bool Scientist::contains(string searchTerm){

    string searchTermLower = utils::stringToLower(searchTerm);

    string nameLower = utils::stringToLower(_name);
    if (nameLower.find(searchTermLower) != string::npos){

        return true;
    }

    string countryLower = utils::stringToLower(_country);
    if (countryLower.find(searchTermLower) != string::npos){

        return true;
    }

    if (searchTermLower == "male" && _gender == 'M'){

        return true;
    }

    if (searchTermLower == "female" && _gender == 'F'){

        return true;
    }

    string yearBornString = utils::intToString(_birth);

    if (yearBornString.find(searchTerm) != string::npos){

        return true;
    }

    if (_death != 0){

        string yearDiedString = utils::intToString(_death);

        if (yearDiedString.find(searchTerm) != string::npos){

            return true;
        }
    }
    else{

        if (searchTermLower == "alive"){

            return true;
        }
    }

    return false;
}
