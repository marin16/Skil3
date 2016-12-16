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
#include <QSpinBox>
#include "tableitem.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableScientist->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableComputer->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableTableLink->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableIdComputer->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableIdScientist->setSelectionBehavior(QAbstractItemView::SelectRows);

    DisplayAllScientists();
    DisplayAllComputers();
    DisplayAllIdScientists();
    DisplayAllIdComputers();
    DisplayAllLinked();

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

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Scientist", "Are you sure the information is correct?",
                                                    QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            bool success = _service.addScientist(newScientist);

            if(success) {
                QMessageBox::information(this, "Scientist added", "This scientist has been added to the database!");
                ui -> tableScientist -> clearContents();
                ui -> addScientistName -> clear();
                ui -> addScientistBirth -> setCurrentText(QString::number(2016));
                ui -> addScientistDeath -> setCurrentText(QString::fromStdString("Alive"));
                ui -> addScientistNationality -> setCurrentText(QString::fromStdString("Afghan"));
                ui -> addScientistGender -> setCurrentText(QString::fromStdString("Male"));
            }
            else {
                QMessageBox::information(this, "Database error", "Error updating the database");
            }

        }
        else {
            MainWindow();
        }
    }
    DisplayAllScientists();
    DisplayAllIdScientists();
}


void MainWindow::DisplayAllScientists(){
    vector<Scientist> scientists = _service.getScientists();
    DisplayScientists(scientists);
}

void MainWindow::DisplayScientists(vector<Scientist> scientists){
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

        ui->tableScientist->setItem(row, 0, new QTableWidgetItem(_paddId(currentScientist.getId())));
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
    vector<Computer> computers = _service.getComputers();
    DisplayComputers(computers);
}

void MainWindow::DisplayComputers(vector<Computer> computers){
    ///ui->tableScientist->clearContents();
    ui -> tableComputer -> verticalHeader() -> setVisible(false);
    ui -> tableComputer -> setRowCount(computers.size());
    string built = "Yes";
    string notbuilt = "No";

    for (unsigned int row = 0; row < computers.size(); row++)
    {
        Computer currentComputers = computers.at(row);

        ui->tableComputer->setItem(row, 0, new QTableWidgetItem(_paddId(currentComputers.getId())));
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
    if(ui->tableScientist->currentItem()->isSelected() == true)
        ui->deleteScientist->setEnabled(true);
    else
        ui->deleteScientist->setEnabled(false);

}


void MainWindow::on_tableComputer_clicked(const QModelIndex &index)
{
    ui -> deleteComputer -> setEnabled(true);
}



void MainWindow::on_filterScientistsList_textChanged(const QString &arg1)
{
    vector<Scientist> scientists;

    ui->tableScientist->clearContents();

    scientists = _service.searchForScientist(arg1.toStdString());

    DisplayScientists(scientists);
}

void MainWindow::on_filterComputers_textChanged(const QString &arg1)
{
    vector<Computer> computers;

    ui->tableComputer->clearContents();

    computers = _service.searchForComputer(arg1.toStdString());

    DisplayComputers(computers);
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
    ui -> deleteScientist -> setDisabled(true);
    DisplayAllIdScientists();
}

void MainWindow::on_addComputer_clicked()
{
    string name = ui -> addComputerName -> text().toStdString();
    string type = ui -> addComputerType -> text().toStdString();
    string year = ui -> addComputerYear -> currentText().toStdString();
    string built = ui -> ddmComputerBuilt -> currentText().toStdString();

    bool builtbool;
    int yearint = atoi(year.c_str());
    if(built == "Built")
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
            ui -> tableComputer -> clearContents();
            ui -> addComputerName -> clear();
            ui -> addComputerType -> clear();
        }
        else {
            MainWindow();
        }
    }
    DisplayAllComputers();
    DisplayAllIdComputers();
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
    DisplayAllIdComputers();
}

void MainWindow::DisplayAllIdScientists(){
    vector<Scientist> scientists = _service.getScientists();
    DisplayIdScientists(scientists);
}

