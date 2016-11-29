#include <iostream>
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
    ofstream file ("data.csv");
    if(file.is_open())
    {
        // write data from param: person to the file
        file << person.getName() << "," << person.getGender() << "," << person.getBirth() << "," << person.getDeath() << "," << person.getCountry() << "\n";
    }
}

vector<Person> DataAccess::readPersons()
{
    // http://stackoverflow.com/questions/34218040/how-to-read-a-csv-file-data-into-an-array
    ifstream file ("data.csv");
    string line;
    vector<vector<string> > parsedCsv;
    vector<Person> persons;
    if(file.is_open())
    {
        while(getline(file,line))
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
    // loop through the lines from the file
    for(int i = 0; i < parsedCsv.size(); i++)
    {
        // fetching data from parsedCsv and converting data
        // convert string to int http://www.cplusplus.com/forum/general/13135/
        string name = parsedCsv[i][0];
        char gender = parsedCsv[i][1].at(0);
        int dob = atoi(parsedCsv[i][2].c_str());
        int dod = atoi(parsedCsv[i][3].c_str());
        string country = parsedCsv[i][4];

        // adding data to person and adding person to persons
        Person person = Person(name, gender, dob, dod, country);
        persons.push_back(person);

        // loop throgh the cells
        /*
        for(int j = 0; j < parsedCsv[i].size(); j++)
        {
            cout << parsedCsv[i][j] << " ";
        }
        cout << endl;
        */
    }

    // TODO: check if parsedCsv is valid
    return persons;
}
