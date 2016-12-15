#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer{
public:
    Computer();
    Computer(int id, string name, int buildy, string type, bool built);
    Computer(string name, int buildy, string type, bool built);

    int getId() const{

        return _id;
    }
    string getName() const{

        return _name;
    }
    int getBuildy() const{

        return _buildy;
    }
    string getType() const{

        return _type;
    }
    bool getBuilt() const{

        return _built;
    }

     // Returns true if Computer contains search Term
    bool contains(string searchTerm);

private:
    int _id;
    string _name;
    int _buildy;
    string _type;
    bool _built;
};

#endif // COMPUTER_H
