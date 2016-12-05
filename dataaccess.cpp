#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <QtSql>

#include "dataaccess.h"
#include "person.h"

using namespace std;

DataAccess::DataAccess()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "csdb";
    db.setDatabaseName(dbName);

    if(!db.open())
    {
        //DB did not open
    }
}
void DataAccess::writePerson(Person person)
{
    // create fstream to data.csv
    ofstream file;
    //open file in append mode
    file.open("data.csv", ios::app);
    if(file.is_open())
    {
        // write data from param: person to the file in csv format
        file << person.getName() << "," << person.getGender() << "," << person.getBirth() << "," << person.getDeath() << "," << person.getCountry() << "\n";
    }
}

vector<Person> DataAccess::readPersons()
{
    vector<Person> persons;

    //db.open();
    QSqlQuery query(_db);
    query.exec("SELECT * from Scientists");

    while(query.next()){
        string name = query.value("name").toString().toStdString();
        //char gender = query.value("gender").toChar().toStdChar();
        int dob = query.value("dob").toUInt();
        int dod = query.value("dod").toUInt();
        string country = query.value("country").toString().toStdString();

        persons.push_back(Person(name,'F',dob,dod,country));
    }

    return persons;
}

void DataAccess::clearList()
{
    ofstream file ("data.csv");
    file.open("data.csv", ofstream::out | ofstream::trunc);
    file.close();

}
