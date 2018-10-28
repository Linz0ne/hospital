#include "logging.h"
#include "ui_logging.h"
#include <QMessageBox>

logging::logging(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::logging)
{
    ui->setupUi(this);
    ui->lineEditpassword->setEchoMode(QLineEdit::Password);
}

logging::~logging()
{
    delete ui;
}

void logging::on_pushButton_clicked()
{
    if(ui->lineEditname->text().trimmed()=="xihua"&&ui->lineEditpassword->text()==tr("xihua"))
      {
        this->close();
        m2.show();
      }
    else
    {
        QMessageBox::information(this,"登陆失败","用户名或密码错误");
        ui->lineEditname->clear();
        ui->lineEditpassword->clear();
    }
}

void logging::on_pushButton_2_clicked()
{
    this->close();
}
