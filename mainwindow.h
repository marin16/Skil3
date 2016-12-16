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
    /*
     * DisplayAllScientists: Used to display all scientist in the main scientist table.
     */
    void DisplayAllScientists();
    /*
     * DisplayScientists: Displays selected scientists in a table.
     * Params: vector<Scientist> scientists (Scientists to be displayed)
     */
    void DisplayScientists(std::vector<Scientist> scientists);
    /*
     * DisplayAllComputers: Used to display all computers in the main computer table.
     */
    void DisplayAllComputers();
    /*
     * DisplayComputers: Displays selected computers in a table.
     * Params: vector<Computer> computers (Computers to be displayed)
     */
    void DisplayComputers(std::vector<Computer> computers);
    /*
     * DisplayAllIdScientists: Displays all scientists ID and name in a table.
     */
    void DisplayAllIdScientists();
    /*
     * DisplayIdScientists: Displays selected scientists ID and name in a table.
     * Params: vector<Scientist> scientists (Scientists to be displayed)
     */
    void DisplayIdScientists(std::vector<Scientist> scientists);
    /*
     * DisplayAllIdComputers: Displays all computers ID and name in a table.
     */
    void DisplayAllIdComputers();
    /*
     * DisplayIdComputers: Displays selected computers ID and name in a table.
     * Params: vector<Computer> computers (Computers to be displayed)
     */
    void DisplayIdComputers(std::vector<Computer> computers);
    /*
     * DisplayAllLinked: Displays all links between scientists and computers.
     */
    void DisplayAllLinked();
    /*
     * DisplayLinked: Displays selected links between scientists and computers.
     * Params: vector<Linked> linked (Links to be displayed)
     */
    void DisplayLinked(std::vector<Linked> linked);
    /*
     * on_addScientist_clicked: Adds a new scientist to the table when add button is clicked.
     */
    void on_addScientist_clicked();
    /*
     * on_deleteScientist_clicked: Deletes a scientist from table when delete button is clicked.
     */
    void on_deleteScientist_clicked();
    /*
     * on_addComputer_clicked: Adds a new computer to the table when add button is clicked.
     */
    void on_addComputer_clicked();
    /*
     * on_deleteComputer_clicked: Deletes a computer from table when delete button is clicked.
     */
    void on_deleteComputer_clicked();
    /*
     * on_addTableLink_clicked: Add link between scientist and computer.
     */
    void on_addTableLink_clicked();
    /*
     * on_deleteTableLink_clicked: Delete link between scientist and computer.
     */
    void on_deleteTableLink_clicked();
    /*
     * on_tableScientist_clicked: Activates delete button when scientist in table is clicked.
     * Params: const QModelIndex &index (Scientist clicked in table)
     */
    void on_tableScientist_clicked(const QModelIndex &index);
    /*
     * on_tableComputer_clicked: Activates delete button when computer in table is clicked.
     * Params: const QModelIndex &index (Computer clicked in table)
     */
    void on_tableComputer_clicked(const QModelIndex &index);
    /*
     * on_tableTableLink_clicked: Activates delete button when link in table is clicked.
     * Params: const QModelIndex &index (Link clicked in table)
     */
    void on_tableTableLink_clicked(const QModelIndex &index);
    /*
     * on_filterScientistsList_textChanged: Used to filter scientist table.
     * Params: const QString &arg1 (Text to filter table by)
     */
    void on_filterScientistsList_textChanged(const QString &arg1);
    /*
     * on_filterComputers_textChanged: Used to filter computer table.
     * Params: const QString &arg1 (Text to filter table by)
     */
    void on_filterComputers_textChanged(const QString &arg1);
    /*
     * on_editScientist_clicked: Edits info on scientist when edit button is clicked.
     */
    void on_editScientist_clicked();
    /*
     * on_tableScientist_clicked: When moves info from table to add bars when scientist is clicked.
     */
    void on_tableScientist_clicked();
    /*
     * on_editComputer_clicked: Edits info on computer when edit button is clicked.
     */
    void on_editComputer_clicked();
    /*
     * on_tableComputer_clicked: When moves info from table to add bars when computer is clicked.
     */
    void on_tableComputer_clicked();
    /*
     * on_tableIdScientist_clicked: When moves info from table to add bars when scientist is clicked.
     */
    void on_tableIdScientist_clicked();
    /*
     * on_tableIdComputer_clicked: When moves info from table to add bars when computer is clicked.
     */
    void on_tableIdComputer_clicked();



private:
    Ui::MainWindow *ui;
    Service _service;
    inputcheck _valid;
    std::vector<Scientist> displayedScientist;
    std::vector<Computer> displayedComputer;
    std::vector<Linked> displayedLinked;
    int _orderBy;
    QString _paddId(int iId);
};

#endif // MAINWINDOW_H
