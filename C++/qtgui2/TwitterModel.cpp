#include "TwitterModel.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

TwitterModel::TwitterModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void TwitterModel::populateData(QVector<string> username, QVector<string> tweet, QVector<string> retweet, QVector<string> favourite, QVector<string> date, QVector<string> header )
{
    usernameCol = username;
    tweetCol = tweet;
    retweetCol = retweet;
    favouriteCol = favourite;
    dateCol = date;
    headerCol = header;
    return;
}

int TwitterModel::rowCount(const QModelIndex & /*parent*/) const
{
   return usernameCol.size();
}

int TwitterModel::columnCount(const QModelIndex & /*parent*/) const
{
    return headerCol.size();
}

QVariant TwitterModel::data(const QModelIndex &index, int role) const
{
    cout << index.row() << endl;
    if (role == Qt::DisplayRole)
       if (index.column() == 0) {
           QString columnOne = QString::fromStdString(usernameCol[index.row()]);
           return columnOne;
       }
       else if (index.column() == 1) {
           QString columnTwo = QString::fromStdString(tweetCol[index.row()]);
           return columnTwo;
       }
       else if (index.column() == 2) {
           QString columnThree = QString::fromStdString(retweetCol[index.row()]);
           return columnThree;
       }
       else if (index.column() == 3) {
           QString columnFour = QString::fromStdString(favouriteCol[index.row()]);
           return columnFour;
       }
       else if (index.column() == 4) {
           QString columnFive = QString::fromStdString(dateCol[index.row()]);
           return columnFive;
       }

    return QVariant();
}

QVariant TwitterModel::headerData(int section, Qt::Orientation orientation, int role) const
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


        case 3:{
            QString headerFour = QString::fromStdString(headerCol[3]);
            return headerFour;
        }


        case 4:{
            QString headerFive = QString::fromStdString(headerCol[4]);
            return headerFive;
        }


        }
    }
    return QVariant();
}
