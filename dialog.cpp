#include "dialog.h"
#include "film.h"
#include "ui_dialog.h"
#include <set>
#include <iterator>
#include "error.h"
#include <QMessageBox>
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

std::set<QString> genres;
void Dialog::fillgenres()
{


    int rows = pointerToModel->rowCount();
    for (int i=1; i<rows;i++)
    {
       QModelIndex index = pointerToModel->index(i,2,QModelIndex());
        QString gen= pointerToModel->data(index).toString();
        genres.insert(gen);
    }
    for(std::set<QString>::iterator it=genres.begin(); it!=genres.end();++it)
    {
        ui->comboBox->addItem(*it);
    }
}


void Dialog::fillcombo()
{
   fillgenres();
   for(std::set<QString>::iterator it=genres.begin(); it!=genres.end();++it)
   {
       ui->comboBox->addItem(*it);
   }
}
void Dialog::chekdate()
{
   std::string data = ui->lineEdit_2->text().toStdString();

   if(data.length()!=10 || data[4]!='-' || data[7]!='-')
   {
       QMessageBox a;
       a.setText("Wrong Data Format");
       a.exec();
   }
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
    pointerToModel->setData(index,ui->comboBox->currentText());

    index = pointerToModel->index(row,3,QModelIndex());
    pointerToModel->setData(index,ui->lineEdit_5->text());

    std::string mpaa_rating = ui->lineEdit_4->text().toStdString();
    std::string inflation_gross = ui->lineEdit_6->text().toStdString();
    pointerToFilmData->setdetais(mpaa_rating,inflation_gross,row);



}





void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
     fillcombo();
}

void Dialog::on_lineEdit_2_editingFinished()
{
    chekdate();
}
