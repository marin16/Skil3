#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <QtSql>

#include "dataaccess.h"
#include "person.h"
#include "computer.h"

using namespace std;

DataAccess::DataAccess()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "csdb";
    _db.setDatabaseName(dbName);

    _db.open();
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
                        "buildy integer,"
                        "type varchar(50),"
                        "built bool not null)");
}
bool DataAccess::writePerson(Person person)
{
    QSqlQuery query;

    query.prepare("insert into Scientists (name, gender, dob, dod, country) values (:name, :gender, :dob, :dod, :country)");
    query.bindValue(":name", QString::fromStdString(person.getName()));
    query.bindValue(":gender", person.getGender());
    query.bindValue(":dob", person.getBirth());
    query.bindValue(":dod", person.getDeath());
    query.bindValue(":country", QString::fromStdString(person.getCountry()));

    return query.exec();
}

vector<Person> DataAccess::readPersons()
{
    vector<Person> persons;

    QSqlQuery query;
    query.exec("select * from Scientists");

    while(query.next()){
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        char gender = query.value("gender").toString().toStdString().at(0);
        int dob = query.value("dob").toUInt();
        int dod = query.value("dod").toUInt();
        string country = query.value("country").toString().toStdString();

        persons.push_back(Person(id,name,gender,dob,dod,country));
    }

    return persons;
}

vector<Person> DataAccess::readPersonsFromQuery(string q)
{
    vector<Person> persons;

    QSqlQuery query;
    query.exec(QString::fromStdString(q));

    while(query.next()){
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        char gender = query.value("gender").toString().toStdString().at(0);
        int dob = query.value("dob").toUInt();
        int dod = query.value("dod").toUInt();
        string country = query.value("country").toString().toStdString();

        persons.push_back(Person(id,name,gender,dob,dod,country));
    }

    return persons;
}

vector<Computer> DataAccess::readComputers()
{
    vector<Computer> computers;

    QSqlQuery query;
    query.exec("SELECT * from computers");
    while(query.next()){
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int buildy = query.value("buildy").toUInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();

        computers.push_back(Computer(id,name,buildy,type,built));
    }

    return computers;
}

vector<Computer> DataAccess::readComputersFromQuery(string q)
{
    vector<Computer> computers;

    QSqlQuery query;
    query.exec(QString::fromStdString(q));

    while(query.next()){
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int buildy = query.value("buildy").toUInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();

        computers.push_back(Computer(id,name,buildy,type,built));
    }

    return computers;
}

bool DataAccess::writeComputer(Computer computer)
{
    QSqlQuery query;

    query.prepare("insert into computers (name, buildy, type, built) values (:name, :buildy, :type, :built)");
    query.bindValue(":name", QString::fromStdString(computer.getName()));
    query.bindValue(":buildy", computer.getBuildy());
    query.bindValue(":type",QString::fromStdString(computer.getType()));
    query.bindValue(":built",computer.getBuilt());

    return query.exec();
}

bool DataAccess::deletePerson(int id)
{
    QSqlQuery query;

    query.prepare("delete from Scientists where  id = :id");
    query.bindValue(":id", id);

    return query.exec();
}

bool DataAccess::deleteComputer(int id)
{
    QSqlQuery query;

    query.prepare("delete from Computers where  id = :id");
    query.bindValue(":id", id);

    return query.exec();
}

bool DataAccess::editPerson(int id, Person person)
{
    QSqlQuery query;

    query.prepare("update Scientists set name = :name, gender = :gender, dob = :dob, dod = :dod, country = :country where id = :id");
    query.bindValue(":name", QString::fromStdString(person.getName()));
    query.bindValue(":gender", person.getGender());
    query.bindValue(":dob", person.getBirth());
    query.bindValue(":dod", person.getDeath());
    query.bindValue(":country", QString::fromStdString(person.getCountry()));
    query.bindValue(":id", id);

    return query.exec();
}

bool DataAccess::editComputer(int id, Computer computer)
{
    QSqlQuery query;

    query.prepare("update Computers set name = :name, buildy = :buildy, type = :type, built = :built where id = :id");
    query.bindValue(":name", QString::fromStdString(computer.getName()));
    query.bindValue(":buildy", computer.getBuildy());
    query.bindValue(":type",QString::fromStdString(computer.getType()));
    query.bindValue(":built",computer.getBuilt());
    query.bindValue(":id", id);

    return query.exec();
}

void DataAccess::clearList()
{

    QSqlQuery querySci;
    querySci.exec("delete from Scientists");

    QSqlQuery queryCom;
    queryCom.exec("delete from Computers");

}
