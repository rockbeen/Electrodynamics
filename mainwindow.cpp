#include "mainwindow.h"
#include "ui_mainwindow.h"
class TE
{
    private:
    double e=1,x,y,m,n,a,b;
    public:

    double Ex(double x,double y,double m,double n,double a,double b,double e);
    double Ey(double x,double y,double m,double n,double a,double b,double e);
    double Ez(double x,double y,double m,double n,double a,double b,double e);


};
 double TE::Ex(double x,double y,double m,double n,double a,double b,double e)
 {
     return (-e *((M_PI * m) / a)* cos((M_PI * m * x) / a) * sin((M_PI * n * y) / b))/(pow((m*M_PI/a),2)+pow((n*M_PI/b),2));
 }
 double TE::Ey(double x,double y,double m,double n,double a,double b,double e)
 {
     return (e*(n*M_PI/b)*sin((M_PI * m * x) / a) * cos((M_PI * n * y) / b))/(pow((m*M_PI/a),2)+pow((n*M_PI/b),2));
 }
   TE exampleTE;
   double m=2,n=1,a=20,b=10;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h=1;
    xBegin_w1=0;
    yBegin_w1=0;
    xBegin_w2=0;
    yBegin_w2=0;
    xEnd_w1=a+h;
    xEnd_w2=a+h;
    ui->widget->xAxis->setRange(0,21);
    ui->widget->yAxis->setRange(0,50);
    ui->widget_2->xAxis->setRange(0,21);
    ui->widget_2->yAxis->setRange(0,50);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   //w1
    time=0;
    X=xBegin_w1;
    Y=yBegin_w1;
    x.clear();
    y.clear();
    timer_w1= new QTimer(this);
    connect(timer_w1,SIGNAL(timeout()),this,SLOT(TimerSlot_w1()));
    ui->widget->clearGraphs();
    timer_w1->start(20);
    x_w2.clear();
    y_w2.clear();
    X_w2=xBegin_w2;
    Y_w2=yBegin_w2;
    timer_w2= new QTimer(this);
    connect(timer_w2,SIGNAL(timeout()),this,SLOT(TimerSlot_w2()));
    ui->widget_2->clearGraphs();
    timer_w2->start(20);


}

void MainWindow::TimerSlot_w1()
{
    //Ey(x)
   if(time<=20*xEnd_w1)
   {

       if(X<=xEnd_w1)
       {
              x.push_back(X);
              y.push_back(exampleTE.Ey(X, Y, m, n, a, b, a));
              X+=h;
              Y+=(h/2);
       }
       time+=(20/xEnd_w1);
   }
   else
   {
       time=0;
       timer_w1->stop();

   }
   ui->widget->addGraph();
   ui->widget->graph(0)->addData(x,y);
   ui->widget->replot();
}
void MainWindow::TimerSlot_w2()
{
    //Ex(y)
   if(time<=20*xEnd_w2)
   {

       if(X_w2<=xEnd_w2)
       {
              x_w2.push_back( Y_w2);
              y_w2.push_back(exampleTE.Ex(X_w2, Y_w2, m, n, a, b, a));
              X_w2+=h;
              Y_w2+=(h/2);
       }
       time+=20;
   }
   else
   {
       time=0;
       timer_w2->stop();

   }
   ui->widget_2->addGraph();
   ui->widget_2->graph(0)->addData(x_w2,y_w2);
   ui->widget_2->replot();
}






void MainWindow::on_pushButton_2_clicked()
{

}
