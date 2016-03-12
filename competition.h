//
// Created by Qun on 2016/3/12.
//

#ifndef LAB2_COMPETITION_H
#define LAB2_COMPETITION_H

#include <string>
using namespace std;

static const int max_length=10;

class Team {
private:
    string name;
    int total_win;
    int total_loss;
    int score_for;
    int score_against;
public:

    Team();

    const string &getName();
    int getTotal_win();
    int getTotal_loss();
    int getScore_for();
    int getScore_against();

    void setName(const string &name);
    void setTotal_win(int total_win);
    void setTotal_loss(int total_loss);
    void setScore_for(int score_for);
    void setScore_against(int score_against);
};


class Result{
private:
    Team teams[max_length];
    int count;
public:
    Result();
    void load(string file_name);
    void sort();
    void print();
};
#endif //LAB2_COMPETITION_H
