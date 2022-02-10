#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QDebug>
#include<QTime>
#include<QTimer>
#include<QLabel>
#include<QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QTimer*timer;
    int direction;
    int snakebody;
    QLabel*label[100];
    int speed;

private slots:
    void moveEvent();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