void MainWindow::DisplayIdScientists(std::vector<Scientist> scientists){
    ///ui->tableScientist->clearContents();
    ui -> tableIdScientist -> verticalHeader() -> setVisible(false);
    ui -> tableIdScientist -> setRowCount(scientists.size());

    for (unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientist = scientists.at(row);

        ui->tableIdScientist->setItem(row, 0, new QTableWidgetItem(_paddId(currentScientist.getId())));
        ui->tableIdScientist->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(currentScientist.getName())));
    }
    displayedScientist = scientists;
}

void MainWindow::DisplayAllIdComputers(){
    vector<Computer> computers = _service.getComputers();
    DisplayIdComputers(computers);
}

void MainWindow::DisplayIdComputers(std::vector<Computer> computers){
    ///ui->tableIdComputer->clearContents();
    ui -> tableIdComputer -> verticalHeader() -> setVisible(false);
    ui -> tableIdComputer -> setRowCount(computers.size());

    for (unsigned int row = 0; row < computers.size(); row++)
    {
        Computer currentComputers = computers.at(row);

        ui->tableIdComputer->setItem(row, 0, new QTableWidgetItem(_paddId(currentComputers.getId())));
        ui->tableIdComputer->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(currentComputers.getName())));

    }
    displayedComputer = computers;
}

void MainWindow::DisplayAllLinked(){
    vector<Linked> linked = _service.getLinks();
    DisplayLinked(linked);
}

void MainWindow::DisplayLinked(std::vector<Linked> linked){
    ///ui->tableIdComputer->clearContents();
    ui -> tableTableLink -> verticalHeader() -> setVisible(false);
    ui -> tableTableLink -> setRowCount(linked.size());

    for (unsigned int row = 0; row < linked.size(); row++)
    {
        Linked currentLink = linked.at(row);

        ui->tableTableLink->setItem(row, 0, new QTableWidgetItem(_paddId(currentLink.getScientist().getId())));
        ui->tableTableLink->setItem(row, 1, new QTableWidgetItem(QString::QString::fromStdString(currentLink.getScientist().getName())));
        ui->tableTableLink->setItem(row, 2, new QTableWidgetItem(_paddId(currentLink.getComputer().getId())));
        ui->tableTableLink->setItem(row, 3, new QTableWidgetItem(QString::QString::fromStdString(currentLink.getComputer().getName())));

    }
    displayedLinked = linked;
}

void MainWindow::on_tableScientist_clicked()
{
        string male = "Male";
        string female = "Female";
        int selectedScientistIndex = ui -> tableScientist -> currentIndex().row();
        Scientist selectedScientist = displayedScientist.at(selectedScientistIndex);
        ui -> addScientistName -> setText(QString::fromStdString(selectedScientist.getName()));
        ui -> addScientistBirth -> setCurrentText(QString::number(selectedScientist.getBirth()));
        if(selectedScientist.getDeath() == 0)
            ui -> addScientistDeath -> setCurrentText(QString::fromStdString("Alive"));
        else
            ui -> addScientistDeath -> setCurrentText(QString::number(selectedScientist.getDeath()));
        ui -> addScientistNationality -> setCurrentText(QString::fromStdString(selectedScientist.getCountry()));
        if (selectedScientist.getGender() == 'M')
            ui -> addScientistGender -> setCurrentText(QString::fromStdString(male));
        else
            ui -> addScientistGender -> setCurrentText(QString::fromStdString(female));  
}

