#include "leaderboard.h"
#include "ui_leaderboard.h"
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

Leaderboard::Leaderboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Leaderboard)
{
    ui->setupUi(this);

    ui->textEdit->setReadOnly(true);

    sort_result();

}

void Leaderboard::sort_result()
{

/*Read the data from file, sort them and rewrite the file*/
    fstream result;
    result.open("C:/Users/Amrit/Documents/build-Button-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/build-Login-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Leaderboard.csv",ios::in);
    vector<string>info;

    string line;
    int count=0;// To count number of lines in the file

    while(getline(result,line))
    {

        count++;
        info.push_back(line);


    }
    users u[count];
    string word;
    vector<string>words;

    for(int i=0;i<count;i++)
    {

        stringstream s(info[i]);

        words.clear();
        while(getline(s,word,','))
        {
            words.push_back(word);
        }
        u[i].first_name=words[0];
        u[i].last_name=words[1];
        u[i].marks=words[2];
 }

    //Bubble sort structure
    users temp;
    for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < (count-1-i); j++)
            {
                if (stoi(u[j].marks) < stoi(u[j + 1].marks))
                {
                    temp = u[j];
                    u[j] = u[j + 1];
                    u[j + 1] = temp;
                }
            }
        }

    //Write to the TextEdit

string data;

for(int i=0;i<count;i++)
{
    data=to_string(i+1)+".\t\t\t"+u[i].first_name+"\t\t\t"+u[i].last_name+"\t\t\t"+u[i].marks+"\n\n\n";

    ui->textEdit_2->append(QString::fromStdString(data));
}

}

Leaderboard::~Leaderboard()
{
    delete ui;
}
