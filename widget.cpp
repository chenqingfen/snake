#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveEvent()));speed=50;
    timer->start(speed);
    direction=1;
    snakebody=3;


     label[0]=new QLabel(this);
     label[0]->setGeometry(180,240,30,30);
     label[0]->setPixmap(QPixmap("9.png"));

     label[1]=new QLabel(this);
     label[1]->setGeometry(210,240,30,30);
     label[1]->setPixmap(QPixmap("food.png"));

     label[2]=new QLabel(this);
     label[2]->setGeometry(240,240,30,30);
     label[2]->setPixmap(QPixmap("food.png"));

}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_3_clicked()
{
    direction=1;
}

void Widget::on_pushButton_4_clicked()
{
    direction=2;
}

void Widget::on_pushButton_clicked()
{
    direction=3;
}

void Widget::on_pushButton_2_clicked()
{
    direction=4;
}
void Widget::moveEvent()
{
    int tailsnakex=label[snakebody-1]->pos().x();
    int tailsnakey=label[snakebody-1]->pos().y();


    for(int i=snakebody-1;i>0;i--)
    {
        int x=label[i-1]->pos().x();
        int y=label[i-1]->pos().y();
        label[i]->setGeometry(x,y,30,30);;

    }
    int headsnakex=label[0]->pos().x();
    int headsnakey=label[0]->pos().y();
    int bordersnakex=label[0]->pos().x();
    int bordersnakey=label[0]->pos().y();

    if(direction==1)
    {
        label[0]->setGeometry(headsnakex,headsnakey-30,30,30);
        if(bordersnakey<0)
        {
            label[0]->setGeometry(bordersnakex,420,30,30);
        }
    }
    else if(direction==2)
    {
        label[0]->setGeometry(headsnakex-30,headsnakey,30,30);
        if(bordersnakex<0)
        {
            label[0]->setGeometry(420,bordersnakey,30,30);
        }
    }
    else if(direction==3)
    {
        label[0]->setGeometry(headsnakex+30,headsnakey,30,30);
        if(bordersnakex>=420)
        {
            label[0]->setGeometry(0,bordersnakey,30,30);
        }
    }
    else
    {
        label[0]->setGeometry(headsnakex,headsnakey+30,30,30);
        if(bordersnakey>=420)
        {
            label[0]->setGeometry(bordersnakex,0,30,30);
        }
    }
    int foodx=ui->food->pos().x();
    int foody=ui->food->pos().y();
    int newsnakeheadx=label[0]->pos().x();
    int newsnakeheady=label[0]->pos().y();
    if(newsnakeheadx==foodx&&newsnakeheady==foody)
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        int RandomFoodx=qrand()%9+1;
        int RandomFoody=qrand()%9+1;//对9取余，对x取余就%x

        ui->food->setGeometry(RandomFoodx*30,RandomFoody*30,30,30);

        label[snakebody]=new QLabel(this);
        label[snakebody]->setGeometry(tailsnakex,tailsnakey,30,30);
        label[snakebody]->setPixmap(QPixmap("food.png"));
        label[snakebody]->show();
        snakebody++;
        timer->start(speed-10);
    }
}



