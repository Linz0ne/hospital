#ifndef MANGER_H
#define MANGER_H

#include <QMainWindow>
#include "program.h"
#include "pay.h"
#include <QSqlTableModel>
namespace Ui {
class manger;
}

class manger : public QMainWindow
{
    Q_OBJECT

public:
    explicit manger(QWidget *parent = 0);
    ~manger();

private slots:
    void on_pushButtonpro_clicked();

    void on_pushButton_3_clicked();

    void on_pushButtonpsure_clicked();

    void on_tabWidget_2_tabBarClicked(int index);

    void on_pushButtonpcancel_clicked();

    void on_pushButtonpsel_clicked();

    void on_pushButtonpsure2_clicked();

    void on_pushButtonpcancle2_clicked();

    void on_tabWidget_2_tabBarDoubleClicked(int index);

    void on_pushButtonpsel_2_clicked();

    void on_pushButtonpsure2_2_clicked();

    void on_pushButtonpcancle2_2_clicked();

    void on_tabWidget_3_tabBarClicked(int index);

    void on_pushButtondsel_clicked();

    void on_pushButtondsure_clicked();

    void on_pushButtondcancle_clicked();

    void on_tabWidget_3_tabBarDoubleClicked(int index);

    void on_pushButtondsel2_clicked();

    void on_pushButtondsure2_clicked();

    void on_pushButtondcancle2_clicked();

    void on_tabWidget_4_tabBarClicked(int index);

    void on_pushButtonprosel_clicked();

    void on_pushButtonprosure_clicked();

    void on_pushButtonprocancle_clicked();

    void on_tabWidget_4_tabBarDoubleClicked(int index);

    void on_pushButtonprosel2_clicked();

    void on_pushButtonprosure2_clicked();

    void on_pushButtonprocancle2_clicked();

    void on_comboBoxdoctor_currentIndexChanged(const QString &arg1);

    void on_pushButtondsure_2_clicked();

    void on_pushButtondcancle_2_clicked();

    //void on_pushButtonprosure_2_clicked();

    //void on_pushButtonprocancle_2_clicked();

    void on_tabWidget_5_tabBarClicked(int index);

    void on_tabWidget_5_tabBarDoubleClicked(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_11_clicked();

    void on_comboBoxdoc_currentIndexChanged(const QString &arg1);


    void on_comboBoxdoc_3_currentIndexChanged(const QString &arg1);

    void on_pushButtonpeosel_clicked();

    void on_pushButton_peopro_clicked();

    void on_pushButtonpeopromoney_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_curesure_clicked();

    void on_pushButton_cureclear_clicked();

    void doPrint();

    void doPrintPreview();

    void printPreview(QPrinter *printer);

    void setUpPage();



private:
    Ui::manger *ui;
    program p;
    pay p1;
    QSqlTableModel *model;
};

#endif // MANGER_H
