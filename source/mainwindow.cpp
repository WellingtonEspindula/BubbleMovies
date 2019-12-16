#include <QDebug>
#include <QMessageBox>
#include <QStandardItem>
#include "../header/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(QWidget *parent, structures_handler *structures) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->structures = *structures;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_commandLinkButton_clicked()
{
    string str_query = ui->lineEdit->text().toStdString();
    query(this->structures, str_query);
    cout << "\n" << endl;

//   QMessageBox msgBox;
//   msgBox.setText(ui->lineEdit->text());
//   msgBox.exec();

//    QStandardItemModel *model = new QStandardItemModel(2,3,this); //2 Rows and 3 Columns
//    model->setHorizontalHeaderItem(0, new QStandardItem(QString("x")));
//    model->setHorizontalHeaderItem(1, new QStandardItem(QString("y")));
//    model->setHorizontalHeaderItem(2, new QStandardItem(QString("z")));


//    for (auto model->) {
//           Property *property = propertiesList.at(row);
//           addRow();
//           model->setItemData(row, 0)->setData(Qt::DisplayRole, property->propertyName());
//           tableWidget->item(row, 1)->setData(Qt::DisplayRole, property->propertyType());
//           tableWidget->item(row, 2)->setData(Qt::DisplayRole, property->propertyValue());
//           tableWidget->item(row, 3)->setData(Qt::DisplayRole, property->propertyUnit());
//     }

//    QStandardItem *item1 = new QStandardItem(QString("abc"));
//    model->insertRow(1, item1);

//   ui->tableView->setModel(model);
//   ui->tableView->setRowCount(50);
//    ui->tableWidget->set
}
