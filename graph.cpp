#include "graph.h"
#include "ui_graph.h"
#include "mainwindow.h"
graph::graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);

}
graph::~graph()
{
    delete ui;
}
int h=1;
class T
{
    private:

    public:
    int t=1;
    int A=1;//amplituda
    int m=1;//мода
    int n=0;//мода
    double c= 3*pow(10,8), //скорость света
    w=200000000,  //частота
    e=1, //эпсилон ε диэлектрическая проницаемость среды
    u=1; //ню μ магнитная проницаемость среды
    double K,k,h,Z0,ZTE,ZTM,wkr,l,lkr,lv,vf,vgp;


};
class TE: public T
{
    public:
    double a,b;//np.pi#размер волновода по х,размер волновода по у

    double Ex(double x,double y,double z);
    double Ey(double x,double y,double z);
    double Hx(double x,double y,double z);
    double Hy(double x,double y,double z);
    double Hz(double x,double y,double z);
    void add(double A,double B,double M,double N,double W)
    {
        a=A;
        b=B;
        m=M;
        n=N;
        w=W;
        K=sqrt(pow((m*M_PI/a),2)+pow((n*M_PI/b),2));// χ каппа поперечное волновое число
        k=w/c*sqrt(e*u);// волновое число
        h=sqrt(pow(k,2)-pow(K,2));// продольное волновое число
        Z0=sqrt(u/e);//волновой импеданс
        ZTE=Z0*k/h;
        ZTM=Z0*h/k;
        wkr=K*c;//критическая частота
        l=2*M_PI/k;//длина волны в свободном пространстве
        lkr=2*M_PI/K;//лина волны критическая
        lv=2*M_PI/h;//длина волны в волноводе
        vf=w/h;//фазовая скорость
        vgp=pow(c,2)/vf;//групповая скорость
    }
   // double Ez(double x,double y,double z) return 0;
};

class TM: public T
{
    public:
     double a,b;
    double Ex(double x,double y,double z);
    double Ey(double x,double y,double z);
    double Ez(double x,double y,double z);
    double Hx(double x,double y,double z);
    double Hy(double x,double y,double z);
   // double Hz(double x,double y,double z) return 0;
};
    double TE::Ex(double x,double y,double z)
      {return ((-A*w*((M_PI * n) / b) /(K*K)) * cos((M_PI * m * x) / a) * sin((M_PI * n * y) / b)*sin(w*t-h*z));}
    double TE::Ey(double x,double y,double z)
      { return ((A*w*((M_PI * m) / a) /(K*K)) * sin((M_PI * m * x) / a) * cos((M_PI * n * y) / b)*sin(w*t-h*z));}
    double TE::Hx(double x,double y,double z)
      {return   ((-A*h*((M_PI * m) / a) /(K*K)) *sin((M_PI * m * x) / a) * cos((M_PI * n * y) / b)*sin(w*t-h*z));}
    double TE::Hy(double x,double y,double z)
      { return ((-A*h*((M_PI * n) / b) /(K*K)) * cos((M_PI * m * x) / a) * sin((M_PI * n * y) / b)*sin(w*t-h*z));}
    double TE::Hz(double x,double y,double z)
      { return (A * cos((M_PI* m * x) / a) * cos((M_PI * n * y) / b)*cos(w*t-h*z));}



    double TM::Ex(double x,double y,double z)
      {return ((A*h*((M_PI * m) / a) /(K*K)) * cos((M_PI * m * x) / a) * sin((M_PI * n * y) / b)*sin(w*t-h*z));}
    double TM::Ey(double x,double y,double z)
      { return ((A*h*((M_PI * n) / b) /(K*K)) * sin((M_PI * m * x) / a) * cos((M_PI * n * y) / b)*sin(w*t-h*z));}
    double TM::Ez(double x,double y,double z)
      {return   (A * sin((M_PI * m * x) / a) * sin((M_PI * n * y) / b)*cos(w*t-h*z));}
    double TM::Hx(double x,double y,double z)
      { return ((-A*w*((M_PI * n) / b) /(K*K)) * sin((M_PI * m * x) / a) * cos((M_PI * n * y) / b)*sin(w*t-h*z));}
    double TM::Hy(double x,double y,double z)
      { return ((A*w*((M_PI * m) / a) /(K*K)) * cos((M_PI * m * x) / a) * sin((M_PI * n * y) / b)*sin(w*t-h*z));}
TE exampleTE;


void graph::recieveData(double a,double b,double m,double n,double w,bool TEorTM)
{

    QString nedw;
    nedw= QString::number(a)+" ";
    nedw+= QString::number(b)+" ";
    nedw+= QString::number(m)+" ";
    nedw+= QString::number(n)+" ";
    nedw+= QString::number(w)+" ";
    nedw+= QString::number(TEorTM);
    exampleTE.add(a,b,m,n,w);
    ui->lineEdit->setText(nedw);

//    xBegin_w1=0;
//    yBegin_w1=0;
//    xBegin_w2=0;
  //  yBegin_w2=0;
 //   xBegin_w3=0;
 //   yBegin_w3=0;
   // xEnd_w1=a;
    //xEnd_w2=a;
    //yEnd_w2=b;
   // yEnd_w1=10;
    ui->widget_1->xAxis->setRange(0,a);
    ui->widget_1->yAxis->setRange(0,b);
    ui->widget_2->xAxis->setRange(0,2*a);
    ui->widget_2->yAxis->setRange(0,b);
    ui->widget_3->xAxis->setRange(0,21);
    ui->widget_3->yAxis->setRange(-50,50);
  //  X_w1=0;
 //   Y_w1=0;
 //   x_w1.clear();
  //  y_w1.clear();


  //  x_w2.clear();
  //  y_w2.clear();
  //  X_w2=xBegin_w2;
  //  Y_w2=yBegin_w2;
  //  timer_w2= new QTimer(this);
  //  connect(timer_w2,SIGNAL(timeout()),this,SLOT(TimerSlot_w2()));
  //  ui->widget_2->clearGraphs();
  //  timer_w2->start(20);


}

void graph::TimerSlot_w1()
{
    double xEnd=exampleTE.a;
    double yEnd=exampleTE.b;
    double X=0,Y=0;
    double Z=0;
    int time=0;
    //Ex(y)
    QVector<double> x,y;
    if(time<=20*yEnd)
    {

         while(X<=xEnd)
             {
               x.push_back(X);
               y.push_back(exampleTE.Ey(X,Y,Z));
               X+=1;


             }     // Y+=(h/2);

         ui->widget_1->addGraph()->addData(x, y);

       //  ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssTriangle , 10));
         x.clear();
         y.clear();

         Y+=h;
         X=0;
         Z+=h;
        time+=20;
    }
    else
    {
        time=0;
        timer_w1->stop();
     }

  //  ui->widget->addGraph()->setData(x, y);
    ui->widget_1->replot();
}


void graph::on_pushButton_clicked()
{
    timer_w1= new QTimer(this);
    connect(timer_w1,SIGNAL(timeout()),this,SLOT(TimerSlot_w1()));
    ui->widget_1->clearGraphs();
    timer_w1->start(20);
}
