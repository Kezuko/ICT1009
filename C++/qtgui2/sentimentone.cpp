#include "sentimentone.h"
#include "ui_sentimentone.h"

SentimentOne::SentimentOne(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SentimentOne)
{
    ui->setupUi(this);
}

SentimentOne::~SentimentOne()
{
    delete ui;
}
