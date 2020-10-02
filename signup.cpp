#include "signup.h"
#include "ui_signup.h"
#include<iostream>
#include<fstream>
#include<QMessageBox>
#include<QString>
#include<QDebug>
#include<QPixmap>

using namespace std;

Signup::Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
    set_image();

}

void Signup::set_image()
{
QPixmap pix("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/aw.jpeg");

ui->label_pic->setPixmap(pix);

ui->label_pic->resize(1920,1080);
}

void Signup::on_Submit_clicked()
{

    QString UserID=ui->lineEdit_usr->text();
    QString Pwd=ui->lineEdit_pwd->text();
    QString VerifyPwd=ui->lineEdit_verpwd->text();

//Very useful for debugging
   /* qDebug()<<UserID.toUtf8();
    qDebug()<<Pwd.toUtf8();
    qDebug()<<VerifyPwd.toUtf8();*/

    if(Pwd.toStdString()==VerifyPwd.toStdString())
    {
        int pwd_length=strlen(Pwd.toUtf8());        //the method toUtf8() converts QString to cstring
                int id_length=strlen(UserID.toUtf8());
                if(pwd_length>=8 and id_length>=8)
                {

                fstream file;
                file.open("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/User_info.csv",ios::app);
                //Write to the file
                file.seekg(0);
                file<<UserID.toStdString()<<","<<Pwd.toStdString()<<"\n";
                QMessageBox::information(this,"Success","Signed Up successfully");
                file.close();
                //Clear strings after you create an account
                ui->lineEdit_usr->setText(" ");
                ui->lineEdit_pwd->setText(" ");
                ui->lineEdit_verpwd->setText(" ");
                }

                if(pwd_length<=8 and id_length<=8)
                {
                QMessageBox::warning(this,"Failed","The username or password or both must be greater than 8 digits.");
                }


    }


    else
    {

        QMessageBox::information(this,"Failed","Incorrect Password");
    }
}

Signup::~Signup()
{
    delete ui;
}
