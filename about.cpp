#include "about.h"
#include "ui_about.h"
#include <QPainter>

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}





void About::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    painter.setPen(Qt::darkCyan);
    painter.setBrush(QBrush(QBrush(Qt::darkCyan)));
    painter.drawEllipse(130,75,150,150);

    painter.setPen(Qt::red);
    painter.setBrush(QBrush(QBrush(Qt::red)));
    painter.drawEllipse(130,75,140,140);

    painter.setPen(Qt::darkCyan);
    painter.setBrush(QBrush(QBrush(Qt::darkCyan)));
    painter.drawEllipse(130,75,130,130);

    painter.setPen(Qt::yellow);
    painter.setBrush(QBrush(QBrush(Qt::yellow)));
    painter.drawEllipse(130,75,120,120);

    /*painter.setPen(Qt::blue);
    painter.setBrush(QBrush(QBrush(Qt::blue)));
    painter.drawEllipse(130,75,110,110);

    painter.setPen(Qt::white);
    painter.setBrush(QBrush(QBrush(Qt::white)));
    painter.drawEllipse(130,75,100,100);

    painter.setPen(Qt::blue);
    painter.setBrush(QBrush(QBrush(Qt::blue)));
    painter.drawEllipse(130,75,90,90);

    painter.setPen(Qt::white);
    painter.setBrush(QBrush(QBrush(Qt::white)));
    painter.drawEllipse(130,75,80,80);

    painter.setPen(Qt::blue);
    painter.setBrush(QBrush(QBrush(Qt::blue)));
    painter.drawEllipse(130,75,70,70);

    painter.setPen(Qt::white);
    painter.setBrush(QBrush(QBrush(Qt::white)));
    painter.drawEllipse(130,75,60,60);

    painter.setPen(Qt::darkCyan);
    painter.setBrush(QBrush(QBrush(Qt::darkCyan)));
    painter.drawEllipse(130,75,50,50);

    painter.setPen(Qt::darkRed);
    painter.setBrush(QBrush(QBrush(Qt::darkRed)));
    painter.drawEllipse(130,75,40,40);

    painter.setPen(Qt::darkCyan);
    painter.setBrush(QBrush(QBrush(Qt::darkCyan)));
    painter.drawEllipse(130,75,30,30);

    painter.setPen(Qt::white);
    painter.setBrush(QBrush(QBrush(Qt::white)));
    painter.drawEllipse(130,75,20,20);

    painter.setPen(Qt::darkCyan);
    painter.setBrush(QBrush(QBrush(Qt::darkCyan)));
    painter.drawEllipse(130,75,10,10);*/

    QImage image;
        image.load("alladin.png");
        QImage scaledImage = image.scaled(110, 110, Qt::KeepAspectRatio);
        painter.drawImage(160, 90, scaledImage);












}
