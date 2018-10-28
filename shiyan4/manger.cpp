#include "manger.h"
#include "ui_manger.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QItemSelectionModel>
#include <QDateTime>
//打印头文件
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QFileDialog>
#include <QFileInfo>
#include <QPageSetupDialog>
#include <QDialog>
#include <QPrinter>

QString senddata;
QString linediname;

manger::manger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manger)
{
    ui->setupUi(this);
    QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("../hospmanger.db");
    }
    if(!db.open())
        qDebug()<<"数据库打开失败！";
    else
        qDebug()<<"数据库打开成功！";
    QSqlQueryModel *queryModel = new QSqlQueryModel(this); //新建模型
    queryModel->setQuery("select dname from doctor");//SQL语句4
    ui->comboBoxdoctor->setModel(queryModel);
    //linediname=QString ("%1").arg(ui->lineEditnum->text());

    QSqlQueryModel *queryModel1 = new QSqlQueryModel(this); //新建模型
    queryModel1->setQuery("select dname from doctor");//SQL语句4
    ui->comboBoxdoc->setModel(queryModel1);
    QSqlQueryModel *queryModel2 = new QSqlQueryModel(this); //新建模型
    queryModel2->setQuery("select dname from doctor");//SQL语句4
    ui->comboBoxdoc_3->setModel(queryModel2);
    ui->lineEditdid->setEnabled(false);
    ui->lineEdit_dp->setEnabled(false);
    ui->lineEdit_dm->setEnabled(false);
    ui->lineEdit_yp->setEnabled(false);
    ui->lineEdit_ym->setEnabled(false);
    ui->lineEditpid->setEnabled(false);

    ui->lineEdit_peo->setEnabled(false);
    ui->lineEdit_mon->setEnabled(false);
    ui->lineEdit_ypeo->setEnabled(false);
    ui->lineEdit_ymon->setEnabled(false);
    ui->pushButtonpro->setEnabled(false);
    ui->pushButton_3->setEnabled(false);


    //疗程管理
    ui->lineEdit_peopid->setEnabled(false);
    ui->lineEdit_peopname->setEnabled(false);
    ui->lineEdit_peopay->setEnabled(false);
    ui->lineEdit_peocount->setEnabled(false);
    ui->lineEdit_peopromon->setEnabled(false);
    ui->lineEdit_peopromoney->setEnabled(false);
    ui->lineEdit_pcount->setEnabled(false);
    ui->spinBox->setEnabled(false);
    ui->textEditprogram->setEnabled(false);
    ui->lineEdit_time->setEnabled(false);
    ui->lineEdit_docs->setEnabled(false);

    ui->pushButton_peopro->setEnabled(false);
    ui->pushButtonpeopromoney->setEnabled(false);
    connect(ui->pushButton_dpv,SIGNAL(clicked()),this,SLOT(doPrintPreview()));
    connect(ui->pushButton_dp,SIGNAL(clicked()),this,SLOT(doPrint()));
}

manger::~manger()
{
    delete ui;
}

void manger::on_pushButtonpro_clicked()
{
    senddata=QString ("%1").arg(ui->lineEditpid->text());
    p.show();
}

void manger::on_pushButton_3_clicked()
{
    senddata=QString ("%1").arg(ui->lineEditpid->text());
    p1.show();
}


//病人管理

