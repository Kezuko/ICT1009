#ifndef CNAMODEL_H
#define CNAMODEL_H
#include <QAbstractTableModel>
#include <QVector>
using namespace std;
class CNAModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    QVector<string> categoryCol;
    QVector<string> titleCol;
    QVector<string> dateCol;
    QVector<string> headerCol;
public:
    CNAModel(QObject *parent = nullptr);
    void populateData(QVector<string> categoryCol, QVector<string> titleCol, QVector<string> dateCol, QVector<string> headerCol);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};
#endif // CNAMODEL_H
