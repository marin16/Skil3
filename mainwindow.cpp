#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include <QDebug>
#include "scientist.h"
#include <string>
#include <QString>
#include <QLabel>
#include <QMessageBox>
#include <QComboBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableScientist->setSelectionBehavior(QAbstractItemView::SelectRows);

    DisplayAllScientists();
    DisplayAllComputers();

    ui -> ddmSortScientists -> addItem("Unsorted");
    ui -> ddmSortScientists -> addItem("Name-asc");
    ui -> ddmSortScientists -> addItem("Birth-asc");
    ui -> ddmSortScientists -> addItem("Death-asc");
    ui -> ddmSortScientists -> addItem("Country-asc");
    ui -> ddmSortScientists -> addItem("Name-desc");
    ui -> ddmSortScientists -> addItem("Birth-desc");
    ui -> ddmSortScientists -> addItem("Death-desc");
    ui -> ddmSortScientists -> addItem("Country-desc");

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

    ui -> addScientistDeath -> addItem("Alive");

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

    for(size_t i = 0; i < (sizeof(constants::nationalities)/sizeof(*constants::nationalities)); i++)
    {
        QString nationality = QString::fromStdString(constants::nationalities[i]);
        ui -> addScientistNationality -> addItem(nationality);
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

        //DisplayScientist(newScientist);

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Scientist", "Are you sure the information is correct?",
                                                    QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            _service.addScientist(newScientist);
            QMessageBox::information(this, "Scientist added", "This scientist has been added to the database!");
            ui -> tableScientist -> clear();
            ui -> addScientistName -> clear();
        }
        else {
            MainWindow();
        }
    }
    DisplayAllScientists();
}


void MainWindow::DisplayAllScientists(){
    vector<Scientist> scientists = _service.getScientists(_orderBy);
    DisplayScientists(scientists);
}

void MainWindow::DisplayScientists(std::vector<Scientist> scientists){
    ///ui->tableScientist->clearContents();
    ui -> tableScientist -> verticalHeader() -> setVisible(false);
    ui -> tableScientist -> setRowCount(scientists.size());
    string alive = "Alive";
    string male = "Male";
    string female = "Female";
    string other = "Other";
    for (unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientist = scientists.at(row);

        ui->tableScientist->setItem(row, 0, new QTableWidgetItem(QString::number(currentScientist.getId())));
        ui->tableScientist->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(currentScientist.getName())));
        if (currentScientist.getGender() == 'M')
            ui->tableScientist->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(male)));
        else if (currentScientist.getGender() == 'F')
            ui->tableScientist->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(female)));
        else
            ui->tableScientist->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(other)));
        ui->tableScientist->setItem(row, 3, new QTableWidgetItem(QString::number(currentScientist.getBirth())));
        if (currentScientist.getDeath() == 0)
            ui->tableScientist->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(alive)));
        else
            ui->tableScientist->setItem(row, 4, new QTableWidgetItem(QString::number(currentScientist.getDeath())));
        ui->tableScientist->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(currentScientist.getCountry())));
    }
    displayedScientist = scientists;
}



void MainWindow::DisplayAllComputers(){
    vector<Computer> computers = _service.getComputers(1);
    DisplayComputers(computers);
}

void MainWindow::DisplayComputers(std::vector<Computer> computers){
    ///ui->tableScientist->clearContents();
    ui -> tableComputer -> verticalHeader() -> setVisible(false);
    ui -> tableComputer -> setRowCount(computers.size());
    string built = "Yes";
    string notbuilt = "No";

    for (unsigned int row = 0; row < computers.size(); row++)
    {
        Computer currentComputers = computers.at(row);

        ui->tableComputer->setItem(row, 0, new QTableWidgetItem(QString::number(currentComputers.getId())));
        ui->tableComputer->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(currentComputers.getName())));
        ui->tableComputer->setItem(row, 2, new QTableWidgetItem(QString::number(currentComputers.getBuildy())));
        ui->tableComputer->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(currentComputers.getType())));
        if (currentComputers.getBuilt())
            ui->tableComputer->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(built)));
        else
            ui->tableComputer->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(notbuilt)));
    }
    displayedComputer = computers;
}

void MainWindow::on_tableScientist_clicked(const QModelIndex &index)
{
    ui -> deleteScientist -> setEnabled(true);
}


void MainWindow::on_tableComputer_clicked(const QModelIndex &index)
{
    ui -> deleteComputer -> setEnabled(true);
}



void MainWindow::on_filterScientistsList_textChanged(const QString &arg1)
{
    vector<Scientist> scientists;

    ui->tableScientist->clearContents();

    scientists = _service.searchForScientist(arg1.toStdString(), _orderBy);

    DisplayScientists(scientists);
}


void MainWindow::on_listScientist_clicked(const QModelIndex &index)
{
    ui -> deleteScientist -> setEnabled(true);
}

void MainWindow::on_deleteScientist_clicked()
{
    int selectedScientistIndex = ui -> tableScientist -> currentIndex().row();
    Scientist selectedScientist = displayedScientist.at(selectedScientistIndex);
    bool success =_service.deleteScientist(selectedScientist.getId());

    if(success)
    {
        ui -> filterScientistsList -> setText("");
        DisplayAllScientists();

        ui -> deleteScientist -> setEnabled(false);
    }
    else
    {
        QMessageBox::warning(this, "Name wrong", "Failed to delete");
    }
}

void MainWindow::on_ddmSortScientists_currentIndexChanged(int index)
{
    _orderBy = index;
    on_filterScientistsList_textChanged(ui->filterScientistsList->text());
}


void MainWindow::on_addComputer_clicked()
{
    string name = ui -> addComputerName -> text().toStdString();
    string type = ui -> addComputerType -> text().toStdString();
    string year = ui -> addComputerYear -> currentText().toStdString();
    string built = ui -> ddmComputerBuilt -> currentText().toStdString();

    bool builtbool;
    int yearint = atoi(year.c_str());
    if(built == "built")
        builtbool = true;
    else
        builtbool = false;

    if(!_valid.cpuCheck(name)) {
        QMessageBox::warning(this, "Name wrong", "This name is illegal. Try again!");
        ui -> addComputerName -> clear();
    }
    else {

        Computer newComputer = Computer(name, yearint, type, builtbool);


        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Computer", "Are you sure the information is correct?",
                                                    QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            _service.addComputer(newComputer);
            QMessageBox::information(this, "Computer added", "This computer has been added to the database!");
            ui -> tableComputer -> clear();
            ui -> addComputerName -> clear();
            ui -> addComputerType -> clear();
        }
        else {
            MainWindow();
        }
    }
    DisplayAllComputers();
}

void MainWindow::on_deleteComputer_clicked()
{
    int selectedComputerIndex = ui -> tableComputer -> currentIndex().row();
    Computer selectedComputer = displayedComputer.at(selectedComputerIndex);
    bool success =_service.deleteComputer(selectedComputer.getId());

    if(success)
    {
        ui -> filterComputers -> setText("");
        DisplayAllComputers();

        ui -> deleteComputer -> setEnabled(false);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Failed to delete");
    }
}