void MainWindow::on_editScientist_clicked()
{
    int selectedScientistIndex = ui -> tableScientist -> currentIndex().row();
    Scientist selectedScientist = displayedScientist.at(selectedScientistIndex);
    int id = selectedScientist.getId();
    string name = ui -> addScientistName -> text().toStdString();
    string gender = ui -> addScientistGender -> currentText().toStdString();
    string birth = ui -> addScientistBirth -> currentText().toStdString();
    string death = ui -> addScientistDeath -> currentText().toStdString();
    string country = ui -> addScientistNationality -> currentText().toStdString();

    int birthint = atoi(birth.c_str());
    int deathint = atoi(death.c_str());

    if(!_valid.nameCheck(name)) {
        QMessageBox::warning(this, "Name wrong", "This name is illegal. Try again!");
        ui -> addScientistName -> setText(QString::fromStdString(selectedScientist.getName()));
    }

    else {
        Scientist editedScientist = Scientist(name, toupper(gender.at(0)), birthint, deathint, country);
        QMessageBox::StandardButton check;
        check = QMessageBox::question(this, "Scientist Edit", "Are you sure you've edited the information correctly?",
                                                QMessageBox::Yes|QMessageBox::No);
        if (check == QMessageBox::Yes) {
            bool success = _service.editScientist(id, editedScientist);

            if(success) {
            QMessageBox::information(this, "Scientist edited", "This scientist has been edited in the database");
            ui -> tableScientist -> clearContents();
            ui -> addScientistName -> clear();
            ui -> addScientistBirth -> setCurrentText(QString::number(2016));
            ui -> addScientistDeath -> setCurrentText(QString::fromStdString("Alive"));
            ui -> addScientistNationality -> setCurrentText(QString::fromStdString("Afghan"));
            ui -> addScientistGender -> setCurrentText(QString::fromStdString("Male"));
            }

            else {
                QMessageBox::information(this, "Database error", "Error updating the database");
            }
         }
         else if (check == QMessageBox::No) {
            string male = "Male";
            string female = "Female";
            ui -> addScientistName -> setText(QString::fromStdString(selectedScientist.getName()));
            ui -> addScientistBirth -> setCurrentText(QString::number(selectedScientist.getBirth()));
            ui -> addScientistDeath -> setCurrentText(QString::number(selectedScientist.getDeath()));
            ui -> addScientistNationality -> setCurrentText(QString::fromStdString(selectedScientist.getCountry()));
            if (selectedScientist.getGender() == 'M')
                ui -> addScientistGender -> setCurrentText(QString::fromStdString(male));
            else
                ui -> addScientistGender -> setCurrentText(QString::fromStdString(female));
         }
         else {
            MainWindow();
         }
    }
    DisplayAllScientists();
    DisplayAllIdScientists();
}

void MainWindow::on_tableComputer_clicked()
{
    string built = "Built";
    string notbuilt = "Not Built";
    int selectedComputerIndex = ui -> tableComputer -> currentIndex().row();
    Computer selectedComputer = displayedComputer.at(selectedComputerIndex);
    ui -> addComputerName-> setText(QString::fromStdString(selectedComputer.getName()));
    ui -> addComputerType -> setText(QString::fromStdString(selectedComputer.getType()));
    ui -> addComputerYear -> setCurrentText(QString::number(selectedComputer.getBuildy()));
    if (selectedComputer.getBuilt())
        ui -> ddmComputerBuilt -> setCurrentText(QString::fromStdString(built));
    else
        ui -> ddmComputerBuilt -> setCurrentText(QString::fromStdString(notbuilt));
}

