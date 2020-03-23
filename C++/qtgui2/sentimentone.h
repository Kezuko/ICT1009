#ifndef SENTIMENTONE_H
#define SENTIMENTONE_H

#include <QMainWindow>

namespace Ui {
class SentimentOne;
}

class SentimentOne : public QMainWindow
{
    Q_OBJECT

public:
    explicit SentimentOne(QWidget *parent = nullptr);
    ~SentimentOne();

private:
    Ui::SentimentOne *ui;
};

#endif // SENTIMENTONE_H
