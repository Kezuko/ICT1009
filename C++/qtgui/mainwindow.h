#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_crawlTab_btnClick_clicked();

    void on_displayTab_browseClick_clicked();

    void on_displayTab_clearClick_clicked();

    void on_searchTab_firstCsvBrowseClick_clicked();

    void on_searchTab_secondCsvBrowseClick_clicked();

    void on_searchTab_clearClick_clicked();

    void on_statisticsTab_firstCsvBrowseClick_clicked();

    void on_statisticsTab_secondCsvBrowseClick_clicked();

    void on_statisticsTab_clearClick_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
