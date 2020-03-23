#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displaySentimentPieChartOne();
    void displayTable(QTableView* tv);
    void setFileName(QString fileName);

private slots:
    void on_displayTab_browseClick_clicked();

    void on_displayTab_clearClick_clicked();

    void on_searchTab_firstCsvBrowseClick_clicked();

    void on_searchTab_secondCsvBrowseClick_clicked();

private:
    Ui::MainWindow *ui;
    QString fileNaming;
};
#endif // MAINWINDOW_H