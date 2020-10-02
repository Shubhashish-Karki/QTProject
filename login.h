#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    void set_image();
    QString username,password;
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_SignUp_clicked();
    void on_LogIn_clicked();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
