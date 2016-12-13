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
    void on_addScientist_clicked();
    void displayScientist(Scientist scientist);

private:
    Ui::MainWindow *ui;
    Service serviceScientist;
};

#endif // MAINWINDOW_H
