/********************************************************************************
** Form generated from reading UI file 'sentimentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENTIMENTDIALOG_H
#define UI_SENTIMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_SentimentDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SentimentDialog)
    {
        if (SentimentDialog->objectName().isEmpty())
            SentimentDialog->setObjectName(QString::fromUtf8("SentimentDialog"));
        SentimentDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(SentimentDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(SentimentDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SentimentDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SentimentDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SentimentDialog);
    } // setupUi

    void retranslateUi(QDialog *SentimentDialog)
    {
        SentimentDialog->setWindowTitle(QCoreApplication::translate("SentimentDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SentimentDialog: public Ui_SentimentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENTIMENTDIALOG_H