void manger::on_pushButton_4_clicked()
{
    QString pid=QString ("INSERT INTO patient (pid,paytime)  VALUES (null,date('now'));");
    QSqlQuery query;
    query.exec(pid);
    QSqlQuery query1;
    QString sql1 ="select pid from patient order by pid desc limit 1 ";
    query1.exec(sql1);
    while(query1.next()){
    QString pid1 = query1.value("pid").toString();
    //QMessageBox::information(this,"结果",pid1);
    ui->lineEditpid->setText(pid1);}
    ui->pushButtonpro->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButtonpsure->setText("确认挂号");




}
void manger::on_pushButtonpsure_clicked()
{
    //QString pid=ui->lineEditnum->text();
    QString pname=ui->lineEditname->text();
    QString tel=ui->lineEdittel->text();
    QString age=ui->lineEditage->text();
    QString pidcard=ui->lineEditidcard->text();
    QString add=ui->lineEditadd->text();
    QString sex=ui->comboBoxsex->currentText();
    QString marry=ui->comboBoxmarry->currentText();
    QString doc=ui->comboBoxdoctor->currentText();
    QString other=ui->textEdit->toPlainText();
    QString sql1 ="select pid from patient order by pid desc limit 1 ";
    QSqlQuery query1;
    query1.exec(sql1);
    while(query1.next())
    {QString pid1 = query1.value("pid").toString();
    QString pinfo = QString ("UPDATE patient SET pname ='%1',sex = '%2',age ='%3',idcard ='%4',tel ='%5',address ='%6',marry ='%7',doc = '%8',other ='%10' WHERE pid = '%12';")
            .arg(pname).arg(sex).arg(age).arg(pidcard).arg(tel).arg(add).arg(marry).arg(doc).arg(other).arg(pid1);


    QSqlQuery query;

    if(query.exec(pinfo))
      {
           QMessageBox::information(this,"结果","添加成功");
           //ui->lineEditnum->clear();
           ui->lineEditname->clear();
           ui->lineEdittel->clear();
           ui->lineEditage->clear();
           ui->lineEditidcard->clear();
           ui->lineEditadd->clear();
           ui->textEdit->clear();
      }
    else
    {
       QMessageBox::information(this,"结果","添加失败,请重新输入");
    }
    ui->pushButtonpro->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButtonpsure->setText("确认添加");


}}
void manger::on_pushButtonpcancel_clicked()
{
    //ui->lineEditnum->clear();
    ui->lineEditname->clear();
    ui->lineEdittel->clear();
    ui->lineEditage->clear();
    ui->lineEditidcard->clear();
    ui->lineEditadd->clear();
    ui->textEdit->clear();
}
void manger::on_tabWidget_2_tabBarClicked(int index)
{
    model =new QSqlTableModel(this);
    model->setTable("patient");
    model->setHeaderData(0,Qt::Horizontal,"病人编号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(10,Qt::Horizontal,"性别");
    model->setHeaderData(11,Qt::Horizontal,"年龄");
    model->setHeaderData(12,Qt::Horizontal,"身份证号");
    model->setHeaderData(13,Qt::Horizontal,"电话");
    model->setHeaderData(14,Qt::Horizontal,"地址");
    model->setHeaderData(15,Qt::Horizontal,"婚姻状况");
    model->setHeaderData(7,Qt::Horizontal,"治疗医生");
    model->setHeaderData(9,Qt::Horizontal,"治疗项目");
    model->setHeaderData(4,Qt::Horizontal,"项目费用");
    model->setHeaderData(2,Qt::Horizontal,"总缴费");
    model->setHeaderData(5,Qt::Horizontal,"治疗次数");
    model->setHeaderData(6,Qt::Horizontal,"缴费状况");
    model->setHeaderData(8,Qt::Horizontal,"缴费时间");
    model->setHeaderData(16,Qt::Horizontal,"备注");
    model->setHeaderData(3,Qt::Horizontal,"剩余费用");


    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if( model->select())
       ui->tableViewp1->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}
void manger::on_comboBoxdoctor_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;
    QString sql = QString("select dname from doctor where dname='%2'").arg(arg1);
    query.exec(sql);

}
void manger::on_pushButtonpsel_clicked()
{
    QString pid= ui->lineEdit->text();
    QString str = QString("pid=%1").arg(pid);
    model->setFilter(str);
    model->select();
    if(model->select())
       ui->tableViewp1->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}

void manger::on_pushButtonpsure2_clicked()
{
    QMessageBox::information(this, "结果", "修改成功!");
    model->submitAll();
}

void manger::on_pushButtonpcancle2_clicked()
{
    model->revertAll();
    model->submitAll();
}

