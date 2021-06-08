#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <film.h>
#include "customproxy.h"
#include <QSortFilterProxyModel>
#include <QStandardItemModel>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_lineEdit_2_textChanged(const QString &arg1);
    void funct();
    void on_actionAbout_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    FilmData* filmdata;
    QStandardItemModel* model;
    customproxy* proxyModel ;
    QAction* about;

};
#endif // MAINWINDOW_H
