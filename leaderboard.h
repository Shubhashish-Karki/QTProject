#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QDialog>

namespace Ui {
class Leaderboard;
}

struct users
{

 std::string first_name;
 std::string last_name;
 std::string marks;

 };


class Leaderboard : public QDialog
{
    Q_OBJECT

public:
    void sort_result();
    explicit Leaderboard(QWidget *parent = nullptr);
    ~Leaderboard();

private:
    Ui::Leaderboard *ui;
};

#endif // LEADERBOARD_H