void manger::on_tabWidget_2_tabBarDoubleClicked(int index)
{
    model =new QSqlTableModel(this);
    model->setTable("patient");
    model->setHeaderData(0,Qt::Horizontal,"病人编号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(10,Qt::Horizontal,"性别");
    model->setHeaderData(11,Qt::Horizontal,"年龄");
    model->setHeaderData(12,Qt::Horizontal,"身份证号");
    model->setHeaderData(13,Qt::Horizontal,"电话");
    model->setHeaderData(14,Qt::Horizontal,"地址");
    model->setHeaderData(15,Qt::Horizontal,"婚姻状况");
    model->setHeaderData(7,Qt::Horizontal,"治疗医生");
    model->setHeaderData(9,Qt::Horizontal,"治疗项目");
    model->setHeaderData(4,Qt::Horizontal,"项目费用");
    model->setHeaderData(2,Qt::Horizontal,"总缴费");
    model->setHeaderData(5,Qt::Horizontal,"治疗次数");
    model->setHeaderData(6,Qt::Horizontal,"缴费状况");
    model->setHeaderData(8,Qt::Horizontal,"缴费时间");
    model->setHeaderData(16,Qt::Horizontal,"备注");
    model->setHeaderData(3,Qt::Horizontal,"剩余费用");
    if( model->select())
       ui->tableViewp2->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}

void manger::on_pushButtonpsel_2_clicked()
{
    QString pid= ui->lineEdit->text();
    QString str = QString("pid=%1").arg(pid);
    model->setFilter(str);
    model->select();
    if(model->select())
       ui->tableViewp2->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}

void manger::on_pushButtonpsure2_2_clicked()
{
    //获取模型中的值
    QItemSelectionModel *smodel = ui->tableViewp2->selectionModel();
    //取出模型中的索引
    QModelIndexList list = smodel->selectedRows();
    //删除所有选中的行
    for (int i = 0; i < list.size();i++)
       {
          model->removeRow( list.at(i).row());//删除选中的行
       }
    model->submitAll();
    QMessageBox::information(this, "结果", "删除成功!");
}

void manger::on_pushButtonpcancle2_2_clicked()
{
    model->revertAll();
    model->submitAll();
}
//医生管理
void manger::on_pushButtondsure_2_clicked()
{
    //QString did=ui->lineEditdid->text();
    QString dname=ui->lineEditdname->text();
    QString dsex=ui->comboBoxdsex->currentText();
    QString dage=ui->lineEditdage->text();
    QString dtel=ui->lineEditdtel->text();
    QString didcard=ui->lineEditdidcard->text();
    //QString total=ui->lineEditdtotal->text();
    QString sql1 ="select did from doctor order by did desc limit 1 ";
    QSqlQuery query1;
    query1.exec(sql1);
    while(query1.next())
    {QString did1 = query1.value("did").toString();
    QString dinfo = QString ("UPDATE doctor SET dname ='%1',sex = '%2',age ='%3',tel ='%4',idcard ='%5' WHERE did = '%6';")
            .arg(dname).arg(dsex).arg(dage).arg(didcard).arg(dtel).arg(did1);
    QSqlQuery query;
    if(query.exec(dinfo))
      {
           QMessageBox::information(this,"结果","添加成功");
           ui->lineEditdid->clear();
           ui->lineEditdname->clear();
           ui->lineEditdage->clear();
           ui->lineEditdtel->clear();
           ui->lineEditdidcard->clear();
           //ui->lineEditdtotal->clear();
      }
    else
       QMessageBox::information(this,"结果","添加失败,请重新输入");
}}

void manger::on_pushButtondcancle_2_clicked()
{
    ui->lineEditdid->clear();
    ui->lineEditdname->clear();
    ui->lineEditdage->clear();
    ui->lineEditdtel->clear();
    ui->lineEditdidcard->clear();
    //ui->lineEditdtotal->clear();
}

void manger::on_pushButton_11_clicked()
{
    QString did=QString ("INSERT INTO patient (pid)  VALUES (null);");
    QSqlQuery query;
    query.exec(did);
    QSqlQuery query1;
    QString sql1 ="select did from doctor order by did desc limit 1 ";
    query1.exec(sql1);
    while(query1.next())
    {
    QString did1 = query1.value("did").toString();
    //QMessageBox::information(this,"结果",pid1);
    ui->lineEditdid->setText(did1);
    }

}

void manger::on_tabWidget_3_tabBarClicked(int index)
{
    model =new QSqlTableModel(this);
    model->setTable("doctor");
    model->setHeaderData(0,Qt::Horizontal,"医生编号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"性别");
    model->setHeaderData(3,Qt::Horizontal,"年龄");
    model->setHeaderData(4,Qt::Horizontal,"电话");
    model->setHeaderData(5,Qt::Horizontal,"身份证号");
    model->setHeaderData(6,Qt::Horizontal,"治疗病人数");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if( model->select())
       ui->tableViewd1->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}

void manger::on_pushButtondsel_clicked()
{
    QString did= ui->lineEdit_3->text();
    QString str = QString("did=%1").arg(did);
    model->setFilter(str);
    model->select();
    if(model->select())
       ui->tableViewd1->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}

void manger::on_pushButtondsure_clicked()
{
    QMessageBox::information(this, "结果", "修改成功!");
    model->submitAll();
}

void manger::on_pushButtondcancle_clicked()
{
    model->revertAll();
    model->submitAll();
}

void manger::on_tabWidget_3_tabBarDoubleClicked(int index)
{
    model =new QSqlTableModel(this);
    model->setTable("doctor");
    model->setHeaderData(0,Qt::Horizontal,"医生编号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"性别");
    model->setHeaderData(3,Qt::Horizontal,"年龄");
    model->setHeaderData(4,Qt::Horizontal,"电话");
    model->setHeaderData(5,Qt::Horizontal,"身份证号");
    model->setHeaderData(6,Qt::Horizontal,"治疗病人数");
    if( model->select())
       ui->tableViewd2->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}

void manger::on_pushButtondsel2_clicked()
{
    QString did= ui->lineEdit_4->text();
    QString str = QString("did=%1").arg(did);
    model->setFilter(str);
    model->select();
    if(model->select())
       ui->tableViewd2->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}

void manger::on_pushButtondsure2_clicked()
{
    //获取模型中的值
    QItemSelectionModel *smodel = ui->tableViewd2->selectionModel();
    //取出模型中的索引
    QModelIndexList list = smodel->selectedRows();
    //删除所有选中的行
    for (int i = 0; i < list.size();i++)
       {
          model->removeRow( list.at(i).row());//删除选中的行
       }
    model->submitAll();
    QMessageBox::information(this, "结果", "删除成功!");
}

void manger::on_pushButtondcancle2_clicked()
{
    model->revertAll();
    model->submitAll();
}
//项目管理
/*void manger::on_pushButtonprosure_2_clicked()
{
    //QString proid=ui->lineEditproid->text();
    QString proname=ui->lineEditproname->text();
    QString price=ui->lineEditprice->text();
    QString proinfo = QString ("insert INTO program (proid,proname,price)VALUES (null,'%2','%3')")
            .arg(proname).arg(price);
    QMessageBox::information(this,"结果",proinfo);
    QSqlQuery query;
    if(query.exec(proinfo))
      {
           QMessageBox::information(this,"结果","添加成功");
           ui->lineEditproid->clear();
           ui->lineEditproname->clear();
           ui->lineEditprice->clear();
      }
    else
       QMessageBox::information(this,"结果","添加失败,请重新输入");
}*/

/*void manger::on_pushButtonprocancle_2_clicked()
{
    ui->lineEditproid->clear();
    ui->lineEditproname->clear();
    ui->lineEditprice->clear();
}*/

void manger::on_tabWidget_4_tabBarClicked(int index)
{
    model =new QSqlTableModel(this);
    model->setTable("program");
    model->setHeaderData(0,Qt::Horizontal,"项目编号");
    model->setHeaderData(1,Qt::Horizontal,"项目名称");
    model->setHeaderData(2,Qt::Horizontal,"单价");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if( model->select())
       ui->tableViewpro1->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}

void manger::on_pushButtonprosel_clicked()
{
    QString proid= ui->lineEdit_5->text();
    QString str = QString("proid=%1").arg(proid);
    model->setFilter(str);
    model->select();
    if(model->select())
       ui->tableViewpro1->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}

void manger::on_pushButtonprosure_clicked()
{
    QMessageBox::information(this, "结果", "修改成功!");
    model->submitAll();
}

void manger::on_pushButtonprocancle_clicked()
{
    model->revertAll();
    model->submitAll();
}

void manger::on_tabWidget_4_tabBarDoubleClicked(int index)
{
    model =new QSqlTableModel(this);
    model->setTable("program");
    model->setHeaderData(0,Qt::Horizontal,"项目编号");
    model->setHeaderData(1,Qt::Horizontal,"项目名称");
    model->setHeaderData(2,Qt::Horizontal,"单价");
    if( model->select())
       ui->tableViewpro2->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}

void manger::on_pushButtonprosel2_clicked()
{
    QString proid= ui->lineEdit_6->text();
    QString str = QString("proid=%1").arg(proid);
    model->setFilter(str);
    model->select();
    if(model->select())
       ui->tableViewpro2->setModel(model);
    else
       QMessageBox::information(this, "结果", "连接数据库失败!");
}

void manger::on_pushButtonprosure2_clicked()
{
    //获取模型中的值
    QItemSelectionModel *smodel = ui->tableViewpro2->selectionModel();
    //取出模型中的索引
    QModelIndexList list = smodel->selectedRows();
    //删除所有选中的行
    for (int i = 0; i < list.size();i++)
       {
          model->removeRow( list.at(i).row());//删除选中的行
       }
    model->submitAll();
    QMessageBox::information(this, "结果", "删除成功!");
}

void manger::on_pushButtonprocancle2_clicked()
{
    model->revertAll();
    model->submitAll();
}

void manger::on_tabWidget_5_tabBarClicked(int index)
{
    //当月人数
    QString sql1 ="select count(pid) from patient  where paytime  between datetime('now','start of month','+1 second') and datetime('now','start of month','+1 month','-1 second');";
    QSqlQuery query1;
    query1.exec(sql1);
    while(query1.next())
    {QString did1 = query1.value("count(pid)").toString();
    ui->lineEdit_dp->setText(did1);
    //当月金额
    QString sql2 ="select sum(pay) from patient  where paytime  between datetime('now','start of month','+1 second') and datetime('now','start of month','+1 month','-1 second');";
    QSqlQuery query2;
    query2.exec(sql2);
    while(query2.next())
    {QString did2 = query2.value("sum(pay)").toString();
    ui->lineEdit_dm->setText(did2);
}}
}

void manger::on_tabWidget_5_tabBarDoubleClicked(int index)
{
    //年度人数
    QString sql1 ="select count(pid) from patient  where paytime  between datetime('now','start of year','+1 second') and datetime('now','start of year','+1 year','-1 second');";
    QSqlQuery query1;
    query1.exec(sql1);
    while(query1.next())
    {QString did1 = query1.value("count(pid)").toString();
    ui->lineEdit_yp->setText(did1);
    //年度金额
    QString sql2 ="select sum(pay) from patient  where paytime  between datetime('now','start of year','+1 second') and datetime('now','start of year','+1 year','-1 second');";
    QSqlQuery query2;
    query2.exec(sql2);
    while(query2.next())
    {QString did2 = query2.value("sum(pay)").toString();
    ui->lineEdit_ym->setText(did2);
}}}


void manger::on_comboBoxdoc_currentIndexChanged(const QString &arg1)
{

        QSqlQuery query56;
        QString sql56 =QString("select count(pid),sum(pay) from patient  where doc='%1' and paytime  between datetime('now','start of month','+1 second') and datetime('now','start of month','+1 month','-1 second');").arg(arg1);
        query56.exec(sql56);
        while(query56.next())
        {QString did56 = query56.value("count(pid)").toString();
         QString did57 = query56.value("sum(pay)").toString();

         ui->lineEdit_peo->setText(did56);
         ui->lineEdit_mon->setText(did57);
        }
}

void manger::on_comboBoxdoc_3_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query56;
    QString sql56 =QString("select count(pid),sum(pay) from patient  where doc='%1' and paytime  between datetime('now','start of year','+1 second') and datetime('now','start of year','+1 year','-1 second');").arg(arg1);
    query56.exec(sql56);
     while(query56.next())
    {QString did56 = query56.value("count(pid)").toString();
     QString did57 = query56.value("sum(pay)").toString();

     ui->lineEdit_ypeo->setText(did56);
     ui->lineEdit_ymon->setText(did57);
    }
}

void manger::on_pushButtonpeosel_clicked()
{
    ui->spinBox->setEnabled(true);
    ui->pushButton_peopro->setEnabled(true);
    ui->pushButtonpeopromoney->setEnabled(true);
    ui->spinBox->setValue(0);

    senddata=ui->lineEdit_peosel->text();
    QSqlQuery query56;
    QString sql56 =QString("select pname,pays,paycount,doc from patient where pid='%1';").arg(senddata);
    query56.exec(sql56);
    while(query56.next())
    {
     QString did56 = query56.value("pname").toString();
     QString did57 = query56.value("pays").toString();
     QString did58 = query56.value("paycount").toString();
     QString did59 = query56.value("doc").toString();


     ui->lineEdit_peopid->setText(senddata);
     ui->lineEdit_peopname->setText(did56);
     ui->lineEdit_peopay->setText(did57);
     ui->lineEdit_pcount->setText(did58);
     ui->lineEdit_docs->setText(did59);
   }
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd");
    ui->lineEdit_time->setText(current_date);

}

void manger::on_pushButton_peopro_clicked()
{
    senddata=ui->lineEdit_peosel->text();
    p.show();
}

void manger::on_pushButtonpeopromoney_clicked()
{
    senddata=ui->lineEdit_peosel->text();
    QSqlQuery query56;
    QString sql56 =QString("select money,program from patient  where pid='%1';").arg(senddata);
    query56.exec(sql56);
    while(query56.next())
    {QString did56 = query56.value("money").toString();
     ui->lineEdit_peopromon->setText(did56);
     QString did57 = query56.value("program").toString();
     ui->textEditprogram->setText(did57);}
}

void manger::on_spinBox_valueChanged(int arg1)
{


    if(0==arg1)
    {
       ui->pushButton_curesure->setEnabled(false);

    }else
    {
        ui->pushButton_curesure->setEnabled(true);
    }
    if(arg1==1)
    {
       ui->spinBox->setEnabled(false);

    }else
    {
       ui->pushButton_curesure->setEnabled(true);
    }
    senddata=ui->lineEdit_peosel->text();
    QSqlQuery query;
    QString sql56 =QString("select paycount,pays,money from patient  where pid='%1';").arg(senddata);
    query.exec(sql56);
    int last;
    double pays;
    double moneys;
      while(query.next())
          {
             last=query.value("paycount").toInt();//剩余
             pays=query.value("pays").toDouble();
             moneys=query.value("money").toDouble();


          }
      if(arg1<=last && pays>=moneys)
      {
          int temNum = last - arg1;
          ui->lineEdit_peocount->setText(QString::number(temNum));
          double temNums = pays - moneys;
          ui->lineEdit_peopromoney->setText(QString::number(temNums));

      }
      else
      {
          QMessageBox::information(this,"提示","余额不足或治疗次数已用完");
          return;
      }


}

void manger::on_pushButton_curesure_clicked()
{
    senddata=ui->lineEdit_peosel->text();
    QSqlQuery query;
    QString sql56 =QString("update patient set pays='%1',paycount='%2' where pid='%3';").arg(ui->lineEdit_peopromoney->text()).arg(ui->lineEdit_peocount->text()).arg(senddata);
    query.exec(sql56);
    QMessageBox::information(this,"结果","添加成功");
}

void manger::on_pushButton_cureclear_clicked()
{
    ui->lineEdit_peosel->clear();
    ui->lineEdit_peopid->clear();
    ui->lineEdit_peopname->clear();
    ui->lineEdit_peopay->clear();
    ui->lineEdit_peocount->clear();
    ui->lineEdit_peopromon->clear();
    ui->lineEdit_peopromoney->clear();
    ui->lineEdit_pcount->clear();
}
void manger::doPrint()
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

void manger::doPrintPreview()
{
    QPrinter printer;
    // 创建打印预览对话框
    QPrintPreviewDialog preview(&printer,  this );
    // 当要生成预览页面时，发射paintRequested()信号
    connect(&preview, SIGNAL(paintRequested(QPrinter*)),
                  this ,SLOT(printPreview(QPrinter*)));
    preview.exec();
}

void manger::printPreview(QPrinter *printer)
{
    ui->widgetpay->render(printer);
}

void manger::setUpPage()
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
