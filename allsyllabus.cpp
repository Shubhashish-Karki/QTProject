#include "allsyllabus.h"
#include "ui_allsyllabus.h"

allsyllabus::allsyllabus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allsyllabus)
{
    ui->setupUi(this);

    ui->textEdit->setReadOnly(true);
}

void allsyllabus::set_image()
{
    QPixmap pix("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/final.jpg");

    ui->label_pic->setPixmap(pix);

    ui->label_pic->resize(1920,1080);
}

allsyllabus::~allsyllabus()
{
    delete ui;
}



