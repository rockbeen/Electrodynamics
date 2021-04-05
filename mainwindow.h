#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void TimerSlot_w1();
    void TimerSlot_w2();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    double xBegin_w1,xEnd_w1,h,X,yBegin_w1,yEnd_w1,Y;
    double xBegin_w2,xEnd_w2,yBegin_w2,yEnd_w2,X_w2,Y_w2;
    int N;
    QVector<double> x,y;
    QVector<double> x_w2,y_w2;
    QTimer *timer_w1,*timer_w2;
    int time,time_w2=0;


};
#endif // MAINWINDOW_H
