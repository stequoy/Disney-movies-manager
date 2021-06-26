#ifndef FILM_H
#define FILM_H

#include <string>
#include <iostream>
#include <vector>
#include <QStringList>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include <set>
#include <fstream>
#include <sstream>
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QStandardItemModel>

struct film
{
    std::string movie_title;
    std::string release_date;
    std::string genre;
    std::string mpaa_rating;
    std::string total_gross;
    std::string inflation_adjusted_gross;
};

class FilmData : public QObject
{
    Q_OBJECT

public:

    FilmData(QStandardItemModel* model)
    {

            pointerToModel = model;
            initModel();

    }

    void initModel()
            {

                for(int row = 0; row < _data.size(); row++)
                {
                    for(int col = 0; col < 6; col++)
                    {
                        QModelIndex index = pointerToModel->index(row, col, QModelIndex());
                        QString cellValue;
                        switch(col)
                        {
                            case 0: cellValue = QString::fromStdString(_data[row].movie_title);
                                    break;

                            case 1: cellValue = QString::fromStdString(_data[row].release_date);
                                    break;

                            case 2: cellValue = QString::fromStdString(_data[row].genre);
                                    break;
                            case 3: cellValue = QString::fromStdString(_data[row].mpaa_rating);
                                    break;
                           case 4: cellValue = QString::fromStdString(_data[row].total_gross);
                                    break;
                            case 5: cellValue = QString::fromStdString(_data[row].inflation_adjusted_gross);
                                    break;
                        }

                        pointerToModel->setData(index, cellValue); // initialize a cell in the model with zero value (you can also put a string instead of 0)
                    }
                }
            }
    void setdetais(std::string mpaa_rating, std::string inflation_gross, int i)
    {
        _data[i].mpaa_rating =mpaa_rating;
        _data[i].inflation_adjusted_gross = inflation_gross;
    }
    void save(QMainWindow* window)
            {
                QString filename = QFileDialog::getSaveFileName(window, "Save file", "", ".csv");
                QFile f(filename);
                f.open(QIODevice::WriteOnly);
                f.write("movie_title,release_date,genre,mpaa_rating,total_gross,inflation_adjusted_gross\n");
                for(int i = 0; i < (int) _data.size(); i++)
                {
                    std::stringstream ss;
                    ss << _data[i].movie_title << "," << _data[i].release_date << "," << _data[i].genre << "," << _data[i].mpaa_rating << "," << _data[i].total_gross << "," << _data[i].inflation_adjusted_gross;
                    f.write(ss.str().c_str());
                }
                f.close();
            }
    void update()
           {
               std :: cout << "Cell updated! Updating data..." << std::endl;

               for(int row = 0; row < pointerToModel->rowCount(); row++){

                   if(row >= (int) _data.size())           // if the "model" has more elements than the "data"
                       _data.push_back(film());         // add a new element to the "data".

                   for(int col = 0; col < pointerToModel->columnCount(); col++)
                   {
                       QModelIndex index = pointerToModel->index(row,col);
                       std::string cellValue = (index.data().toString()).toStdString();

                       switch(col)
                       {
                           case 0: _data[row].movie_title = cellValue;
                                   break;

                           case 1: _data[row].release_date = cellValue;
                                   break;

                           case 2: _data[row].genre = cellValue;
                                   break;
                       case 3: _data[row].total_gross = cellValue;
                                   break;

                       }
                   }
               }
           }
    void remove()
    {
        update();
    }

    std::set<std::string> genres;

    void open(QMainWindow* window)
    {
        QString fileName = QFileDialog::getOpenFileName(window,"Open File","*.csv");
            QFile file(fileName);
            file.open(QIODevice::ReadOnly);

            file.readLine();

            while(!file.atEnd())
            {
                QByteArray line = file.readLine();
                QList<QByteArray> lineAsVector = line.split(',');
                int row = pointerToModel->rowCount(); // 2

                    pointerToModel->insertRows(row, 1);

                    QModelIndex index = pointerToModel->index(row, 0, QModelIndex());
                    pointerToModel->setData(index,lineAsVector.at(0));

                    index = pointerToModel->index(row, 1, QModelIndex());
                    pointerToModel->setData(index,lineAsVector.at(1));

                    index = pointerToModel->index(row, 2, QModelIndex());
                    pointerToModel->setData(index,lineAsVector.at(2));

                    genres.insert(lineAsVector.at(2).toStdString());

                    index = pointerToModel->index(row, 3, QModelIndex());
                    pointerToModel->setData(index,lineAsVector.at(4));

                    std::string mpaa_rating=lineAsVector.at(3).toStdString();

                    std::string inflation_gross=lineAsVector.at(5).toStdString();
                    _data[row].mpaa_rating =mpaa_rating;

                    _data[row].inflation_adjusted_gross = inflation_gross;
                    row++;
             }

    } 

    void sum()
    {
        int sum = 0;
        for(int row = 0; row < pointerToModel->rowCount(); row++)
        {
            QModelIndex index = pointerToModel->index(row,3);
            int cellValue = (index.data().toString()).toInt();
            sum+=cellValue;
        }

    }

    film getFilm(int i)
            {
                return _data[i];
            }






private:
    std::vector<film> _data;


    QStandardItemModel* pointerToModel;

};
#endif FILM_H
