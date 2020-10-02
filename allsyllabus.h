#ifndef ALLSYLLABUS_H
#define ALLSYLLABUS_H

#include <QDialog>
#include<QScrollBar>

namespace Ui {
class allsyllabus;
}

class allsyllabus : public QDialog
{
    Q_OBJECT

public:
    void set_image();
    explicit allsyllabus(QWidget *parent = nullptr);
    ~allsyllabus();

private:
    Ui::allsyllabus *ui;
};

#endif // ALLSYLLABUS_H
