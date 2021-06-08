#ifndef MASTER_H
#define MASTER_H

#include <QDialog>
#include <film.h>


namespace Ui {
class master;
}

class master : public QDialog
{
    Q_OBJECT

public:
    explicit master(QWidget *parent = nullptr);
    ~master();

    void setFilmDetails(int number, film film);

private:
    Ui::master *ui;

    film filmdetails;
};

#endif // MASTER_H
