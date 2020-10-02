#ifndef MODELTEST_H
#define MODELTEST_H

#include <QDialog>
#include<vector>
#include<cstring>


namespace Ui {
class ModelTest;

}

class ModelTest : public QDialog
{
    Q_OBJECT

public:

    explicit ModelTest(QWidget *parent = nullptr);
    ~ModelTest();

public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:

    Ui::ModelTest *ui;
    std::string line,attribute;
    std::vector<std::string>col;
    std::vector<std::string>longstr;
};

#endif // MODELTEST_H
