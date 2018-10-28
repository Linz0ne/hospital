#include "pay.h"
#include "ui_pay.h"
#include <manger.h>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
//打印头文件
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QFileDialog>
#include <QFileInfo>
#include <QPageSetupDialog>
#include <QDialog>
#include <QPrinter>

extern QString senddata;
extern QString linediname;
pay::pay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pay)
{
    ui->setupUi(this);
    ui->lineEditnames->setEnabled(false);
    ui->textEditprograms->setEnabled(false);
    ui->lineEditdoctors->setEnabled(false);
    ui->lineEditmoneys->setEnabled(false);
    ui->lineEditpaytmie->setEnabled(false);
    connect(ui->pushButton_dpv,SIGNAL(clicked()),this,SLOT(doPrintPreview()));
    connect(ui->pushButton_dp,SIGNAL(clicked()),this,SLOT(doPrint()));
}

pay::~pay()
{
    delete ui;
}
void pay::on_pushButton_clicked()
{
    //实际金额,次数,缴费状态
    QSqlQuery query77;
    QString pro77= QString ("UPDATE patient SET pay = '%1',paycount='%2',paym='%3',pays='%1' WHERE pid = %4").arg(ui->lineEditfact->text()).arg(ui->lineEditcishu->text()).arg(ui->comboBox->currentText()).arg(senddata);
    query77.exec(pro77);
    ui->label_9->clear();
    QMessageBox::information(this,"结果","添加成功");
}

void pay::on_pushButton_3_clicked()
{
    ui->label_9->setText(senddata);
    ui->lineEditnames->setText(linediname);
    QSqlQuery query1;
    QString sql1 ="select pname, program,doc,money,paytime from patient order by pid desc limit 1 ";
    query1.exec(sql1);
    while(query1.next())
    {
    QString pid1 = query1.value("pname").toString();
    QString pid2 = query1.value("program").toString();
    QString pid3 = query1.value("doc").toString();
    QString pid4 = query1.value("money").toString();
    QString pid5 = query1.value("paytime").toString();

    //QMessageBox::information(this,"结果",pid1);
    ui->lineEditnames->setText(pid1);
    ui->textEditprograms->setText(pid2);
    ui->lineEditdoctors->setText(pid3);
    ui->lineEditmoneys->setText(pid4);
    ui->lineEditpaytmie->setText(pid5);

    }
}
void pay::doPrint()
{
   // 创建打印机对象
    QPrinter printer;
    // 创建打印对话框
    QString printerName = printer.printerName();
    if ( printerName.size() == 0)
        return ;
    QPrintDialog dlg(&printer,  this );
    if  (dlg.exec() == QDialog::Accepted)
    {
       ui->widgetpay->render(&printer);

    }
}

void pay::doPrintPreview()
{
    QPrinter printer;
    // 创建打印预览对话框
    QPrintPreviewDialog preview(&printer,  this );
    // 当要生成预览页面时，发射paintRequested()信号
    connect(&preview, SIGNAL(paintRequested(QPrinter*)),
                  this ,SLOT(printPreview(QPrinter*)));
    preview.exec();
}

void pay::printPreview(QPrinter *printer)
{
    ui->widgetpay->render(printer);
}

void pay::setUpPage()
{
    QPrinter printer;
    QPageSetupDialog pageSetUpdlg(&printer,  this );
    if  (pageSetUpdlg.exec() == QDialog::Accepted)
    {
        printer.setOrientation(QPrinter::Landscape);
}
else
{
    printer.setOrientation(QPrinter::Portrait);
}
}

void pay::on_pushButton_2_clicked()
{
    ui->label_9->clear();
    ui->lineEditnames->clear();
    ui->textEditprograms->clear();
    ui->lineEditdoctors->clear();
    ui->lineEditmoneys->clear();
    ui->lineEditpaytmie->clear();
}
