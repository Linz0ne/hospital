#include "program.h"
#include "ui_program.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

extern QString senddata;

program::program(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::program)
{
    ui->setupUi(this);
    ui->lineEditpname->setEnabled(false);

}
program::~program()
{
    delete ui;
}

void program::on_pushButton_clicked()
{
    QString str;
    str="项目：";
    str=str+'\n';
    double infactmoney;
    if(ui->checkBox_one->isChecked())
     {
        str+=ui->checkBox_one->text();
        str=str+'\n';
        QSqlQuery query1;
        QString sql1 ="select price from program where proid=1";
        query1.exec(sql1);
        while(query1.next())
         {
         double pid1 = query1.value("price").toDouble();

         infactmoney+=pid1;
         }
     }
    if(ui->checkBox_2one->isChecked())
    {
      str+=ui->checkBox_2one->text();
      str=str+'\n';
      QSqlQuery query2;
      QString sql2 ="select price from program where proid=2";
      query2.exec(sql2);
      while(query2.next())
      {
      double pid2 = query2.value("price").toDouble();
      //QMessageBox::information(this,"结果",pid1);
      infactmoney+=pid2;}
    }
    if(ui->checkBox_3one->isChecked())
      {str+=ui->checkBox_3one->text();
      str=str+'\n';
      QSqlQuery query3;
      QString sql3 ="select price from program where proid=3";
      query3.exec(sql3);
      while(query3.next())
      {
      double pid3 = query3.value("price").toDouble();
      //QMessageBox::information(this,"结果",pid1);
      infactmoney+=pid3;}}
    if(ui->checkBox_4one->isChecked())
    {
      str+=ui->checkBox_4one->text();
    QSqlQuery query4;
    QString sql4 ="select price from program where proid=4";
    query4.exec(sql4);
    while(query4.next())
    {
    double pid4 = query4.value("price").toDouble();
    //QMessageBox::information(this,"结果",pid1);
    infactmoney+=pid4;
    str=str+'\n';
    }}
    if(ui->checkBox_5one->isChecked())
      {str+=ui->checkBox_5one->text();
    str=str+'\n';
    QSqlQuery query5;
    QString sql5 ="select price from program where proid=5";
    query5.exec(sql5);
    while(query5.next())
    {
    double pid5 = query5.value("price").toDouble();
    //QMessageBox::information(this,"结果",pid1);
    infactmoney+=pid5;}}

    if(ui->checkBox_6one->isChecked())
      {str+=ui->checkBox_6one->text();
    str=str+'\n';
    QSqlQuery query6;
    QString sql6 ="select price from program where proid=6";
    query6.exec(sql6);
    while(query6.next())
    {
    double pid6 = query6.value("price").toDouble();
    //QMessageBox::information(this,"结果",pid1);
    infactmoney+=pid6;}}
    if(ui->checkBox_7one->isChecked())
      {str+=ui->checkBox_7one->text();
    str=str+'\n';
    QSqlQuery query7;
    QString sql7 ="select price from program where proid=7";
    query7.exec(sql7);
    while(query7.next())
    {
    double pid7 = query7.value("price").toDouble();
    //QMessageBox::information(this,"结果",pid1);
    infactmoney+=pid7;}}
    if(ui->checkBox_8one->isChecked())
      {str+=ui->checkBox_8one->text();
    str=str+'\n';
    QSqlQuery query8;
    QString sql8 ="select price from program where proid=36";
    query8.exec(sql8);
    while(query8.next())
    {
    double pid8 = query8.value("price").toDouble();
    //QMessageBox::information(this,"结果",pid1);
    infactmoney+=pid8;}}
    if(ui->checkBox_two->isChecked())
      {str+=ui->checkBox_two->text();
    str=str+'\n';
    QSqlQuery query9;
    QString sql9 ="select price from program where proid=8";
    query9.exec(sql9);
    while(query9.next())
    {
    double pid9 = query9.value("price").toDouble();
    //QMessageBox::information(this,"结果",pid1);
    infactmoney+=pid9;}}
    if(ui->checkBox_2two->isChecked())
     { str+=ui->checkBox_2two->text();
       str=str+'\n';
       QSqlQuery query38;
       QString sql38 ="select price from program where proid=9";
       query38.exec(sql38);
       while(query38.next())
       {
       double pid38 = query38.value("price").toDouble();
       //QMessageBox::information(this,"结果",pid1);
       infactmoney+=pid38;}}

    if(ui->checkBox_3two->isChecked())
     { str+=ui->checkBox_3two->text();
    str=str+'\n';
    QSqlQuery query11;
    QString sql11 ="select price from program where proid=10";
    query11.exec(sql11);
    while(query11.next())
    {
    double pid11 = query11.value("price").toDouble();
    //QMessageBox::information(this,"结果",pid1);
    infactmoney+=pid11;}}
    if(ui->checkBox_4two->isChecked())
     { str+=ui->checkBox_4two->text();
     str=str+'\n';
     QSqlQuery query12;
     QString sq12 ="select price from program where proid=11";
     query12.exec(sq12);
     while(query12.next())
     {
     double pid12= query12.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid12;
     }}
    if(ui->checkBox_5two->isChecked())
      {str+=ui->checkBox_5two->text();
     str=str+'\n';
     QSqlQuery query14;
     QString sq14 ="select price from program where proid=12";
     query14.exec(sq14);
     while(query14.next())
     {
     double pid14 = query14.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid14;
     }}
    if(ui->checkBox_6two->isChecked())
      {str+=ui->checkBox_6two->text();
     str=str+'\n';
     QSqlQuery query15;
     QString sql15 ="select price from program where proid=13";
     query15.exec(sql15);
     while(query15.next())
     {
     double pid15 = query15.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid15;}}
    if(ui->checkBox_7two->isChecked())
     { str+=ui->checkBox_7two->text();
     str=str+'\n';
     QSqlQuery query16;
     QString sql16="select price from program where proid=14";
     query16.exec(sql16);
     while(query16.next())
     {
     double pid16 = query16.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid16;}}
    if(ui->checkBox_8two->isChecked())
      {str+=ui->checkBox_8two->text();
     str=str+'\n';
     QSqlQuery query17;
     QString sql17 ="select price from program where proid=35";
     query17.exec(sql17);
     while(query17.next())
     {
     double pid17 = query17.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid17;}}
    if(ui->checkBox_three->isChecked())
     { str+=ui->checkBox_three->text();
     str=str+'\n';
     QSqlQuery query18;
     QString sql18 ="select price from program where proid=15";
     query18.exec(sql18);
     while(query18.next())
     {
     double pid18 = query18.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid18;}}
    if(ui->checkBox_2three->isChecked())
     { str+=ui->checkBox_2three->text();
     str=str+'\n';
     QSqlQuery query19;
     QString sql19 ="select price from program where proid=16";
     query19.exec(sql19);
     while(query19.next())
     {
     double pid19 = query19.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid19;}}
    if(ui->checkBox_3three->isChecked())
      {str+=ui->checkBox_3three->text();
     str=str+'\n';
     QSqlQuery query20;
     QString sql20 ="select price from program where proid=17";
     query20.exec(sql20);
     while(query20.next())
     {
     double pid20 = query20.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid20;}}
    if(ui->checkBox_4three->isChecked())
      {str+=ui->checkBox_4three->text();
     str=str+'\n';
     QSqlQuery query21;
     QString sql21="select price from program where proid=18";
     query21.exec(sql21);
     while(query21.next())
     {
     double pid21 = query21.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid21;}}
    if(ui->checkBox_5three->isChecked())
      {str+=ui->checkBox_6three->text();
     str=str+'\n';
     QSqlQuery query22;
     QString sql22="select price from program where proid=19";
     query22.exec(sql22);
     while(query22.next())
     {
     double pid22 = query22.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid22;}}
    if(ui->checkBox_6three->isChecked())
      {str+=ui->checkBox_6three->text();
     str=str+'\n';
     QSqlQuery query37;
     QString sql37 ="select price from program where proid=20";
     query37.exec(sql37);
     while(query37.next())
     {
     double pid37 = query37.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid37;}}
    if(ui->checkBox_7three->isChecked())
      {str+=ui->checkBox_7three->text();
     str=str+'\n';
     QSqlQuery query23;
     QString sql23 ="select price from program where proid=21";
     query23.exec(sql23);
     while(query23.next())
     {
     double pid23 = query23.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid23;}}
    if(ui->checkBox_four->isChecked())
      {str+=ui->checkBox_four->text();
     str=str+'\n';
     QSqlQuery query24;
     QString sql24 ="select price from program where proid=22";
     query24.exec(sql24);
     while(query24.next())
     {
     double pid24 = query24.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid24;}}
    if(ui->checkBox_2four->isChecked())
      {str+=ui->checkBox_2four->text();
     str=str+'\n';
     QSqlQuery query25;
     QString sql25 ="select price from program where proid=23";
     query25.exec(sql25);
     while(query25.next())
     {
     double pid25 = query25.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid25;}}
    if(ui->checkBox_3four->isChecked())
     { str+=ui->checkBox_3four->text();
     str=str+'\n';
     QSqlQuery query26;
     QString sql26 ="select price from program where proid=24";
     query26.exec(sql26);
     while(query26.next())
     {
     double pid26 = query26.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid26;}}
    if(ui->checkBox_4four->isChecked())
      {str+=ui->checkBox_4four->text();
     str=str+'\n';
     QSqlQuery query27;
     QString sql27 ="select price from program where proid=25";
     query27.exec(sql27);
     while(query27.next())
     {
     double pid27 = query27.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid27;}}
    if(ui->checkBox_5four->isChecked())
      {str+=ui->checkBox_5four->text();
     str=str+'\n';
     QSqlQuery query28;
     QString sql28 ="select price from program where proid=26";
     query28.exec(sql28);
     while(query28.next())
     {
     double pid28 = query28.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid28;}}
    if(ui->checkBox_6four->isChecked())
      {str+=ui->checkBox_6four->text();
    str=str+'\n';
    QSqlQuery query29;
    QString sql29 ="select price from program where proid=27";
    query29.exec(sql29);
    while(query29.next())
    {
    double pid29 = query29.value("price").toDouble();
    //QMessageBox::information(this,"结果",pid1);
    infactmoney+=pid29;}}
    if(ui->checkBox_7four->isChecked())
      {str+=ui->checkBox_7four->text();
     str=str+'\n';
     QSqlQuery query30;
     QString sql30 ="select price from program where proid=28";
     query30.exec(sql30);
     while(query30.next())
     {
     double pid30 = query30.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid30;}}
    if(ui->checkBox_five->isChecked())
     { str+=ui->checkBox_five->text();
     str=str+'\n';
     QSqlQuery query31;
     QString sql31 ="select price from program where proid=29";
     query31.exec(sql31);
     while(query31.next())
     {
     double pid31= query31.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid31;}}
    if(ui->checkBox_2five->isChecked())
      {str+=ui->checkBox_2five->text();
     str=str+'\n';
     QSqlQuery query32;
     QString sql32 ="select price from program where proid=30";
     query32.exec(sql32);
     while(query32.next())
     {
     double pid32 = query32.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid32;}}
    if(ui->checkBox_3five->isChecked())
      {str+=ui->checkBox_3five->text();
     str=str+'\n';
     QSqlQuery query33;
     QString sql33 ="select price from program where proid=31";
     query33.exec(sql33);
     while(query33.next())
     {
     double pid33 = query33.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid33;}}
    if(ui->checkBox_4five->isChecked())
      {str+=ui->checkBox_4five->text();
     str=str+'\n';
     QSqlQuery query34;
     QString sql34 ="select price from program where proid=32";
     query34.exec(sql34);
     while(query34.next())
     {
     double pid34 = query34.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid34;}}
    if(ui->checkBox_5five->isChecked())
      {str+=ui->checkBox_5five->text();
     str=str+'\n';
     QSqlQuery query35;
     QString sql35 ="select price from program where proid=33";
     query35.exec(sql35);
     while(query35.next())
     {
     double pid35 = query35.value("price").toDouble();
     //QMessageBox::information(this,"结果",pid1);
     infactmoney+=pid35;}}
     if(ui->checkBox_6five->isChecked())
       {str+=ui->checkBox_5five->text();
      str=str+'\n';
      QSqlQuery query35;
      QString sql35 ="select price from program where proid=34";
      query35.exec(sql35);
      while(query35.next())
      {
      double pid35 = query35.value("price").toDouble();
      //QMessageBox::information(this,"结果",pid1);
      infactmoney+=pid35;}}
      if(ui->checkBox_7five->isChecked())
       { str+=ui->checkBox_5five->text();
       str=str+'\n';
       QSqlQuery query36;
       QString sql36 ="select price from program where proid=37";
       query36.exec(sql36);
       while(query36.next())
       {
       double pid36 = query36.value("price").toDouble();
       //QMessageBox::information(this,"结果",pid1);
       infactmoney+=pid36;
       qDebug("%.2f", infactmoney);
       }}

     //插入项目
      QString pro= QString ("UPDATE patient SET program = '%1'  WHERE pid = %2").arg(str).arg(senddata);

      QSqlQuery query;
      query.exec(pro);

      //插入金额
      QSqlQuery query99;
      QString infactmoneys=QString::number(infactmoney);
      QString pro1= QString ("UPDATE patient SET money = '%1'  WHERE pid = %2").arg(infactmoneys).arg(senddata);



       if(query99.exec(pro1))

       {
          QMessageBox::information(this,"结果","添加成功");
              ui->checkBox_one->setChecked(false);
              ui->checkBox_2one->setChecked(false);
              ui->checkBox_3one->setChecked(false);
              ui->checkBox_4one->setChecked(false);
              ui->checkBox_5one->setChecked(false);
              ui->checkBox_6one->setChecked(false);
              ui->checkBox_7one->setChecked(false);
              ui->checkBox_8one->setChecked(false);
              ui->checkBox_two->setChecked(false);
              ui->checkBox_2two->setChecked(false);
              ui->checkBox_3two->setChecked(false);
              ui->checkBox_4two->setChecked(false);
              ui->checkBox_5two->setChecked(false);
              ui->checkBox_6two->setChecked(false);
              ui->checkBox_7two->setChecked(false);
              ui->checkBox_8two->setChecked(false);
              ui->checkBox_three->setChecked(false);
              ui->checkBox_2three->setChecked(false);
              ui->checkBox_3three->setChecked(false);
              ui->checkBox_4three->setChecked(false);
              ui->checkBox_5three->setChecked(false);
              ui->checkBox_6three->setChecked(false);
              ui->checkBox_7three->setChecked(false);
              ui->checkBox_four->setChecked(false);
              ui->checkBox_2four->setChecked(false);
              ui->checkBox_3four->setChecked(false);
              ui->checkBox_4four->setChecked(false);
              ui->checkBox_5four->setChecked(false);
              ui->checkBox_6four->setChecked(false);
              ui->checkBox_7four->setChecked(false);
              ui->checkBox_five->setChecked(false);
              ui->checkBox_2five->setChecked(false);
              ui->checkBox_3five->setChecked(false);
              ui->checkBox_4five->setChecked(false);
              ui->checkBox_5five->setChecked(false);
              ui->checkBox_6five->setChecked(false);
              ui->checkBox_7five->setChecked(false);
      }

              /*
          QMessageBox::information(this,"结果","添加成功");*/


   /* if(ui->checkBox_7five->isChecked())
      {
        str=ui->checkBox_7five->text();
        QString pro= QString ("UPDATE patient SET program = '%1'  WHERE pid = %2").arg(str).arg(senddata);
        QMessageBox::information(this,"结果",pro);
        QSqlQuery query;
        query.exec(pro);
    }*/
    /*QMessageBox::information(this,"结果",pro);
    QSqlQuery query;
    query.exec(pro);
    if(query.exec(pro))
       QMessageBox::information(this,"结果","添加成功");
    else
       QMessageBox::information(this,"结果","添加失败");*/
     ui->label_2->clear();


}

