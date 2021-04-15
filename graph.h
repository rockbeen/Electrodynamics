#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>

namespace Ui {
class graph;
}

class graph : public QDialog
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = nullptr);
    ~graph();
public slots:
    void recieveData(double,double,double,double,double,bool);
private slots:
    void TimerSlot_w1();
   // void TimerSlot_w2();
  //  void TimerSlot_w3();
    void on_pushButton_clicked();

private:
    Ui::graph *ui;
  //  double xBegin_w1,xEnd_w1,h,X_w1,yBegin_w1,yEnd_w1,Y_w1;
 //   double xBegin_w2,xEnd_w2,yBegin_w2,yEnd_w2,X_w2,Y_w2;
    // QVector<double> x_w1,y_w1,x_w2,y_w2,x_w3,y_w3;
     QTimer *timer_w1,*timer_w2,*timer_w3;
   //  int time_w1,time_w2,time_w3=0;
};

#endif // GRAPH_H
