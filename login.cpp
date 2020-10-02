#include "login.h"
#include "ui_login.h"
#include "QString"
#include "QMessageBox"
#include "QPixmap"
#include "menus.h"
#include "QFile"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<vector>
#include"signup.h"
#include<QDebug>

using namespace std;

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);


    QPixmap pix("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/child.jpeg");

    ui->label_pic->setPixmap(pix);

    ui->label_pic->resize(1920,1080);

}

void Login::set_image()
{

    QPixmap pix("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/child.jpeg");

    ui->label_pic->setPixmap(pix);

    ui->label_pic->resize(1920,1080);
}

void Login::on_LogIn_clicked()
{
    vector<string>info;
    fstream file;
    file.open("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/User_info.csv",ios::in);
    string line,word;

     username = ui->lineEdit->text();
     password = ui->lineEdit_2->text();

    //qDebug()<<username.toUtf8();
    while(file)
    {
        getline(file,line);
        stringstream s(line);
        info.clear();
        while(getline(s,word,','))
        {
        info.push_back(word);
        }
        cout<<info[0];

        if(info[0]==username.toStdString() && info[1]==password.toStdString())

        {

        file.close();

        QMessageBox::StandardButton reply=QMessageBox::question(this,"FEPP","Logged In Successfully."
                                                                            "Do you want to continue?",QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::Yes)
        {
        file.close();
        Menus m;
        m.setModal(true);
        m.exec();

         /*ui->statusbar->showMessage("Username and Password is correct",5000);*/

        }
        if(reply==QMessageBox::No)
        {

        file.close();
        /*QApplication::quit();*/

        }
        }
        else
        {
            if(file)
            {

                continue;
            }

            else
            {
            QMessageBox::information(this,"Submit","Incorrect Username or Password");
            /*ui->statusbar->showMessage("Username and Password is incorrect",5000);*/

            }
        }
}
}

void Login::on_SignUp_clicked()
{
Signup s;
s.setModal(true);
s.exec();

}

Login::~Login()
{
    delete ui;
}
