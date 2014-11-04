#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    c = new ZRainbowColor;
    c->setRange(256);
    c->buildColorBar();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    color* co = c->colorBar();
    for(int i = 0;i<256;i++)
    {
//        qDebug()<<i<<co[i].r<<co[i].g<<co[i].b;
        p.fillRect(i*4,50,3,20,QBrush(QColor(co[i].r,co[i].g,co[i].b)));
    }
}
