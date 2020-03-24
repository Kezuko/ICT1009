#ifndef SENTIMENTMAINWINDOW_H
#define SENTIMENTMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class SentimentMainWindow;
}

class SentimentMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SentimentMainWindow(QWidget *parent = nullptr);
    ~SentimentMainWindow();

private:
    Ui::SentimentMainWindow *ui;
};

#endif // SENTIMENTMAINWINDOW_H
