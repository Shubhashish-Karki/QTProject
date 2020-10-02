#include "challenges.h"
#include "ui_challenges.h"

Challenges::Challenges(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Challenges)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

void Challenges::set_image()
{
    QPixmap pix("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Free Entrance Preparation Platform/aw.jpeg");

    ui->label_pic->setPixmap(pix);

    ui->label_pic->resize(1920,1080);
}

Challenges::~Challenges()
{
    delete ui;
}