void MainWindow::on_editComputer_clicked()
{
    int selectedComputerIndex = ui -> tableComputer -> currentIndex().row();
    Computer selectedComputer = displayedComputer.at(selectedComputerIndex);
    int id = selectedComputer.getId();
    string name = ui -> addComputerName -> text().toStdString();
    string type = ui -> addComputerType -> text().toStdString();
    string year = ui -> addComputerYear -> currentText().toStdString();
    string built = ui -> ddmComputerBuilt -> currentText().toStdString();

    bool builtbool;
    int yearint = atoi(year.c_str());
    if(built == "Built")
        builtbool = true;
    else
        builtbool = false;

    if(!_valid.cpuCheck(name)) {
        QMessageBox::warning(this, "Name wrong", "This name is illegal. Try again!");
        ui -> addComputerName -> setText(QString::fromStdString(selectedComputer.getName()));
    }

    else {
        Computer editedComputer = Computer(name, yearint, type, builtbool);
        QMessageBox::StandardButton check;
        check = QMessageBox::question(this, "Computer Edit", "Are you sure you've edited the information correctly?",
                                                QMessageBox::Yes|QMessageBox::No);
        if (check == QMessageBox::Yes) {
            bool success = _service.editComputer(id, editedComputer);

            if(success) {
                QMessageBox::information(this, "Computer edited", "This computer has been edited in the database");
                ui -> tableComputer -> clearContents();
                ui -> addComputerName -> clear();
                ui -> addComputerType -> clear();
                ui -> addComputerYear -> setCurrentText(QString::number(2016));
                ui -> ddmComputerBuilt -> setCurrentText(QString::fromStdString("Built"));
            }
            else {
                QMessageBox::information(this, "Database error", "Error updating the database");
            }
        }
        else if (check == QMessageBox::No) {
            string built = "Built";
            string notbuilt = "Not Built";
            ui -> addComputerName-> setText(QString::fromStdString(selectedComputer.getName()));
            ui -> addComputerType -> setText(QString::fromStdString(selectedComputer.getType()));
            ui -> addComputerYear -> setCurrentText(QString::number(selectedComputer.getBuildy()));
            if (selectedComputer.getBuilt()) {
                ui -> ddmComputerBuilt -> setCurrentText(QString::fromStdString(built));
            }
            else {
                ui -> ddmComputerBuilt -> setCurrentText(QString::fromStdString(notbuilt));
            }
        }
        else {
           MainWindow();
        }
    }
    DisplayAllComputers();
    DisplayAllIdComputers();
}


void MainWindow::on_addTableLink_clicked()
{
    string scientistId = ui -> addTableLinkSID -> text().toStdString();
    string computerId = ui -> addTableLinkCID -> text().toStdString();

    int scientistIdInt = atoi(scientistId.c_str());
    int computerIdInt = atoi(computerId.c_str());

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Link", "Are you sure the information is correct?",
                                                QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        if(_service.link(computerIdInt, scientistIdInt))
            QMessageBox::information(this, "Link", "This link has been added to the database!");
        else
            QMessageBox::information(this, "Link", "This link has failed!");
        ui -> addTableLinkSID -> clear();
        ui -> addTableLinkCID -> clear();
    }
    else {
        MainWindow();
    }
    DisplayAllLinked();
}


void MainWindow::on_tableIdScientist_clicked()
{
    int selectedScientistIndex = ui -> tableIdScientist -> currentIndex().row();
    Scientist selectedScientist = displayedScientist.at(selectedScientistIndex);
    ui -> addTableLinkSID -> setText(QString::number(selectedScientist.getId()));
}

void MainWindow::on_tableIdComputer_clicked()
{
    int selectedComputerIndex = ui -> tableIdComputer -> currentIndex().row();
    Computer selectedComputer = displayedComputer.at(selectedComputerIndex);
    ui -> addTableLinkCID -> setText(QString::number(selectedComputer.getId()));
}

QString MainWindow::_paddId(int iId)
{
    string id = to_string(iId);
    if(constants::padding > id.size())
        id.insert(0,constants::padding - id.size(), ' ');
    return QString::fromStdString(id);
}

void MainWindow::on_tableTableLink_clicked(const QModelIndex &index)
{
    if(ui->tableTableLink->currentItem()->isSelected() == true)
        ui->deleteTableLink->setEnabled(true);
    else
        ui->deleteTableLink->setEnabled(false);
}

void MainWindow::on_deleteTableLink_clicked()
{
    int selectedLinkIndex = ui -> tableTableLink -> currentIndex().row();
    Linked selectedLink = displayedLinked.at(selectedLinkIndex);
    bool success = _service.unLink(selectedLink.getComputer().getId(), selectedLink.getScientist().getId());

    if(success)
    {
        ui -> filterLinkedTables -> setText("");
        DisplayAllLinked();

        ui -> deleteTableLink -> setEnabled(false);
    }
    else
    {
        QMessageBox::warning(this, "Failed", "Failed to delete");
    }
    ui -> deleteTableLink -> setDisabled(true);
}
