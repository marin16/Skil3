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
    cout << "Fucker";
    if(!db.open())
    {
        QSqlQuery ScientistsTable;
        ScientistsTable.exec("create table if not exists Scientists ("
                             "id integer primary key autoincrement,"
                             "name varchar(50) not null,"
                             "gender char not null,"
                             "dob integer not null,"
                             "dod integer,"
                             "country varchar(50))");
        QSqlQuery ComputersTable;
        ComputersTable.exec("create table if not exists Computers ("
                            "id integer primary key autoincrement,"
                            "name varchar(50) not null,"
                            "builty integer,"
                            "type varchar(50),"
                            "built bool not null)");
    }
    else
    {
        //Fuck you
        db.close();
    }
}
void DataAccess::writePerson(Person person)
{
    /*
    // create fstream to data.csv
    ofstream file;
    //open file in append mode
    file.open("data.csv", ios::app);
    if(file.is_open())
    {
        // write data from param: person to the file in csv format
        file << person.getName() << "," << person.getGender() << "," << person.getBirth() << "," << person.getDeath() << "," << person.getCountry() << "\n";
    }
    */
    QSqlQuery query;

    query.prepare("INSERT INTO Scientists (name, gender, dob, dod, country) VALUES (:name, :gender, :dob, :dod, :country)");
    query.bindValue(":name", QString::fromStdString(person.getName()));
    query.bindValue(":gender", person.getGender());
    query.bindValue(":dob", person.getBirth());
    query.bindValue(":dod", person.getDeath());
    query.bindValue(":country", QString::fromStdString(person.getCountry()));
    if(query.exec())
        cout << "Query executed" << endl; //TODO: change to return true
    else
        cout << "Query failed" << endl; //TODO: change to return false
}

vector<Person> DataAccess::readPersons()
{
    vector<Person> persons;

    QSqlQuery query;
    query.exec("SELECT * from Scientists");

    while(query.next()){
        string name = query.value("name").toString().toStdString();
        //TODO: Fix char
        char gender = query.value("gender").toString().toStdString().at(0);
        int dob = query.value("dob").toUInt();
        int dod = query.value("dod").toUInt();
        string country = query.value("country").toString().toStdString();

        persons.push_back(Person(name,gender,dob,dod,country));
    }

    return persons;
}

vector<Computer> DataAccess::readComputers()
{
    vector<Computer> computers;

    QSqlQuery query;
    query.exec("SELECT * from Scientists");

    while(query.next()){
        string name = query.value("name").toString().toStdString();
        //TODO: Fix char
        int buildy = query.value("buildy").toUInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();

        computers.push_back(Computer(name,buildy,type,built));
    }

    return computers;
}


void DataAccess::clearList()
{

    QSqlQuery querySci;
    querySci.exec("delete from Scientists");

    QSqlQuery queryCom;
    queryCom.exec("delete from Computers");

}
