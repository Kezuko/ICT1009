//#include "csv.h"
#include "parser.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include "MyModel.h"
#include <QVector>
#include <sstream>
#include <QFileDialog>
#include <QMessageBox>
#include "drilldownchart.h"
#include "drilldownslice.h"
#include <QtWidgets/QApplication>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCore/QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QT_CHARTS_USE_NAMESPACE
    QMainWindow window;

    DrilldownChart *chart = new DrilldownChart();
    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QPieSeries *yearSeries = new QPieSeries(&window);
    yearSeries->setName("Sales by year - All");

    const QStringList months = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    const QStringList names = {
        "Jane", "John", "Axel", "Mary", "Susan", "Bob"
    };

    for (const QString &name : names) {
        QPieSeries *series = new QPieSeries(&window);
        series->setName("Sales by month - " + name);

        for (const QString &month : months)
            *series << new DrilldownSlice(QRandomGenerator::global()->bounded(1000), month, yearSeries);

        QObject::connect(series, &QPieSeries::clicked, chart, &DrilldownChart::handleSliceClicked);

        *yearSeries << new DrilldownSlice(series->sum(), name, series);
    }

    QObject::connect(yearSeries, &QPieSeries::clicked, chart, &DrilldownChart::handleSliceClicked);

    chart->changeSeries(yearSeries);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    window.setCentralWidget(chartView);
    window.resize(800, 500);
    window.show();

/*
    Declaring 5 hardcoded columns for Twitter - Copy 5.csv
    Note: passing column size called variable "size" to table
*/
//    QVector<string> usernameCol;
//    QVector<string> tweetCol;
//    QVector<string> retweetCol;
//    QVector<string> favouriteCol;
//    QVector<string> dateCol;
//    QVector<string> header;
//    int size = 0;

///*
//    Hardocoding the header, the file path and column count to "Username","Tweet","Rt count","Fav count","Data" and "D:/..." and 5 respectively
//    Dynamic check:
//    1.MyModel::Row count
//    2.MyModel::Data
//    3.MyModel::Col count
//    4.MyModel::Header data
//    Static check:

//*/
//    std::ifstream f("D:/Eclipse Workspace/JavaSwingnot7/Grp32/Grp32_code/twitter - Copy 5.csv");
//    using namespace aria::csv;
//    CsvParser parser(f);
//    parser.delimiter(',').quote('\"');

//    std::string str = "";
//    std::getline(f, str); // get the first line
//    istringstream iss(str);
//    std::string token;
//    while (std::getline(iss, token, ','))
//    {
//        // process each token
//        header.push_back(token);
//    }


////delimited by ; instead of ,
////quoted fields use ' instead of "
////terminated by \0 instead of by \r\n, \n, or \r;

//    CsvParser::iterator i(&parser);
//    for (i = parser.begin(); i != parser.end(); i++){
////    for (auto& row : parser) {
////        for (auto& field : row) {
////            std::cout << field << " | ";
////        }
//        auto row = i->data();
//        if (size==0){
//            size = row->size();
//        }
//        usernameCol.push_back(row[0]);
//        tweetCol.push_back(row[1]);
//        retweetCol.push_back(row[2]);
//        favouriteCol.push_back(row[3]);
//        dateCol.push_back(row[4]);
//    }

///*
//    Troubleshooting
//*/

//    using namespace std;
//    for(std::string u : usernameCol){
//        cout << "U=" << u << endl;
//    }
//    for(std::string t : tweetCol){
//        cout << "T=" << t << endl;
//    }
//    for(std::string r : retweetCol){
//        cout << "R=" << r << endl;
//    }
//    for(std::string f : favouriteCol){
//        cout << "F=" << f << endl;
//    }
//    for(std::string d : dateCol){
//        cout << "D=" << d << endl;
//    }
//    for(std::string h : header){
//        cout << "H=" << h << endl;
//    }

