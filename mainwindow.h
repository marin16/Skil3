#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "scientist.h"
#include <QMainWindow>
#include <string>
#include "service.h"

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

private:
    Ui::MainWindow *ui;
    Service _service;
};

#endif // MAINWINDOW_H
