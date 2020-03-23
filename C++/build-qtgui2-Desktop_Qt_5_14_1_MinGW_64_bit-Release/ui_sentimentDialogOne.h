/********************************************************************************
** Form generated from reading UI file 'sentimentDialogOne.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENTIMENTDIALOGONE_H
#define UI_SENTIMENTDIALOGONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SentimentOne
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SentimentOne)
    {
        if (SentimentOne->objectName().isEmpty())
            SentimentOne->setObjectName(QString::fromUtf8("SentimentOne"));
        SentimentOne->resize(800, 600);
        centralwidget = new QWidget(SentimentOne);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SentimentOne->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SentimentOne);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        SentimentOne->setMenuBar(menubar);
        statusbar = new QStatusBar(SentimentOne);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SentimentOne->setStatusBar(statusbar);

        retranslateUi(SentimentOne);

        QMetaObject::connectSlotsByName(SentimentOne);
    } // setupUi

    void retranslateUi(QMainWindow *SentimentOne)
    {
        SentimentOne->setWindowTitle(QCoreApplication::translate("SentimentOne", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SentimentOne: public Ui_SentimentOne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENTIMENTDIALOGONE_H
