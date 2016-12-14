#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "scientist.h"
#include <QMainWindow>
#include <string>
#include "service.h"
#include "inputcheck.h"
#include "linked.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void DisplayAllScientists();
    void DisplayScientists(std::vector<Scientist> scientists);
    void DisplayAllComputers();
    void DisplayComputers(std::vector<Computer> computers);
    void DisplayAllIdScientists();
    void DisplayIdScientists(std::vector<Scientist> scientists);
    void DisplayAllIdComputers();
    void DisplayIdComputers(std::vector<Computer> computers);
    void DisplayAllLinked();
    void DisplayLinked(std::vector<Linked> linked);
    void on_addScientist_clicked();
    void on_deleteScientist_clicked();
    void on_addComputer_clicked();

    void on_listScientist_clicked(const QModelIndex &index);
    //void on_listComputer_clicked(const QModelIndex &index);
    void on_tableScientist_clicked(const QModelIndex &index);
    void on_tableComputer_clicked(const QModelIndex &index);
    void on_filterScientistsList_textChanged(const QString &arg1);
    void on_filterComputers_textChanged(const QString &arg1);

    void on_ddmSortScientists_currentIndexChanged(int index);
    void on_ddmComputerSort_currentIndexChanged(int index);
    void on_deleteComputer_clicked();

private:
    Ui::MainWindow *ui;
    Service _service;
    inputcheck _valid;
    std::vector<Scientist> displayedScientist;
    std::vector<Computer> displayedComputer;
    std::vector<Linked> displayedLinked;
    int _orderBy;
};

#endif // MAINWINDOW_H
