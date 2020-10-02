#include "testi.h"
#include "ui_testi.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<QString>
using namespace std;

TestI::TestI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestI)
{
    ui->setupUi(this);

    }

}

TestI::~TestI()
{
    delete ui;
}


