#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "film.h"
#include <QStandardItemModel>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setModelPointer(QStandardItemModel* pointerToModel);
    void setDataPointer(FilmData* filmdata);
    void fillgenres();
    void fillcombo();
    void chekdate();

private slots:
    void on_pushButton_clicked();



    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_editingFinished();

private:
    Ui::Dialog *ui;
    QStandardItemModel* pointerToModel;
    FilmData* pointerToFilmData;
};

#endif // DIALOG_H
