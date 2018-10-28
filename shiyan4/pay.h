#ifndef PAY_H
#define PAY_H

#include <QMainWindow>
#include <QPrinter>

namespace Ui {
class pay;
}

class pay : public QMainWindow
{
    Q_OBJECT

public:
    explicit pay(QWidget *parent = 0);
    ~pay();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void doPrint();

    void doPrintPreview();

    void printPreview(QPrinter *printer);

    void setUpPage();


    void on_pushButton_2_clicked();

private:
    Ui::pay *ui;
};

#endif // PAY_H
