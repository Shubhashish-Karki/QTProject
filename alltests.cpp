#include "alltests.h"
#include "ui_alltests.h"
#include<sstream>
#include<iostream>
#include<fstream>
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<modeltest.h>
#include<QString>
#include<QFileDialog>
#include<QProcess>
#include<QTime>
#include<login.h>

using namespace std;

int i=0;
int marks=0;
int h{0},m{0},s{0};

AllTests::AllTests(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AllTests)

{
    ui->setupUi(this);

    ui->textEdit->setReadOnly(true);
    ui->textEdit->hide();
    ui->checkBox->hide();
    ui->checkBox_2->hide();
    ui->checkBox_3->hide();
    ui->checkBox_4->hide();
    ui->pushButton_2->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->label->hide();
    ui->pushButton_3->hide();
    ui->lineEdit->setReadOnly(true);
    i=0;
    h=0,m=0,s=0;
    set_image();

}

void AllTests::set_image()
{
QPixmap pix("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/cs.jpeg");
ui->label_pic->setPixmap(pix);
ui->label_pic->resize(1920,1080);
run_timer();
}

void AllTests::on_pushButton_clicked()
{
        fstream temp;
        string f;
        temp.open("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/mediator.txt",ios::in);
        while(getline(temp,f))
        {
            filename=f;
            temp.close();
        }

        fstream Questions;
        Questions.open(filename,ios::in);

        while(getline(Questions,line))
        {
            longstr.push_back(line);
        }
        Questions.close();
        /*stringstream s(longstr[0]);
        while(getline(s,attribute,'#'))
        {
        col.push_back(attribute);
        }*/


    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);


    ui->textEdit->show();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->checkBox->show();
    ui->checkBox_2->show();
    ui->checkBox_3->show();


    ui->checkBox_4->show();
    ui->pushButton_2->hide();
    ui->pushButton_3->show();
    ui->label_2->hide();
    ui->label->show();
    ui->label_3->hide();


    if(i==20)
    {
        ui->textEdit->hide();
        ui->textEdit->hide();
        ui->checkBox->hide();
        ui->checkBox_2->hide();
        ui->checkBox_3->hide();
        ui->checkBox_4->hide();
        ui->pushButton->hide();
        ui->pushButton_2->show();
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->pushButton_3->hide();
        ui->lineEdit->hide();
        ui->lineEdit_2->hide();

    }


do{
        stringstream s(longstr[i]);
        col.clear();
        while(getline(s,attribute,'#'))
        {
        col.push_back(attribute);
        }
        ui->textEdit->setText(QString::fromStdString(col[0]));
        ui->checkBox->setText(QString::fromStdString(col[1]));
        ui->checkBox_2->setText(QString::fromStdString(col[2]));
        ui->checkBox_3->setText(QString::fromStdString(col[3]));
        ui->checkBox_4->setText(QString::fromStdString(col[4]));
        i++;
        if(ui->checkBox->isChecked())
        {
            if(col[5]==ui->checkBox->text().toStdString())
            {
                marks+=1;
            }
            else
            {
                marks=0;
            }
        }
        if(ui->checkBox_2->isChecked())
        {
            if(col[5]==ui->checkBox_2->text().toStdString())
            {
                marks+=1;
            }
            else
            {
                marks=0;
            }
        }
        if(ui->checkBox_3->isChecked())
        {
            if(col[5]==ui->checkBox_3->text().toStdString())
            {
                marks+=1;
            }
            else
            {
                marks=0;
            }
        }
        if(ui->checkBox_4->isChecked())
        {
            if(col[5]==ui->checkBox_4->text().toStdString())
            {
                marks+=1;
            }
            else
            {
                marks=0;
            }
        }
        break;
    }while(i<20);


}

void AllTests::on_pushButton_3_clicked()
{
    ui->label_3->show();
    ui->label_3->setText(QString::fromStdString(col[5]));

}

void AllTests::on_pushButton_2_clicked()
{
    //write results to a file
        //Will also create a file if not created
            ui->pushButton_2->hide();
            ui->label_4->show();
            ui->label_4->setText(QString::fromStdString("Thank you for taking a test."));

}

void AllTests::run_timer()
{
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(function()));
    timer->start(1000);
}

void AllTests::function()
{
    s++;
    QTime time(h,m,s);
    QString t_time=time.toString();
    ui->lineEdit->setText(t_time);

    if(s==60)
    {
    s=0;
    m++;
    ui->lineEdit->setText(t_time);
    }

    if(m==60)
    {
    m=0;
    h++;
    ui->lineEdit->setText(t_time);
    }

}

AllTests::~AllTests()
{
    delete ui;
}
