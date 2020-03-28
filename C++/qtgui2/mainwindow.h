#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableView>

#pragma once
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <vector>
#include "../rapidjson/document.h"
#include "../rapidjson/istreamwrapper.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/stringbuffer.h"
#include "../rapidjson/ostreamwrapper.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include "../utils/project_utils.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displaySentimentPieChartOne(vector<string> *sharedParsedData);
    void displayTable(QTableView* tv, vector<string> *sharedParsedData);

private slots:
    void on_displayTab_browseClick_clicked();

    void on_searchTab_firstCsvBrowseClick_clicked();

    void on_searchTab_secondCsvBrowseClick_clicked();

    void on_filterTab_browseClick_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
