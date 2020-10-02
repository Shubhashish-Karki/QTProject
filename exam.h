#ifndef EXAM_H
#define EXAM_H

#include <QDialog>
#include<iostream>
#include<QTimer>
#include<cstring>

using namespace std;

namespace Ui {
class exam;
}

class exam : public QDialog
{
    Q_OBJECT

public:
    void set_image();
    void run_timer();
    explicit exam(QWidget *parent = nullptr);
    ~exam();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_checkBox_stateChanged(int );
    void on_checkBox_2_stateChanged(int );
    void on_checkBox_3_stateChanged(int );
    void on_checkBox_4_stateChanged(int );

public slots:
    void function();

private:
    Ui::exam *ui;
    string filename;
    vector<string>col;
    vector<string>longstr;
    string line,attribute;
    QTimer *timer;
};

#endif // EXAM_H
