/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *Tab;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *crawlTab_btnClick;
    QWidget *horizontalLayoutWidget_12;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *lineEdit_2;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *lineEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_12;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_10;
    QRadioButton *radioButton_11;
    QRadioButton *radioButton_13;
    QRadioButton *radioButton_14;
    QWidget *tab_2;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *displayTab_browseClick;
    QSpacerItem *horizontalSpacer;
    QPushButton *displayTab_clearClick;
    QTableView *tableView;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *searchTab_secondCsvBrowseClick;
    QSpacerItem *horizontalSpacer_6;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *searchTab_clearClick;
    QSpacerItem *horizontalSpacer_7;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *searchTab_firstCsvBrowseClick;
    QSpacerItem *horizontalSpacer_5;
    QTableView *tableView_2;
    QTableView *tableView_4;
    QWidget *tab_4;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *statisticsTab_clearClick;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView_3;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *statisticsTab_firstCsvBrowseClick;
    QSpacerItem *horizontalSpacer_2;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *statisticsTab_secondCsvBrowseClick;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1667, 910);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        Tab = new QTabWidget(centralwidget);
        Tab->setObjectName(QString::fromUtf8("Tab"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 119, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        crawlTab_btnClick = new QPushButton(tab);
        crawlTab_btnClick->setObjectName(QString::fromUtf8("crawlTab_btnClick"));
        crawlTab_btnClick->setGeometry(QRect(0, 320, 93, 28));
        horizontalLayoutWidget_12 = new QWidget(tab);
        horizontalLayoutWidget_12->setObjectName(QString::fromUtf8("horizontalLayoutWidget_12"));
        horizontalLayoutWidget_12->setGeometry(QRect(210, 50, 571, 71));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget_12);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        lineEdit_2 = new QLineEdit(horizontalLayoutWidget_12);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_12->addWidget(lineEdit_2);

        horizontalLayoutWidget_11 = new QWidget(tab);
        horizontalLayoutWidget_11->setObjectName(QString::fromUtf8("horizontalLayoutWidget_11"));
        horizontalLayoutWidget_11->setGeometry(QRect(210, 0, 571, 51));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(horizontalLayoutWidget_11);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_11->addWidget(lineEdit);

        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 170, 781, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_2 = new QRadioButton(horizontalLayoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(horizontalLayoutWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        horizontalLayout->addWidget(radioButton_3);

        radioButton = new QRadioButton(horizontalLayoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);

        horizontalLayoutWidget_2 = new QWidget(tab);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 250, 781, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_7 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));

        horizontalLayout_2->addWidget(radioButton_7);

        radioButton_6 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));

        horizontalLayout_2->addWidget(radioButton_6);

        radioButton_12 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_12->setObjectName(QString::fromUtf8("radioButton_12"));

        horizontalLayout_2->addWidget(radioButton_12);

        radioButton_8 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));

        horizontalLayout_2->addWidget(radioButton_8);

        radioButton_5 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        horizontalLayout_2->addWidget(radioButton_5);

        verticalLayoutWidget_2 = new QWidget(tab);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 200, 781, 51));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        horizontalLayoutWidget_3 = new QWidget(tab);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 280, 781, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton_9 = new QRadioButton(horizontalLayoutWidget_3);
        radioButton_9->setObjectName(QString::fromUtf8("radioButton_9"));

        horizontalLayout_3->addWidget(radioButton_9);

        radioButton_10 = new QRadioButton(horizontalLayoutWidget_3);
        radioButton_10->setObjectName(QString::fromUtf8("radioButton_10"));

        horizontalLayout_3->addWidget(radioButton_10);

        radioButton_11 = new QRadioButton(horizontalLayoutWidget_3);
        radioButton_11->setObjectName(QString::fromUtf8("radioButton_11"));

        horizontalLayout_3->addWidget(radioButton_11);

        radioButton_13 = new QRadioButton(horizontalLayoutWidget_3);
        radioButton_13->setObjectName(QString::fromUtf8("radioButton_13"));

        horizontalLayout_3->addWidget(radioButton_13);

        radioButton_14 = new QRadioButton(horizontalLayoutWidget_3);
        radioButton_14->setObjectName(QString::fromUtf8("radioButton_14"));

        horizontalLayout_3->addWidget(radioButton_14);

        Tab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayoutWidget_4 = new QWidget(tab_2);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(0, 0, 1651, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        displayTab_browseClick = new QPushButton(horizontalLayoutWidget_4);
        displayTab_browseClick->setObjectName(QString::fromUtf8("displayTab_browseClick"));

        horizontalLayout_4->addWidget(displayTab_browseClick);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        displayTab_clearClick = new QPushButton(horizontalLayoutWidget_4);
        displayTab_clearClick->setObjectName(QString::fromUtf8("displayTab_clearClick"));

        horizontalLayout_4->addWidget(displayTab_clearClick);

        tableView = new QTableView(tab_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 30, 1651, 791));
        Tab->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayoutWidget_6 = new QWidget(tab_3);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(210, 0, 571, 81));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        lineEdit_3 = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_6->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_6->addWidget(lineEdit_4);

        verticalLayoutWidget_3 = new QWidget(tab_3);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 160, 161));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        horizontalLayoutWidget_9 = new QWidget(tab_3);
        horizontalLayoutWidget_9->setObjectName(QString::fromUtf8("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(210, 120, 571, 41));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        searchTab_secondCsvBrowseClick = new QPushButton(horizontalLayoutWidget_9);
        searchTab_secondCsvBrowseClick->setObjectName(QString::fromUtf8("searchTab_secondCsvBrowseClick"));

        horizontalLayout_9->addWidget(searchTab_secondCsvBrowseClick);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);

        horizontalLayoutWidget_10 = new QWidget(tab_3);
        horizontalLayoutWidget_10->setObjectName(QString::fromUtf8("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(210, 160, 571, 41));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        searchTab_clearClick = new QPushButton(horizontalLayoutWidget_10);
        searchTab_clearClick->setObjectName(QString::fromUtf8("searchTab_clearClick"));

        horizontalLayout_10->addWidget(searchTab_clearClick);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);

        horizontalLayoutWidget_8 = new QWidget(tab_3);
        horizontalLayoutWidget_8->setObjectName(QString::fromUtf8("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(210, 80, 571, 41));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        searchTab_firstCsvBrowseClick = new QPushButton(horizontalLayoutWidget_8);
        searchTab_firstCsvBrowseClick->setObjectName(QString::fromUtf8("searchTab_firstCsvBrowseClick"));

        horizontalLayout_8->addWidget(searchTab_firstCsvBrowseClick);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        tableView_2 = new QTableView(tab_3);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(0, 200, 1661, 341));
        tableView_4 = new QTableView(tab_3);
        tableView_4->setObjectName(QString::fromUtf8("tableView_4"));
        tableView_4->setGeometry(QRect(0, 540, 1661, 341));
        Tab->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayoutWidget_4 = new QWidget(tab_4);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(0, 0, 229, 71));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(verticalLayoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_4->addWidget(label_12);

        label_13 = new QLabel(verticalLayoutWidget_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_4->addWidget(label_13);

        horizontalLayoutWidget_7 = new QWidget(tab_4);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(210, 80, 571, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        statisticsTab_clearClick = new QPushButton(horizontalLayoutWidget_7);
        statisticsTab_clearClick->setObjectName(QString::fromUtf8("statisticsTab_clearClick"));

        horizontalLayout_7->addWidget(statisticsTab_clearClick);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        tableView_3 = new QTableView(tab_4);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(0, 110, 781, 401));
        horizontalLayoutWidget_5 = new QWidget(tab_4);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(210, 0, 571, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        statisticsTab_firstCsvBrowseClick = new QPushButton(horizontalLayoutWidget_5);
        statisticsTab_firstCsvBrowseClick->setObjectName(QString::fromUtf8("statisticsTab_firstCsvBrowseClick"));

        horizontalLayout_5->addWidget(statisticsTab_firstCsvBrowseClick);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        horizontalLayoutWidget_6 = new QWidget(tab_4);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(210, 40, 571, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        statisticsTab_secondCsvBrowseClick = new QPushButton(horizontalLayoutWidget_6);
        statisticsTab_secondCsvBrowseClick->setObjectName(QString::fromUtf8("statisticsTab_secondCsvBrowseClick"));

        horizontalLayout_6->addWidget(statisticsTab_secondCsvBrowseClick);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        Tab->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        Tab->addTab(tab_5, QString());

        verticalLayout_5->addWidget(Tab);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1667, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "First Keyword", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Second Keyword", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Website source", nullptr));
        crawlTab_btnClick->setText(QCoreApplication::translate("MainWindow", "Crawl", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "CNA", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "The Guardian", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Twitter", nullptr));
        radioButton_7->setText(QCoreApplication::translate("MainWindow", "300", nullptr));
        radioButton_6->setText(QCoreApplication::translate("MainWindow", "600", nullptr));
        radioButton_12->setText(QCoreApplication::translate("MainWindow", "900", nullptr));
        radioButton_8->setText(QCoreApplication::translate("MainWindow", "1200", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "1500", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Number of pages to crawl", nullptr));
        radioButton_9->setText(QCoreApplication::translate("MainWindow", "1800", nullptr));
        radioButton_10->setText(QCoreApplication::translate("MainWindow", "2100", nullptr));
        radioButton_11->setText(QCoreApplication::translate("MainWindow", "2400", nullptr));
        radioButton_13->setText(QCoreApplication::translate("MainWindow", "2700", nullptr));
        radioButton_14->setText(QCoreApplication::translate("MainWindow", "3000", nullptr));
        Tab->setTabText(Tab->indexOf(tab), QCoreApplication::translate("MainWindow", "Crawl", nullptr));
        displayTab_browseClick->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        displayTab_clearClick->setText(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
        Tab->setTabText(Tab->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Display", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "First Keyword", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Second Keyword", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Browse first csv file", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Browse second csv file", nullptr));
        searchTab_secondCsvBrowseClick->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        searchTab_clearClick->setText(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
        searchTab_firstCsvBrowseClick->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        Tab->setTabText(Tab->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Search", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Top 10 Retweets and Favourites", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Top 10 Retweets and Favourites", nullptr));
        statisticsTab_clearClick->setText(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
        statisticsTab_firstCsvBrowseClick->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        statisticsTab_secondCsvBrowseClick->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        Tab->setTabText(Tab->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        Tab->setTabText(Tab->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
