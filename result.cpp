#include "result.h"
#include "ui_result.h"
#include<fstream>


Result::Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
}


void Result::on_pushButton_clicked()
{

    //Get information from user
    QString First_name=ui->lineEdit->text();
    QString Last_name=ui->lineEdit_2->text();
    QString EntranceID=ui->lineEdit_3->text();

    //Write the above information to the file
    std::fstream result;
    result.open("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/Leaderboard.csv",std::ios::out);
    result<<First_name.toStdString()<<"#"<<Last_name.toStdString()<<"#"<<EntranceID.toStdString()<<"\n";

}

Result::~Result()
{
    delete ui;
}

