#ifndef CUSTOMPROXY_H
#define CUSTOMPROXY_H
#include <QSortFilterProxyModel>

class customproxy : public QSortFilterProxyModel
{
public:

    customproxy(QObject* parent = 0);
    void setFilterSubstr(QString country);
protected:

     bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override;

private:
     QString substr;
};

#endif // CUSTOMPROXY_H
