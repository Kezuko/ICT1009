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
#include <QtCore/QSortFilterProxyModel>
#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    /*
     * Open a file dialog
     */
    QFileDialog dialog(this);
//    QString currDir = QFileDialog::getExistingDirectory(this, tr("Open a directory"),
//                                                    "/home",
//                                                    QFileDialog::ShowDirsOnly
//                                                    | QFileDialog::DontResolveSymlinks);
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::currentPath(), tr("CSV files (*.csv)"));
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
     * PieChart displays a title based on the opened CSV file
     */
    std::string utf8_text = fileName.toUtf8().constData();
    MainWindow::setFileName(fileName);

    /*
     * Using parser.h for csv parsing.
     */
    std::ifstream f(utf8_text);
    using namespace aria::csv;
    CsvParser parser(f);
    parser.delimiter(',').quote('\"');

    /*
     * Get the header of the table. Populate header vector<string> with header string
     */
    std::string str = "";
    std::getline(f, str);
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
    /*
     * Populate the vectors based on whether (1) Twitter CSV, (2) TheGuardian/CNA CSV is displaying
     */
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
        if (header.size()==3){//TheGuardian/CNA has 3 headers
            categoryCol.push_back(row[0]);
            titleCol.push_back(row[1]);
            dateCol.push_back(row[2]);
        }
        else if (header.size()==5){//Twitter has 5 headers
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
     * Depending on (1) Twitter CSV, (2) TheGuardian/CNA CSV is displaying, (1) MyModel = Twitter CSV Table Model, (2) CNAModel = TheGuardian/CNA CSV Table Model
     */
    if (header.size()==3){
        CNAModel *cnaModel = new CNAModel(this);//replicate this for search and statistics tab
        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);

        proxyModel->setSourceModel(cnaModel);
        tv->setModel(proxyModel);
        proxyModel->setFilterRegExp(QRegExp("coronavirus", Qt::CaseInsensitive,
                                            QRegExp::FixedString));
        proxyModel->setFilterKeyColumn(1);
        proxyModel->setDynamicSortFilter(true);
        cnaModel->populateData(categoryCol, titleCol, dateCol, header);

        tv->setModel(cnaModel);//replicate this for tableView_2,_3,_4,_5...
        tv->horizontalHeader()->setVisible(true);
    //    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tv->verticalHeader()->setMinimumWidth(25);
        tv->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
        tv->setSortingEnabled(true);//improve this code, sorting doesn't work

        tv->resizeColumnsToContents();
        tv->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        int numRows = cnaModel->rowCount();
        for(QVector<string>::iterator i=titleCol.begin(); i != titleCol.end(); i++){
            bool match = false;
            string keyword1 = ui->lineEdit_3->text().toUtf8().constData();
            string keyword2 = ui->lineEdit_4->text().toUtf8().constData();

            if(!keyword1.empty()){
                if(!keyword2.empty()){
                    //do nothing
                }
                else if(keyword2.empty()){
                    keyword2 = keyword1;
                }
            }
            else if(keyword1.empty()){
                if(!keyword2.empty()){
                    keyword1 = keyword2;
                }
                else if(keyword2.empty()){
                    break;
                }
            }

            std::size_t keyword1found = i->find(keyword1);
            for (char &c : keyword1){
                putchar(toupper(c));
            }
            std::size_t keyword1foundupper = i->find(keyword1);
            for (char &c : keyword1){
                putchar(tolower(c));
            }
            std::size_t keyword1foundlower = i->find(keyword1);



            std::size_t keyword2found = i->find(keyword2);
            for (char &c : keyword1){
                putchar(toupper(c));
            }
            std::size_t keyword2foundupper = i->find(keyword2);
            for (char &c : keyword1){
                putchar(tolower(c));
            }
            std::size_t keyword2foundlower = i->find(keyword2);
            if (keyword1found!=std::string::npos && keyword2found!=std::string::npos){
                match = true;
            }
            if (keyword1foundupper!=std::string::npos && keyword2foundupper!=std::string::npos){
                match = true;
            }
            if (keyword1foundupper!=std::string::npos && keyword2foundupper!=std::string::npos){
                match = true;
            }
            if (keyword1foundlower!=std::string::npos && keyword2foundlower!=std::string::npos){
                match = true;
            }
            int index = std::distance( titleCol.begin(), i );
            if (!match){
                tv->hideRow(index);
                numRows--;
            }

        }

        tv->show();
        QObject* button = QObject::sender();
        if(button == ui->searchTab_firstCsvBrowseClick){
            ui->label_9->setText(QString::fromStdString(to_string(numRows) + " rows x " + to_string(cnaModel->columnCount()) + " columns loaded"));
        }
        else if(button == ui->searchTab_secondCsvBrowseClick){
            ui->label_10->setText(QString::fromStdString(to_string(numRows) + " rows x " + to_string(cnaModel->columnCount()) + " columns loaded"));
        }
        else if(button == ui->displayTab_browseClick){
            ui->label_11->setText(QString::fromStdString(to_string(numRows) + " rows x " + to_string(cnaModel->columnCount()) + " columns loaded"));
        }
        cout << "CNA/TheGuardian row count = " << numRows << "x" << cnaModel->columnCount() << endl;
    }
    else if (header.size()==5){
        MyModel *myModel = new MyModel(this);//replicate this for search and statistics tab
        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);

        proxyModel->setSourceModel(myModel);
        tv->setModel(proxyModel);
        proxyModel->setDynamicSortFilter(true);
        myModel->populateData(usernameCol, tweetCol, retweetCol, favouriteCol, dateCol, header);
        tv->setModel(myModel);//replicate this for tableView_2,_3,_4,_5...
        tv->horizontalHeader()->setVisible(true);
    //    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tv->verticalHeader()->setMinimumWidth(25);
        tv->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
        tv->setSortingEnabled(true);//improve this code, sorting doesn't work

        tv->resizeColumnsToContents();
        tv->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        int numRows = myModel->rowCount();
        for(QVector<string>::iterator i=tweetCol.begin(); i != tweetCol.end(); i++){
            bool match = false;

            string keyword1 = ui->lineEdit_3->text().toUtf8().constData();
            string keyword2 = ui->lineEdit_4->text().toUtf8().constData();

            if(!keyword1.empty()){
                if(!keyword2.empty()){
                    //do nothing
                }
                else if(keyword2.empty()){
                    keyword2 = keyword1;
                }
            }
            else if(keyword1.empty()){
                if(!keyword2.empty()){
                    keyword1 = keyword2;
                }
                else if(keyword2.empty()){
                    break;
                }
            }
            std::size_t keyword1found = i->find(keyword1);
            for (char &c : keyword1){
                putchar(toupper(c));
            }
            std::size_t keyword1foundupper = i->find(keyword1);
            for (char &c : keyword1){
                putchar(tolower(c));
            }
            std::size_t keyword1foundlower = i->find(keyword1);



            std::size_t keyword2found = i->find(keyword2);
            for (char &c : keyword1){
                putchar(toupper(c));
            }
            std::size_t keyword2foundupper = i->find(keyword2);
            for (char &c : keyword1){
                putchar(tolower(c));
            }
            std::size_t keyword2foundlower = i->find(keyword2);
            if (keyword1found!=std::string::npos && keyword2found!=std::string::npos){
                match = true;
            }
            if (keyword1foundupper!=std::string::npos && keyword2foundupper!=std::string::npos){
                match = true;
            }
            if (keyword1foundupper!=std::string::npos && keyword2foundupper!=std::string::npos){
                match = true;
            }
            if (keyword1foundlower!=std::string::npos && keyword2foundlower!=std::string::npos){
                match = true;
            }
            int index = std::distance( tweetCol.begin(), i );
            if (!match){
                tv->hideRow(index);
                numRows--;
            }

        }
        tv->show();
        QObject* button = QObject::sender();
        if(button == ui->searchTab_firstCsvBrowseClick){
            ui->label_9->setText(QString::fromStdString(to_string(numRows) + " rows x " + to_string(myModel->columnCount()) + " columns loaded"));
        }
        else if(button == ui->searchTab_secondCsvBrowseClick){
            ui->label_10->setText(QString::fromStdString(to_string(numRows) + " rows x " + to_string(myModel->columnCount()) + " columns loaded"));
        }
        else if(button == ui->displayTab_browseClick){
            ui->label_11->setText(QString::fromStdString(to_string(numRows) + " rows x " + to_string(myModel->columnCount()) + " columns loaded"));
        }
        cout << "Twitter row count = " << numRows << "x" << myModel->columnCount() << endl;
    }



}

void MainWindow::on_searchTab_firstCsvBrowseClick_clicked()
{
    displayTable(ui->tableView_2);
    displaySentimentPieChartOne();
}

void MainWindow::on_searchTab_secondCsvBrowseClick_clicked()
{
    displayTable(ui->tableView_4);
    displaySentimentPieChartOne();
}
