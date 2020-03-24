#include "SentimentMainWindow.h"
#include "ui_SentimentMainWindow.h"

SentimentMainWindow::SentimentMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SentimentMainWindow)
{
    ui->setupUi(this);
}

SentimentMainWindow::~SentimentMainWindow()
{
    delete ui;
}
