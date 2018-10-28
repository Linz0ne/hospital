#ifndef PROGRAM_H
#define PROGRAM_H

#include <QMainWindow>

namespace Ui {
class program;
}

class program : public QMainWindow
{
    Q_OBJECT

public:
    explicit program(QWidget *parent = 0);
    ~program();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::program *ui;
};

#endif // PROGRAM_H
