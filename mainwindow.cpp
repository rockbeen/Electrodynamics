#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    windowGraph =new graph();
    connect(ui->pushButton, SIGNAL(clicked()), windowGraph, SLOT(show()));// подключаем сигнал к слоту (для нвого окна)
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked())); // подключаем клик по кнопке к определенному нами слоту
    connect(this, SIGNAL(sendData(double,double,double,double,double,bool)), windowGraph, SLOT(recieveData(double,double,double,double,double,bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    emit sendData(ui->line_a->text().toDouble(),ui->line_b->text().toDouble(),ui->spinBox_m->value(),ui->spinBox_n->value(),ui->frequency->text().toDouble(),
                  ui->radioButton_TE->isChecked()); // вызываем сигнал, в котором передаём введённые данные




}


