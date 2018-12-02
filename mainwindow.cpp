#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "resizer.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->fileNames=QFileDialog::getOpenFileNames(this,tr("Select images"),"/home/adrianek/Desktop","images (*.*)");

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setText("");
    Resizer r;
    r.start(this->fileNames,this->ui->spinBox->value(),this->ui->spinBox_2->value());
    ui->label->setText("DONE!");
}
