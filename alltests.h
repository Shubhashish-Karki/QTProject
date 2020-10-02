#ifndef ALLTESTS_H
#define ALLTESTS_H

#include <QDialog>
#include<vector>
#include<cstring>
#include<modeltest.h>
#include<iostream>
#include<QTimer>

using namespace std;
namespace Ui {
class AllTests;
}

class AllTests : public QDialog
{
    Q_OBJECT

public:

    explicit AllTests(QWidget *parent = nullptr);
    ~AllTests();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

public slots:
    void set_image();
    void run_timer();
    void function();

private:
    string filename;
    Ui::AllTests *ui;
    vector<string>col;
    vector<string>longstr;
    string line,attribute;
    QTimer *timer;

};

#endif // ALLTESTS_H
