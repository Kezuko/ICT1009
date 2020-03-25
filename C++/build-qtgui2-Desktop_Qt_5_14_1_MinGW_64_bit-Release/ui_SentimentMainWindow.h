/********************************************************************************
** Form generated from reading UI file 'SentimentMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENTIMENTMAINWINDOW_H
#define UI_SENTIMENTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SentimentMainWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SentimentMainWindow)
    {
        if (SentimentMainWindow->objectName().isEmpty())
            SentimentMainWindow->setObjectName(QString::fromUtf8("SentimentMainWindow"));
        SentimentMainWindow->resize(800, 600);
        centralwidget = new QWidget(SentimentMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SentimentMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SentimentMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        SentimentMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SentimentMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SentimentMainWindow->setStatusBar(statusbar);

        retranslateUi(SentimentMainWindow);

        QMetaObject::connectSlotsByName(SentimentMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SentimentMainWindow)
    {
        SentimentMainWindow->setWindowTitle(QCoreApplication::translate("SentimentMainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SentimentMainWindow: public Ui_SentimentMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENTIMENTMAINWINDOW_H
