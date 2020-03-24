#ifndef SENTIMENTDIALOG_H
#define SENTIMENTDIALOG_H

#include <QDialog>

namespace Ui {
class SentimentDialog;
}

class SentimentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SentimentDialog(QWidget *parent = nullptr);
    ~SentimentDialog();

private:
    Ui::SentimentDialog *ui;
};

#endif // SENTIMENTDIALOG_H
