#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "scientist.h"
#include <string>
#include <Qstring>
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

    ui -> ddmTableLink -> addItem("Link Sort");

    for (int i = 2016; i > 1800; i--)
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

    Scientist newScientist = Scientist(name, toupper(gender.at(0)), birthint, deathint, country);

    displayScientist(newScientist);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Scientist", "Are you sure the information is correct?",
                                                QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        serviceScientist.addScientist(newScientist);
    }
    else {
        MainWindow();
    }
}

void MainWindow::displayScientist(Scientist scientist)
{
}
