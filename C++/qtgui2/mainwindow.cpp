//#include "csv.h"
#include "parser.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include "TwitterModel.h"
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
#include "SentimentMainWindow.h"
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

/*
 * Display the table in Display tab when browse button is clicked
 */

void MainWindow::on_displayTab_browseClick_clicked()
{
    displayTable(ui->tableView);
}

/*
 * 1 x QMainWindow will be created everytime sentiment analysis is performed.
 * Contents in the new window will be in pie chart. Visualising the Positive, Neutral and Negative ratings of Twitter tweets.
 */

void MainWindow::displaySentimentPieChartOne(){
    SentimentMainWindow *first = new SentimentMainWindow(this);

    QT_CHARTS_USE_NAMESPACE

    DrilldownChart *chart = new DrilldownChart();
    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QPieSeries *ratingsSeries = new QPieSeries(first);

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

/*
 * No success or error message is needed for displaying the table, a pointer of QTableView will be referenced as an argument to call the inbuilt methods of QTableView to populate it.
 */

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
    std::string utf8_text = "";

    QVector<string> categoryCol;
    QVector<string> titleCol;
    QVector<string> dateCol;
    QVector<string> header;

    QVector<string> usernameCol;
    QVector<string> tweetCol;
    QVector<string> retweetCol;
    QVector<string> favouriteCol;
    int size = 0;

    if(!fileName.isEmpty()&& !fileName.isNull()){
        QMessageBox::information(this,"...",fileName);
        /*
         * PieChart displays a title based on the opened CSV file
         */
        utf8_text = fileName.toUtf8().constData();
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

        /*
         * Populate the vector<string> based on whether (1) Twitter CSV, (2) TheGuardian/CNA CSV is displaying
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
         * Depending on whether (1) Twitter CSV, (2) TheGuardian/CNA CSV is displaying, (1) TwitterModel = Twitter CSV Table Model, (2) CNAModel = TheGuardian/CNA CSV Table Model
         * will be used to populate the table.
         * Calls QTableView inbuilt functions to improve the aesthetics of table
         * Use of CNAModel and TwitterModel class to subclass the QAbstractTableModel to create table models
         * Pass data from csv parser to the subclasses through populateData function in TwitterModel and CNAModel class
         * Filter the data to display based on keywords that match the Article Title column in The Guardian / CNA CSVs or Tweet column in Twitter CSV.
         * Filter is case insensitive
         * Other columns are not filtered and are the limitations of the GUI.
         * If First Keyword is empty and Second Keyword is not, Second Keyword is copied to First Keyword. Filtering will be based on Second Keyword. Vice versa.
         * If both First Keyword and Second Keyword are empty, all table entries will display as usual.
         */
        if (header.size()==3){
            CNAModel *cnaModel = new CNAModel(this);
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
            string keyword1 = "";
            string keyword2 = "";
            for(QVector<string>::iterator i=titleCol.begin(); i != titleCol.end(); i++){
                bool match = false;
                if(tv!=ui->tableView){
                    keyword1 = ui->lineEdit_3->text().toUtf8().constData();
                    keyword2 = ui->lineEdit_4->text().toUtf8().constData();
                }


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
        }
        else if (header.size()==5){
            TwitterModel *myModel = new TwitterModel(this);//replicate this for search and statistics tab
            QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);

            proxyModel->setSourceModel(myModel);
            tv->setModel(proxyModel);
            proxyModel->setDynamicSortFilter(true);
            myModel->populateData(usernameCol, tweetCol, retweetCol, favouriteCol, dateCol, header);
            tv->setModel(myModel);
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

                /*
                 * Case insensitive filtering of keywords
                 */

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

                /*
                 * Remove mismatched table rows from the table
                 */

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
        }

    }







}

/*
 * Display table and pie chart when user wants to open a file in search tab
 */

void MainWindow::on_searchTab_firstCsvBrowseClick_clicked()
{
    displayTable(ui->tableView_2);
    displaySentimentPieChartOne();
}

/*
 * Display table and pie chart when user wants to open a file in search tab
 */

void MainWindow::on_searchTab_secondCsvBrowseClick_clicked()
{
    displayTable(ui->tableView_4);
    displaySentimentPieChartOne();
}
