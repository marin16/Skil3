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
    // create fstream to data.csv
    ifstream file ("data.csv");
    if(file.is_open())
    {
        // write data from param: person to the file
        file << person.getName() << "," << person.getAge() << "\n";
    }
}

vector<Person> DataAccess::readPersons()
{
    // http://stackoverflow.com/questions/34218040/how-to-read-a-csv-file-data-into-an-array
    ifstream file ("data.csv");
    string line;
    vector<vector<string> > parsedCsv;
    if(file.is_open())
    {
        while(getline(data,line))
        {
            stringstream lineStream(line);
            string cell;
            vector<string> parsedRow;
            while(getline(lineStream,cell, ','))
            {
                parsedRow.push_back(cell);
            }
            parsedCsv.push_back(parsedRow);
        }
    }
}
