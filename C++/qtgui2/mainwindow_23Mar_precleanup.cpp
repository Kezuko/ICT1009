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
#include "sentimentone.h"
#include "CNAModel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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
//    using ratingspace aria::csv;
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

//    using ratingspace std;
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

void MainWindow::setFileName(QString fileName){
    fileNaming = fileName;
}

void MainWindow::on_displayTab_browseClick_clicked()
{
    displayTable(ui->tableView);
//    QFileDialog dialog(this);
//    QString currDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
//                                                    "/home",
//                                                    QFileDialog::ShowDirsOnly
//                                                    | QFileDialog::DontResolveSymlinks);
//    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", currDir, tr("CSV files (*.csv)"));
//    dialog.setViewMode(QFileDialog::Detail);
//    QMessageBox::information(this,"...",fileName);

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
//    // QString to String
//    std::string utf8_text = fileName.toUtf8().constData();

//    std::ifstream f(utf8_text);
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
////    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableView->verticalHeader()->setMinimumWidth(25);
//    ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
//    ui->tableView->setSortingEnabled(true);//improve this code, sorting doesn't work
//    ui->tableView->resizeColumnsToContents();
//    ui->tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    ui->tableView->show();

}

void MainWindow::on_displayTab_clearClick_clicked()
{
}

void MainWindow::displaySentimentPieChartOne(){
    SentimentOne *first = new SentimentOne(this);

    QT_CHARTS_USE_NAMESPACE


    DrilldownChart *chart = new DrilldownChart();
    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QPieSeries *ratingsSeries = new QPieSeries(first);
    ratingsSeries->setName(fileNaming);

    const QStringList keywords = {
//        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        "Covid", "China", "Spreading", "Infectious", "Death", "Epicentre", "Risk", "Infection", "Vaccine", "Lockdown"
    };
    const QStringList ratings = {
        "Very Negative", "Negative", "Neutral", "Positive", "Very Positive"
    };

//    for (const QString &name : ratings) {
    QPieSeries *series = new QPieSeries(first);
    series->setName("Keywords from ratings");

//        for (const QString &keyword : keywords)
    *series << new DrilldownSlice(QRandomGenerator::global()->bounded(1000), keywords[0], ratingsSeries);//commented QRandomGenerator::global()->bounded(1000) from first argument/parameter of DrilldownSlice
    *series << new DrilldownSlice(QRandomGenerator::global()->bounded(1000), keywords[1], ratingsSeries);
    *series << new DrilldownSlice(QRandomGenerator::global()->bounded(1000), keywords[2], ratingsSeries);
    *series << new DrilldownSlice(QRandomGenerator::global()->bounded(1000), keywords[3], ratingsSeries);
    *series << new DrilldownSlice(QRandomGenerator::global()->bounded(1000), keywords[4], ratingsSeries);
    *series << new DrilldownSlice(QRandomGenerator::global()->bounded(1000), keywords[5], ratingsSeries);
    *series << new DrilldownSlice(QRandomGenerator::global()->bounded(1000), keywords[6], ratingsSeries);
    *series << new DrilldownSlice(QRandomGenerator::global()->bounded(1000), keywords[7], ratingsSeries);
    *series << new DrilldownSlice(QRandomGenerator::global()->bounded(1000), keywords[8], ratingsSeries);
    *series << new DrilldownSlice(QRandomGenerator::global()->bounded(1000), keywords[9], ratingsSeries);


    QObject::connect(series, &QPieSeries::clicked, chart, &DrilldownChart::handleSliceClicked);

    *ratingsSeries << new DrilldownSlice(QRandomGenerator::global()->bounded(100), ratings[0], series);
    *ratingsSeries << new DrilldownSlice(QRandomGenerator::global()->bounded(100), ratings[1], series);
    *ratingsSeries << new DrilldownSlice(QRandomGenerator::global()->bounded(100), ratings[2], series);
    *ratingsSeries << new DrilldownSlice(QRandomGenerator::global()->bounded(100), ratings[3], series);
    *ratingsSeries << new DrilldownSlice(QRandomGenerator::global()->bounded(100), ratings[4], series);//commented out series->sum()
//    }

    QObject::connect(ratingsSeries, &QPieSeries::clicked, chart, &DrilldownChart::handleSliceClicked);

    chart->changeSeries(ratingsSeries);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    first->setCentralWidget(chartView);
    first->resize(800, 500);
    first->show();
}

