#ifndef MENUS_H
#define MENUS_H

#include <QDialog>

namespace Ui {
class Menus;
}

class Menus : public QDialog
{
    Q_OBJECT

public:
    explicit Menus(QWidget *parent = nullptr);
    ~Menus();

private slots:
    void on_Test_clicked();
    void on_Exam_clicked();
    void on_Syllabus_clicked();
    void on_References_clicked();
    void on_Challanges_clicked();

    void on_pushButton_clicked();

private:
    Ui::Menus *ui;
};

#endif // MENUS_H
