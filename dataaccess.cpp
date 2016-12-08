#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <QtSql>

#include "dataaccess.h"
#include "scientist.h"
#include "computer.h"
#include "linked.h"

using namespace std;

DataAccess::DataAccess()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "csdb";
    _db.setDatabaseName(dbName);

    _db.open();
    QSqlQuery scientistsTable;
    scientistsTable.exec("create table if not exists Scientists ("
                         "id integer primary key autoincrement,"
                         "name varchar(50) not null,"
                         "gender char not null,"
                         "dob integer not null,"
                         "dod integer,"
                         "country varchar(50))");
    QSqlQuery computersTable;
    computersTable.exec("create table if not exists Computers ("
                        "id integer primary key autoincrement,"
                        "name varchar(50) not null,"
                        "buildy integer,"
                        "type varchar(50),"
                        "built bool not null)");
    QSqlQuery scientistHasComputerTable;
    scientistHasComputerTable.exec("create table if not exists Scientist_has_Computer ("
                        "sid integer,"
                        "cid integer,"
                        "foreign key(sid) references Scientists(id),"
                        "foreign key(cid) references Computers(id),"
                        "primary key(sid, cid))");
    QSqlQuery scientistHasComputerView;
    scientistHasComputerView.exec("create view if not exists SC_view as select C.id as 'cId', C.name as 'cName', C.buildy, C.type, C.built, S.id as 'sId', S.name as 'sName', S.gender, S.dob, S.dod, S.country from Scientist_has_Computer SC join Scientists S on S.id = SC.sid join Computers C on C.id = SC.cid");

}
bool DataAccess::writeScientist(Scientist scientist)
{
    QSqlQuery query;

    query.prepare("insert into Scientists (name, gender, dob, dod, country) values (:name, :gender, :dob, :dod, :country)");
    query.bindValue(":name", QString::fromStdString(scientist.getName()));
    query.bindValue(":gender", scientist.getGender());
    query.bindValue(":dob", scientist.getBirth());
    query.bindValue(":dod", scientist.getDeath());
    query.bindValue(":country", QString::fromStdString(scientist.getCountry()));

    return query.exec();
}

vector<Scientist> DataAccess::readScientists()
{
    vector<Scientist> scientists;

    QSqlQuery query;
    query.exec("select * from Scientists");

    while(query.next()){
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        char gender = query.value("gender").toString().toStdString().at(0);
        int dob = query.value("dob").toUInt();
        int dod = query.value("dod").toUInt();
        string country = query.value("country").toString().toStdString();

        scientists.push_back(Scientist(id,name,gender,dob,dod,country));
    }

    return scientists;
}

vector<Scientist> DataAccess::readScientistsFromQuery(string q)
{
    vector<Scientist> scientists;

    QSqlQuery query;
    query.exec(QString::fromStdString(q));

    while(query.next()){
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        char gender = query.value("gender").toString().toStdString().at(0);
        int dob = query.value("dob").toUInt();
        int dod = query.value("dod").toUInt();
        string country = query.value("country").toString().toStdString();

        scientists.push_back(Scientist(id,name,gender,dob,dod,country));
    }

    return scientists;
}

vector<Computer> DataAccess::readComputers()
{
    vector<Computer> computers;

    QSqlQuery query;
    query.exec("select * from computers");
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

vector<Linked> DataAccess::readLinked()
{
    vector<Linked> links;

    QSqlQuery query;
    query.exec("select * from SC_view");
    while(query.next()){
        int cId = query.value("cId").toUInt();
        string cName = query.value("cName").toString().toStdString();
        int buildy = query.value("buildy").toUInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();
        int pId = query.value("sId").toUInt();
        string pName = query.value("sName").toString().toStdString();
        char gender = query.value("gender").toString().toStdString().at(0);
        int dob = query.value("dob").toUInt();
        int dod = query.value("dod").toUInt();
        string country = query.value("country").toString().toStdString();

        links.push_back(Linked(Scientist(pId,pName,gender,dob,dod,country), Computer(cId,cName,buildy,type,built)));
    }
    return links;
}

vector<Linked> DataAccess::readLinkedFromQuery(string q)
{
    vector<Linked> links;

    QSqlQuery query;
    query.exec(QString::fromStdString(q));

    while(query.next()){
        int cId = query.value("cId").toUInt();
        string cName = query.value("cName").toString().toStdString();
        int buildy = query.value("buildy").toUInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();
        int pId = query.value("sId").toUInt();
        string pName = query.value("sName").toString().toStdString();
        char gender = query.value("gender").toString().toStdString().at(0);
        int dob = query.value("dob").toUInt();
        int dod = query.value("dod").toUInt();
        string country = query.value("country").toString().toStdString();

        links.push_back(Linked(Scientist(pId,pName,gender,dob,dod,country), Computer(cId,cName,buildy,type,built)));
    }
    return links;
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

bool DataAccess::deleteScientist(int id)
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

bool DataAccess::editScientist(int id, Scientist scientist)
{
    QSqlQuery query;

    query.prepare("update Scientists set name = :name, gender = :gender, dob = :dob, dod = :dod, country = :country where id = :id");
    query.bindValue(":name", QString::fromStdString(scientist.getName()));
    query.bindValue(":gender", scientist.getGender());
    query.bindValue(":dob", scientist.getBirth());
    query.bindValue(":dod", scientist.getDeath());
    query.bindValue(":country", QString::fromStdString(scientist.getCountry()));
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

bool DataAccess::link(int cId, int sId)
{
    QSqlQuery query;
    query.prepare("insert into Scientist_has_Computer (sid, cid) values (:sId, :cId)");
    query.bindValue(":sId", sId);
    query.bindValue(":cId", cId);

    return query.exec();
}

void DataAccess::clearList()
{
    QSqlQuery querySciCom;
    querySciCom.exec("delete from Scientist_has_Computer");

    QSqlQuery querySci;
    querySci.exec("delete from Scientists");

    QSqlQuery queryCom;
    queryCom.exec("delete from Computers");

}
