#ifndef LOGGING_H
#define LOGGING_H

#include <QMainWindow>
#include "manger.h"
namespace Ui {
class logging;
}

class logging : public QMainWindow
{
    Q_OBJECT

public:
    explicit logging(QWidget *parent = 0);
    ~logging();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::logging *ui;
    manger m2;
};

#endif // LOGGING_H
