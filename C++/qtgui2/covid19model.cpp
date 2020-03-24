#include "covid19model.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

CovidModel::CovidModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void CovidModel::populateData(QVector<string> country, QVector<string> confirmedCases, QVector<string> header)
{
    countryCol = country;
    confirmedCasesCol = confirmedCases;
    headerCol = header;
    return;
}

int CovidModel::rowCount(const QModelIndex & /*parent*/) const
{
   return countryCol.size();
}

int CovidModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

QVariant CovidModel::data(const QModelIndex &index, int role) const
{
    cout << index.row() << endl;
    if (role == Qt::DisplayRole)
       if (index.column() == 0) {
           QString columnOne = QString::fromStdString(countryCol[index.row()]);
           return columnOne;
       }
       else if (index.column() == 1) {
           QString columnTwo = QString::fromStdString(confirmedCasesCol[index.row()]);
           return columnTwo;
       }

    return QVariant();
}

QVariant CovidModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:{
            QString headerOne = QString::fromStdString(headerCol[1]);
            return headerOne;
        }


        case 1:{
            QString headerTwo = QString::fromStdString(headerCol[65]);
            return headerTwo;
        }

        }
    }
    return QVariant();
}
