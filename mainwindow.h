#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTimer>
#include "graph.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void sendData(double,double,double,double,double,bool);
private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    graph *windowGraph;

};
#endif // MAINWINDOW_H
