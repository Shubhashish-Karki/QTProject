#include "modeltest.h"
#include "ui_modeltest.h"
#include<alltests.h>
#include<QMessageBox>
#include<fstream>

ModelTest::ModelTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelTest)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/final.jpg");

    ui->label_pic->setPixmap(pix);

    ui->label_pic->resize(1920,1080);
}

void ModelTest::on_pushButton_clicked()
{

    fstream temp;
    temp.open("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/mediator.txt",ios::out);
    temp<<"C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/F1.csv";
    temp.close();
    QMessageBox::StandardButton reply=QMessageBox::question(this,"MODEL TEST-I","Are you ready?");

if(reply==QMessageBox::Yes)

{
    AllTests a;
    a.setModal(true);
    a.exec();
}


}

void ModelTest::on_pushButton_2_clicked()
{
    fstream temp;
    temp.open("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/mediator.txt",ios::out);
    temp<<"C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/F2.csv";
    temp.close();
    QMessageBox::StandardButton reply=QMessageBox::question(this,"MODEL TEST-II","Are you ready?");

    if(reply==QMessageBox::Yes)
    {

        AllTests a;
        a.setModal(true);
        a.exec();

    }

}

void ModelTest::on_pushButton_3_clicked()
{

    fstream temp;
    temp.open("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/mediator.txt",ios::out);
    temp<<"C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/F3.csv";
    temp.close();
    QMessageBox::StandardButton reply=QMessageBox::question(this,"MODEL TEST-III","Are you ready?");

    if(reply==QMessageBox::Yes)
    {

        AllTests a;
        a.setModal(true);

        a.exec();

    }

}


void ModelTest::on_pushButton_4_clicked()
    {
    fstream temp;
    temp.open("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/mediator.txt",ios::out);
    temp<<"C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/F4.csv";
    temp.close();
    QMessageBox::StandardButton reply=QMessageBox::question(this,"MODEL TEST-III","Are you ready?");

        if(reply==QMessageBox::Yes)
        {
            AllTests a;
            a.setModal(true);
            a.exec();
        }

    }


void ModelTest::on_pushButton_5_clicked()
    {
     fstream temp;
     temp.open("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/mediator.txt",ios::out);
     temp<<"C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/F5.csv";
     temp.close();
     QMessageBox::StandardButton reply=QMessageBox::question(this,"MODEL TEST-IV","Are you ready?");

        if(reply==QMessageBox::Yes)
        {

            AllTests a;
            a.setModal(true);
            a.exec();
        }

    }


ModelTest::~ModelTest()
{
    delete ui;
}