void program::on_pushButton_3_clicked()
{
    ui->label_2->setText(senddata);
    QSqlQuery query56;
    QString sql56 =QString("select pname from patient  where pid='%1';").arg(senddata);

    query56.exec(sql56);
    while(query56.next())
    {QString did56 = query56.value("pname").toString();
    ui->lineEditpname->setText(did56);}
}

void program::on_pushButton_2_clicked()
{
    ui->checkBox_one->setChecked(false);
    ui->checkBox_2one->setChecked(false);
    ui->checkBox_3one->setChecked(false);
    ui->checkBox_4one->setChecked(false);
    ui->checkBox_5one->setChecked(false);
    ui->checkBox_6one->setChecked(false);
    ui->checkBox_7one->setChecked(false);
    ui->checkBox_8one->setChecked(false);
    ui->checkBox_two->setChecked(false);
    ui->checkBox_2two->setChecked(false);
    ui->checkBox_3two->setChecked(false);
    ui->checkBox_4two->setChecked(false);
    ui->checkBox_5two->setChecked(false);
    ui->checkBox_6two->setChecked(false);
    ui->checkBox_7two->setChecked(false);
    ui->checkBox_8two->setChecked(false);
    ui->checkBox_three->setChecked(false);
    ui->checkBox_2three->setChecked(false);
    ui->checkBox_3three->setChecked(false);
    ui->checkBox_4three->setChecked(false);
    ui->checkBox_5three->setChecked(false);
    ui->checkBox_6three->setChecked(false);
    ui->checkBox_7three->setChecked(false);
    ui->checkBox_four->setChecked(false);
    ui->checkBox_2four->setChecked(false);
    ui->checkBox_3four->setChecked(false);
    ui->checkBox_4four->setChecked(false);
    ui->checkBox_5four->setChecked(false);
    ui->checkBox_6four->setChecked(false);
    ui->checkBox_7four->setChecked(false);
    ui->checkBox_five->setChecked(false);
    ui->checkBox_2five->setChecked(false);
    ui->checkBox_3five->setChecked(false);
    ui->checkBox_4five->setChecked(false);
    ui->checkBox_5five->setChecked(false);
    ui->checkBox_6five->setChecked(false);
    ui->checkBox_7five->setChecked(false);

}
