#include "master.h"
#include "ui_master.h"
#include "film.h"
#include <QString>

master::master(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::master)
{
    ui->setupUi(this);
}

master::~master()
{
    delete ui;
}

void master::setFilmDetails(int number, film film)
{
    ui->lineEdit->setText(QString::fromStdString(film.movie_title));
    ui->lineEdit_2->setText(QString::fromStdString(film.release_date));
    ui->lineEdit_3->setText(QString::fromStdString(film.genre));
    ui->lineEdit_4->setText(QString::fromStdString(film.mpaa_rating));
    ui->lineEdit_5->setText(QString::fromStdString(film.total_gross));
    ui->lineEdit_6->setText(QString::fromStdString(film.inflation_adjusted_gross));
}

