#include "customproxy.h"


customproxy::customproxy(QObject* parent)
    : QSortFilterProxyModel(parent)
{
    substr=QString();
}

bool customproxy::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);

    QString name = sourceModel()->data(index).toString();

    QModelIndex index2 = sourceModel()->index(sourceRow, 2, sourceParent);

    QString Genre = sourceModel()->data(index2).toString();

    QModelIndex index3 = sourceModel()->index(sourceRow, 1, sourceParent);

    QString Date = sourceModel()->data(index3).toString();

    QModelIndex index4 = sourceModel()->index(sourceRow, 3, sourceParent);

    QString Gross = sourceModel()->data(index4).toString();

    return ((name.contains(substr))||(Genre.contains(substr))||(Date.contains(substr))||(Gross.contains(substr)));

}

void customproxy::setFilterSubstr(QString substr)
{
    this->substr = substr.trimmed().isEmpty() ? QString() : substr;
    invalidateFilter();
}


