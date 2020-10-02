#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //QApplication takes command line arguments
    Login w;                    //An object of class Login is created
    w.show();                   //Without show() window is never going to open
    w.setFixedSize(1200,600);   //Fixes the size of Login Window
    return a.exec();            //The program goes inside the event loop until exit
}
