#ifndef MYMODEL_H
#define MYMODEL_H
#include <QAbstractTableModel>
#include <QVector>
using namespace std;
class MyModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    QVector<string> usernameCol;
    QVector<string> tweetCol;
    QVector<string> retweetCol;
    QVector<string> favouriteCol;
    QVector<string> dateCol;
    QVector<string> headerCol;
public:
    MyModel(QObject *parent = nullptr);
    void populateData(QVector<string> usernameCol, QVector<string> tweetCol, QVector<string> retweetCol, QVector<string> favouriteCol, QVector<string> dateCol, QVector<string> header);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};
#endif // MYMODEL_H
