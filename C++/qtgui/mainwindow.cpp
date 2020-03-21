#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_crawlTab_btnClick_clicked()
{

}

void MainWindow::on_displayTab_browseClick_clicked()
{

}

void MainWindow::on_displayTab_clearClick_clicked()
{

}

void MainWindow::on_searchTab_firstCsvBrowseClick_clicked()
{

}

void MainWindow::on_searchTab_secondCsvBrowseClick_clicked()
{

}

void MainWindow::on_searchTab_clearClick_clicked()
{

}

void MainWindow::on_statisticsTab_firstCsvBrowseClick_clicked()
{

}

void MainWindow::on_statisticsTab_secondCsvBrowseClick_clicked()
{

}

void MainWindow::on_statisticsTab_clearClick_clicked()
{

}
