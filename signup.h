#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

namespace Ui {
class Signup;
}

class Signup : public QDialog
{
    Q_OBJECT

public:

    explicit Signup(QWidget *parent = nullptr);
    void set_image();
    ~Signup();

private slots:

    void on_Submit_clicked();


private:

    Ui::Signup *ui;
};

#endif // SIGNUP_H
