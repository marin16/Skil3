#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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

    ui -> ddmScientistGender -> addItem("Male");
    ui -> ddmScientistGender -> addItem("Female");

    ui -> ddmTableLink -> addItem("Link Sort");

}

MainWindow::~MainWindow()
{
    delete ui;
}