///*
//    Hardcoding the table to appear in Display tab
//*/

//    MyModel *myModel = new MyModel(this);//replicate this for search and statistics tab
//    myModel->populateData(usernameCol, tweetCol, retweetCol, favouriteCol, dateCol, header);

///*
//    Hardcoding the table model
//*/

//    ui->tableView->setModel(myModel);//replicate this for tableView_2,_3,_4,_5...
//    ui->tableView->horizontalHeader()->setVisible(true);
//    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);*/
//    ui->tableView->verticalHeader()->setMinimumWidth(25);
//    ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
//    ui->tableView->setSortingEnabled(true);//improve this code, sorting doesn't work
//    ui->tableView->resizeColumnsToContents();
//    ui->tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    ui->tableView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_displayTab_browseClick_clicked()
{
    QFileDialog dialog(this);
    QString currDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", currDir, tr("CSV files (*.csv)"));
    dialog.setViewMode(QFileDialog::Detail);
    QMessageBox::information(this,"...",fileName);

    QVector<string> usernameCol;
    QVector<string> tweetCol;
    QVector<string> retweetCol;
    QVector<string> favouriteCol;
    QVector<string> dateCol;
    QVector<string> header;
    int size = 0;

/*
    Hardocoding the header, the file path and column count to "Username","Tweet","Rt count","Fav count","Data" and "D:/..." and 5 respectively
    Dynamic check:
    1.MyModel::Row count
    2.MyModel::Data
    3.MyModel::Col count
    4.MyModel::Header data
    Static check:

*/
    std::ifstream f("D:/Eclipse Workspace/JavaSwingnot7/Grp32/Grp32_code/twitter - Copy 5.csv");
    using namespace aria::csv;
    CsvParser parser(f);
    parser.delimiter(',').quote('\"');

    std::string str = "";
    std::getline(f, str); // get the first line
    istringstream iss(str);
    std::string token;
    while (std::getline(iss, token, ','))
    {
        // process each token
        header.push_back(token);
    }


//delimited by ; instead of ,
//quoted fields use ' instead of "
//terminated by \0 instead of by \r\n, \n, or \r;

    CsvParser::iterator i(&parser);
    for (i = parser.begin(); i != parser.end(); i++){
//    for (auto& row : parser) {
//        for (auto& field : row) {
//            std::cout << field << " | ";
//        }
        auto row = i->data();
        if (size==0){
            size = row->size();
        }
        usernameCol.push_back(row[0]);
        tweetCol.push_back(row[1]);
        retweetCol.push_back(row[2]);
        favouriteCol.push_back(row[3]);
        dateCol.push_back(row[4]);
    }

/*
    Troubleshooting
*/

    using namespace std;
    for(std::string u : usernameCol){
        cout << "U=" << u << endl;
    }
    for(std::string t : tweetCol){
        cout << "T=" << t << endl;
    }
    for(std::string r : retweetCol){
        cout << "R=" << r << endl;
    }
    for(std::string f : favouriteCol){
        cout << "F=" << f << endl;
    }
    for(std::string d : dateCol){
        cout << "D=" << d << endl;
    }
    for(std::string h : header){
        cout << "H=" << h << endl;
    }

/*
    Hardcoding the table to appear in Display tab
*/

    MyModel *myModel = new MyModel(this);//replicate this for search and statistics tab
    myModel->populateData(usernameCol, tweetCol, retweetCol, favouriteCol, dateCol, header);

/*
    Hardcoding the table model
*/

    ui->tableView->setModel(myModel);//replicate this for tableView_2,_3,_4,_5...
    ui->tableView->horizontalHeader()->setVisible(true);
//    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setMinimumWidth(25);
    ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->setSortingEnabled(true);//improve this code, sorting doesn't work
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->tableView->show();

}

void MainWindow::on_displayTab_clearClick_clicked()
{
}

void MainWindow::on_searchTab_firstCsvBrowseClick_clicked()
{

}
