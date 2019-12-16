#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "api.h"

#ifndef QT_GUI
#define QT_GUI
#include <QDebug>
#include <QMessageBox>
#include <QStandardItem>
#include <QMainWindow>
#endif


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(QWidget *parent = nullptr, structures_handler *structures = nullptr);
    void alert(string msg);
    ~MainWindow();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::MainWindow *ui;
    structures_handler structures;
};

#endif // MAINWINDOW_H
