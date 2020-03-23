#include "CNAModel.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

CNAModel::CNAModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void CNAModel::populateData(QVector<string> category, QVector<string> title, QVector<string> date, QVector<string> header)
{
    categoryCol = category;
    titleCol = title;
    dateCol = date;
    headerCol = header;
    return;
}

int CNAModel::rowCount(const QModelIndex & /*parent*/) const
{
   return categoryCol.size();
}

int CNAModel::columnCount(const QModelIndex & /*parent*/) const
{
    return headerCol.size();
}

QVariant CNAModel::data(const QModelIndex &index, int role) const
{
    cout << index.row() << endl;
    if (role == Qt::DisplayRole)
       if (index.column() == 0) {
           QString columnOne = QString::fromStdString(categoryCol[index.row()]);
           return columnOne;
       }
       else if (index.column() == 1) {
           QString columnTwo = QString::fromStdString(titleCol[index.row()]);
           return columnTwo;
       }
       else if (index.column() == 2) {
           QString columnThree = QString::fromStdString(dateCol[index.row()]);
           return columnThree;
       }

    return QVariant();
}

QVariant CNAModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:{
            QString headerOne = QString::fromStdString(headerCol[0]);
            return headerOne;
        }


        case 1:{
            QString headerTwo = QString::fromStdString(headerCol[1]);
            return headerTwo;
        }


        case 2:{
            QString headerThree = QString::fromStdString(headerCol[2]);
            return headerThree;
        }

        }
    }
    return QVariant();
}
