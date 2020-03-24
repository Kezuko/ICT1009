#ifndef COVID19MODEL_H
#define COVID19MODEL_H
#include <QAbstractTableModel>
#include <QVector>
using namespace std;
class CovidModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    QVector<string> confirmedCasesCol;
    QVector<string> countryCol;
    QVector<string> headerCol;
public:
    CovidModel(QObject *parent = nullptr);
    void populateData(QVector<string> confirmedCasesCol, QVector<string> countryCol, QVector<string> headerCol);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // COVID19MODEL_H
