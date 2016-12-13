#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "scientist.h"
#include <QMainWindow>
#include <string>
#include "service.h"
#include "inputcheck.h"

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
    void DisplayScientist(Scientist scientist);
    void on_addScientist_clicked();

    void on_listScientist_clicked(const QModelIndex &index);

    void on_listComputer_clicked(const QModelIndex &index);

    void on_tableScientist_clicked(const QModelIndex &index);

    void on_tableComputer_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Service _service;
    inputcheck _valid;
};

#endif // MAINWINDOW_H
