#include "exam.h"
#include "ui_exam.h"
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
#include"result.h"

using namespace std;

//Initialization of global variables
int I=0;
int Marks=0;
int hrs{0},mins{0},secs{0};

exam::exam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exam)

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
    ui->lineEdit->setReadOnly(true);
    set_image();
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(function()));
    timer->start(1000);
}

void exam::set_image()
{
    QPixmap pix("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/cs.jpeg");
    ui->label_pic->setPixmap(pix);
    ui->label_pic->resize(1920,1080);
}


void exam::run_timer()
{
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(function()));
    timer->start(1000);
}

void exam::on_pushButton_clicked()
{
        filename="C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/exam.csv";
        fstream Questions;
        Questions.open(filename,ios::in);

        while(getline(Questions,line))
        {
            longstr.push_back(line);

        }
        Questions.close();
        stringstream s(longstr[0]);
        while(getline(s,attribute,'#'))
        {
        col.push_back(attribute);
        }


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
    ui->label_2->hide();
    ui->label->show();


do{
        stringstream s(longstr[I]);
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
        ui->checkBox->setEnabled(true);
        ui->checkBox_2->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        I++;
        break;
    }while(I<102);

    if(I==101)
    {
        ui->textEdit->hide();
        ui->textEdit->hide();
        ui->checkBox->hide();
        ui->checkBox_2->hide();
        ui->checkBox_3->hide();
        ui->checkBox_4->hide();
        ui->pushButton->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->pushButton_2->show();
        ui->lineEdit->hide();
        ui->lineEdit_2->hide();

    }
}
void exam::on_pushButton_2_clicked()
{
            string Smarks=to_string(Marks);
            ui->textEdit->show();
            ui->textEdit->resize(650,70);
            if(Marks>=40)
            {
            ui->textEdit->setText(QString::fromStdString("You passed the exam.You're score is:"+Smarks));
            ui->pushButton_2->hide();
            }
            if(Marks<40)
            {
            ui->textEdit->setText(QString::fromStdString("You failed the exam.You're score is:"+Smarks));
            ui->pushButton_2->hide();
            }
            Result r;
            r.setModal(true);
            r.exec();
}

void exam::function()
{
    secs++;
    QTime time(hrs,mins,secs);
    QString t_time=time.toString();
    ui->lineEdit->setText(t_time);



    if(secs==60)
    {
    secs=0;
    mins++;
    ui->lineEdit->setText(t_time);
    }

    if(mins==60)
    {
    secs=0;
    mins++;
    ui->lineEdit->setText(t_time);
    }

}

void exam::on_checkBox_stateChanged(int state)
{
    ui->checkBox->setDisabled(true);
    ui->checkBox_2->setDisabled(true);
    ui->checkBox_3->setDisabled(true);
    ui->checkBox_4->setDisabled(true);
    if(state)
    {
    if(col[5]==ui->checkBox->text().toStdString())
    {
        Marks++;
        cout<<Marks<<endl;
    }
   }

}


void exam::on_checkBox_2_stateChanged(int state)
{
    ui->checkBox->setDisabled(true);
    ui->checkBox_2->setDisabled(true);
    ui->checkBox_3->setDisabled(true);
    ui->checkBox_4->setDisabled(true);
    if(state)
    {
    if(col[5]==ui->checkBox_2->text().toStdString())
    {
        Marks++;
        cout<<Marks<<endl;
    }
   }
}

void exam::on_checkBox_3_stateChanged(int state)
{
    ui->checkBox->setDisabled(true);
    ui->checkBox_2->setDisabled(true);
    ui->checkBox_3->setDisabled(true);
    ui->checkBox_4->setDisabled(true);
    if(state)
    {
    if(col[5]==ui->checkBox_3->text().toStdString())
    {
        Marks++;
        cout<<Marks<<endl;
    }
   }
}
void exam::on_checkBox_4_stateChanged(int state)
{
    ui->checkBox->setDisabled(true);
    ui->checkBox_2->setDisabled(true);
    ui->checkBox_3->setDisabled(true);
    ui->checkBox_4->setDisabled(true);
    if(state)
    {
    if(col[5]==ui->checkBox_4->text().toStdString())
    {
        Marks++;
        cout<<Marks<<endl;
    }
   }
}
 //Destructor
exam::~exam()
{
    delete ui;//Frees the memory stored by ui pointer
}
