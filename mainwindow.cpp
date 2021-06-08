#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "film.h"
#include "dialog.h"
#include "master.h"
#include "customproxy.h"
#include "about.h"
#include <iostream>
#include <QAction>
#include <sstream>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel(0, 3, this);
    model->setHorizontalHeaderItem(0, new QStandardItem("Name"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Date"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Genre"));
    /*model->setHorizontalHeaderItem(3, new QStandardItem("Rating"));*/
    model->setHorizontalHeaderItem(3, new QStandardItem("Total Gross"));
    /*model->setHorizontalHeaderItem(5, new QStandardItem("Revenue2"));*/
    filmdata = new FilmData(model);   
    proxyModel= new customproxy();
    proxyModel->setSourceModel(model);
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
    QObject::connect(model, &QStandardItemModel::dataChanged, filmdata, &FilmData::update );
    QObject::connect(model, &QStandardItemModel::rowsRemoved, filmdata, &FilmData::remove );

    /*QPixmap bkgnd("C:\\progect\\BIG_HW\\logo.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);*/


}

MainWindow::~MainWindow()
{
    delete ui;
    delete filmdata;
    delete model;

}


void MainWindow::on_pushButton_clicked()
{
    Dialog dialog;
    dialog.setDataPointer(filmdata);
    dialog.setModelPointer(model);
    dialog.setModal(true);
    dialog.exec();
    funct();
}


void MainWindow::on_pushButton_3_clicked()
{
    if(proxyModel->rowCount()!=0 & model->rowCount()!=0)
    {

    QModelIndex proxyIndex = ui->tableView->currentIndex();
        QModelIndex modelIndex = proxyModel->mapToSource(proxyIndex);
        int row = modelIndex.row();
       model->removeRows(row,1);
       funct();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    filmdata->save(this);
}

void MainWindow::on_pushButton_5_clicked()
{
    filmdata->open(this);
    funct();
}

void MainWindow::on_pushButton_6_clicked()
{
    if(proxyModel->rowCount()!=0 & model->rowCount()!=0)
    {

        master master;
        QModelIndex proxyIndex = ui->tableView->currentIndex();
        QModelIndex modelIndex = proxyModel->mapToSource(proxyIndex);
        int row = modelIndex.row();
        film film1 = filmdata->getFilm(row);
        master.setFilmDetails(row, film1);
        master.setModal(true);
        master.exec();
    }



}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{

    ui->pushButton_3->setEnabled(true);
    ui->pushButton_6->setEnabled(true);

}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
   proxyModel->setFilterSubstr(arg1);

}

void MainWindow::funct()
{
    unsigned long long int sum = 0;
    for(int row = 0; row < model->rowCount(); row++)
    {
        QModelIndex index = model->index(row,3);
        int cellValue = (index.data().toString()).toInt();
        sum+=cellValue;
    }
    std::stringstream ss;
    ss << sum;
    std::string ans = ss.str();
    ui->lineEdit->setText(QString::fromStdString(ans));
}

void MainWindow::on_actionAbout_triggered()
{
    About about;
        about.setModal(true);
        about.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(proxyModel->rowCount()!=0 & model->rowCount()!=0)
    {
    int w = QRandomGenerator::global()->bounded(0,proxyModel->rowCount());
    QModelIndex index = proxyModel->index(w,0);
    master master;
    QModelIndex proxyIndex = index;
    QModelIndex modelIndex = proxyModel->mapToSource(proxyIndex);
    int row = modelIndex.row();
    film film1 = filmdata->getFilm(row);
    master.setFilmDetails(row, film1);
    master.setModal(true);
    master.exec();
    }



}
