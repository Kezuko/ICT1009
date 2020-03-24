#ifndef TWITTERMODEL_H
#define TWITTERMODEL__H
#include <QAbstractTableModel>
#include <QVector>
using namespace std;
class TwitterModel : public QAbstractTableModel
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
    TwitterModel(QObject *parent = nullptr);
    void populateData(QVector<string> usernameCol, QVector<string> tweetCol, QVector<string> retweetCol, QVector<string> favouriteCol, QVector<string> dateCol, QVector<string> header);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};
#endif // TWITTERMODEL_H
