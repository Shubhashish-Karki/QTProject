#ifndef CHALLENGES_H
#define CHALLENGES_H

#include <QDialog>

namespace Ui {
class Challenges;
}

class Challenges : public QDialog
{
    Q_OBJECT

public:
    void set_image();
    explicit Challenges(QWidget *parent = nullptr);
    ~Challenges();

private:
    Ui::Challenges *ui;
};

#endif // CHALLENGES_H
