#include "menus.h"
#include "ui_menus.h"
#include "QDialog"
#include "QMessageBox"
#include "modeltest.h"
#include <QPixmap>
#include<allsyllabus.h>
#include<exam.h>
#include<challenges.h>
#include<leaderboard.h>




Menus::Menus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menus)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/aw.jpeg");

    ui->label_pic->setPixmap(pix);

    ui->label_pic->resize(1920,1080);
}

void Menus::on_Test_clicked()
{

//Opens the dialogbox Menus
    ModelTest t;
    t.setModal(true);
    t.exec();

}

void Menus::on_Exam_clicked()
{

QMessageBox::information(this,"Exam","Exam time!!");
exam e;
e.setModal(true);
e.exec();

}
void Menus::on_Syllabus_clicked()
{
/*QMessageBox::information(this,"Syllabus","Syllabus for All subjects are available");*/

    allsyllabus s;
    s.setModal(true);
    s.exec();
}

void Menus::on_References_clicked()
{
   QMessageBox::information(this,"References","Coming Soon..");
}

void Menus::on_Challanges_clicked()
{
  QMessageBox::information(this,"Challenges","Hurrah!Daily Challenges");
  Challenges c;
  c.setModal(true);
  c.exec();
}

void Menus::on_pushButton_clicked()
{
    Leaderboard l;
    l.setModal(true);
    l.exec();
}

Menus::~Menus()
{
    delete ui;
}