void MainWindow::displayTable(QTableView* tv){
    QFileDialog dialog(this);
    QString currDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", currDir, tr("CSV files (*.csv)"));
    dialog.setViewMode(QFileDialog::Detail);
    QMessageBox::information(this,"...",fileName);

    QVector<string> categoryCol;
    QVector<string> titleCol;
    QVector<string> dateCol;
    QVector<string> header;

    QVector<string> usernameCol;
    QVector<string> tweetCol;
    QVector<string> retweetCol;
    QVector<string> favouriteCol;
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
    // QString to String
    std::string utf8_text = fileName.toUtf8().constData();
    MainWindow::setFileName(fileName);

    std::ifstream f(utf8_text);
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
        if (header.size()==3){
            categoryCol.push_back(row[0]);
            titleCol.push_back(row[1]);
            dateCol.push_back(row[2]);
        }
        else if (header.size()==5){
            usernameCol.push_back(row[0]);
            tweetCol.push_back(row[1]);
            retweetCol.push_back(row[2]);
            favouriteCol.push_back(row[3]);
            dateCol.push_back(row[4]);
        }

    }

/*
    Troubleshooting
*/

    using namespace std;
    for(std::string u : categoryCol){
        cout << "C=" << u << endl;
    }
    for(std::string t : titleCol){
        cout << "T=" << t << endl;
    }
    for(std::string r : dateCol){
        cout << "D=" << r << endl;
    }
    for(std::string h : header){
        cout << "H=" << h << endl;
    }
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

/*
    Hardcoding the table to appear in Display tab
*/
    if (header.size()==3){
        CNAModel *cnaModel = new CNAModel(this);//replicate this for search and statistics tab
        cnaModel->populateData(categoryCol, titleCol, dateCol, header);
        tv->setModel(cnaModel);//replicate this for tableView_2,_3,_4,_5...
        tv->horizontalHeader()->setVisible(true);
    //    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tv->verticalHeader()->setMinimumWidth(25);
        tv->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
        tv->setSortingEnabled(true);//improve this code, sorting doesn't work
        tv->resizeColumnsToContents();
        tv->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        tv->show();
    }
    else if (header.size()==5){
        MyModel *myModel = new MyModel(this);//replicate this for search and statistics tab
        myModel->populateData(usernameCol, tweetCol, retweetCol, favouriteCol, dateCol, header);
        tv->setModel(myModel);//replicate this for tableView_2,_3,_4,_5...
        tv->horizontalHeader()->setVisible(true);
    //    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tv->verticalHeader()->setMinimumWidth(25);
        tv->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
        tv->setSortingEnabled(true);//improve this code, sorting doesn't work
        tv->resizeColumnsToContents();
        tv->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        tv->show();
    }



}

void MainWindow::on_searchTab_firstCsvBrowseClick_clicked()
{
    displayTable(ui->tableView_2);
    displaySentimentPieChartOne();

/*
    Hardcoding the table model
*/

//    ui->tableView_2->setModel(cnaModel);//replicate this for tableView_2,_3,_4,_5...
//    ui->tableView_2->horizontalHeader()->setVisible(true);
////    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableView_2->verticalHeader()->setMinimumWidth(25);
//    ui->tableView_2->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
//    ui->tableView_2->setSortingEnabled(true);//improve this code, sorting doesn't work
//    ui->tableView_2->resizeColumnsToContents();
//    ui->tableView_2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    ui->tableView_2->show();
}

void MainWindow::on_searchTab_secondCsvBrowseClick_clicked()
{
    displayTable(ui->tableView_4);
    displaySentimentPieChartOne();
}
