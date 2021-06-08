#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

void Dialog::setDataPointer(FilmData *filmdata)
{
    pointerToFilmData = filmdata;
}

void Dialog::setModelPointer(QStandardItemModel* model)
{
    pointerToModel = model;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    int row = pointerToModel->rowCount();
    pointerToModel->insertRows(row,1);

    QModelIndex index = pointerToModel->index(row,0,QModelIndex());
    pointerToModel->setData(index,ui->lineEdit->text());

    index = pointerToModel->index(row,1,QModelIndex());
    pointerToModel->setData(index,ui->lineEdit_2->text());

    index = pointerToModel->index(row,2,QModelIndex());
    pointerToModel->setData(index,ui->lineEdit_3->text());

    index = pointerToModel->index(row,3,QModelIndex());
    pointerToModel->setData(index,ui->lineEdit_5->text());

    std::string mpaa_rating = ui->lineEdit_4->text().toStdString();
    std::string inflation_gross = ui->lineEdit_6->text().toStdString();
    pointerToFilmData->setdetais(mpaa_rating,inflation_gross,row);

}
