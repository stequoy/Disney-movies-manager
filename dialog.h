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

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QStandardItemModel* pointerToModel;
    FilmData* pointerToFilmData;
};

#endif // DIALOG_H
