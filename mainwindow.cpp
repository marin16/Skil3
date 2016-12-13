#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "scientist.h"
#include <string>
#include <QString>
#include <QLabel>
#include <QMessageBox>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> ddmSortScientists -> addItem("Name-asc");
    ui -> ddmSortScientists -> addItem("Birth-asc");
    ui -> ddmSortScientists -> addItem("Death-asc");
    ui -> ddmSortScientists -> addItem("Country-asc");
    ui -> ddmSortScientists -> addItem("-----");
    ui -> ddmSortScientists -> addItem("Name-desc");
    ui -> ddmSortScientists -> addItem("Birth-desc");
    ui -> ddmSortScientists -> addItem("Death-desc");
    ui -> ddmSortScientists -> addItem("Country-desc");
    ui -> ddmSortScientists -> addItem("-----");
    ui -> ddmSortScientists -> addItem("Unsorted");


    ui -> ddmComputerSort -> addItem("Name-asc");
    ui -> ddmComputerSort -> addItem("BuildYear-asc");
    ui -> ddmComputerSort -> addItem("Type-asc");
    ui -> ddmComputerSort -> addItem("-----");
    ui -> ddmComputerSort -> addItem("Name-desc");
    ui -> ddmComputerSort -> addItem("BuildYear-desc");
    ui -> ddmComputerSort -> addItem("Type-desc");
    ui -> ddmComputerSort -> addItem("-----");
    ui -> ddmComputerSort -> addItem("Unsorted");

    ui -> ddmComputerBuilt -> addItem("Built");
    ui -> ddmComputerBuilt -> addItem("Not Built");

    ui -> addScientistGender -> addItem("Male");
    ui -> addScientistGender -> addItem("Female");

    for(size_t i = 2016; i >= 1800; i--)
    {
        QString year = QString::number(i);
        ui -> addScientistBirth -> addItem(year);

    }

    for(size_t i = 2016; i >= 1800; i--)
    {
        QString year = QString::number(i);
        ui -> addScientistDeath -> addItem(year);

    }

    ui -> ddmTableLink -> addItem("Link Sort");

    for (int i = 2016; i > 1799; i--)
    {
        QString s = QString::number(i);
        ui -> addComputerYear -> addItem(s);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addScientist_clicked()
{
    string name = ui -> addScientistName -> text().toStdString();
    string gender = ui -> addScientistGender -> currentText().toStdString();
    string birth = ui -> addScientistBirth -> currentText().toStdString();
    string death = ui -> addScientistDeath -> currentText().toStdString();
    string country = ui -> addScientistNationality -> currentText().toStdString();

    int birthint = atoi(birth.c_str());
    int deathint = atoi(death.c_str());

    if(!_valid.nameCheck(name)) {
        QMessageBox::warning(this, "Name wrong", "This name is illegal. Try again!");
        ui -> addScientistName -> clear();
    }
    else {

        Scientist newScientist = Scientist(name, toupper(gender.at(0)), birthint, deathint, country);

        DisplayScientist(newScientist);

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Scientist", "Are you sure the information is correct?",
                                                    QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            _service.addScientist(newScientist);
            QMessageBox::information(this, "Scientist added", "This scientist has been added to the database!");
            ui -> listScientist -> clear();
            ui -> addScientistName -> clear();
        }
        else {
            MainWindow();
        }
    }
}

void MainWindow::DisplayAllScientists(){
    vector<Scientist> scientists = _service.getScientists(1);
    DisplayScientists(scientists);
}

void MainWindow::DisplayScientists(std::vector<Scientist> scientists){
    ui->listScientist->clear();

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        Scientist currentScientist = scientists.at(i);

        ui->listScientist->addItem(QString::fromStdString(currentScientist.getName()));
    }
}

void MainWindow::DisplayScientist(Scientist scientist){
    ui->listScientist->clear();

        QString genderstring = QChar(scientist.getGender());

        ui->listScientist->addItem(QString::fromStdString(scientist.getName()));
        ui->listScientist->addItem(genderstring);
        ui->listScientist->addItem(QString::number(scientist.getBirth()));
        ui->listScientist->addItem(QString::number(scientist.getDeath()));
        ui->listScientist->addItem(QString::fromStdString(scientist.getCountry()));

}

