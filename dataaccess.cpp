#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "dataaccess.h"
#include "person.h"

DataAccess::DataAccess()
{

}
void DataAccess::writePerson(Person person)
{
    /*
    ifstream file ("data.csv");
    if(file.is_open())
    {
        file << person.getName() << "," << person.getAge() << "\n";
    }
    */
}

vector<Person> DataAccess::readPersons()
{
    /*
    ifstream file ("data.csv");
    vector<string> data;

    if(file.is_open())
    {
        string s;
        if(!getline (infile, s )) break;

        isstringstream ss( s );
        vector <string> record;

        while(ss)
        {
            string s;
            if (!getline(ss, s, ',')) break;
            record.push_back( s );
        }

        data.push_back( record );
    }
    if (!infile.eof())
    {
        // TODO: error handeling
    }
    */
}
