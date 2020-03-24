#include "sentimentdialog.h"
#include "ui_sentimentdialog.h"

SentimentDialog::SentimentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SentimentDialog)
{
    ui->setupUi(this);
}

SentimentDialog::~SentimentDialog()
{
    delete ui;
}
