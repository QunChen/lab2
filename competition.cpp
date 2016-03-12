//
// Created by Qun on 2016/3/12.
//
#include "competition.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

Team::Team() {
    name="";
    total_win=0;
    total_loss=0;
    score_for=0;
    score_against=0;
}

const string &Team::getName()  {
    return name;
}

int Team::getTotal_win()  {
    return total_win;
}

int Team::getTotal_loss()  {
    return total_loss;
}

int Team::getScore_for()  {
    return score_for;
}

int Team::getScore_against()  {
    return score_against;
}

void Team::setName(const string &name) {
    this->name = name;
}

void Team::setTotal_win(int total_win) {
    this->total_win = total_win;
}

void Team::setTotal_loss(int total_loss) {
    this->total_loss = total_loss;
}

void Team::setScore_for(int score_for) {
    this->score_for = score_for;
}

void Team::setScore_against(int score_against) {
    this->score_against = score_against;
}

Result::Result() {
    count=0;
}

void Result::load(string file_name) {
    ifstream file(file_name);
    if(file.is_open()){
        string line1,line2;
        while(getline(file,line1)){
            getline(file,line2);
           stringstream s1(line1);
            stringstream s2(line2);
            string name1,name2;
            getline(s1,name1,':');
            getline(s1,name2,'\n');
            string score1_string,score2_string;
            getline(s2,score1_string,':');
            getline(s2,score2_string,'\n');

            int score1=atoi(score1_string.c_str());
            int score2=atoi(score2_string.c_str());


            bool is_found1=false,is_found2= false;
            for(int i=0;i<max_length;i++){
                if(teams[i].getName().compare(name1)==0){
                    is_found1= true;

                    if(score1>score2){
                        teams[i].setTotal_win(teams[i].getTotal_win()+1);
                    }else{
                        teams[i].setTotal_loss(teams[i].getTotal_loss()+1);
                    }

                    teams[i].setScore_for(teams[i].getScore_for()+score1);
                    teams[i].setScore_against(teams[i].getScore_against()+score2);
                    continue;
                }
                if(teams[i].getName().compare(name2)==0){
                    is_found2= true;

                    if(score2>score1){
                        teams[i].setTotal_win(teams[i].getTotal_win()+1);
                    }else{
                        teams[i].setTotal_loss(teams[i].getTotal_loss()+1);
                    }

                    teams[i].setScore_for(teams[i].getScore_for()+score2);
                    teams[i].setScore_against(teams[i].getScore_against()+score1);
                }
            }

            if(!is_found1){
                Team team;
                team.setName(name1);
                team.setScore_for(score1);
                team.setScore_against(score2);
                if(score1>score2){
                    team.setTotal_win(1);
                }else{
                    team.setTotal_loss(1);
                }

                teams[count]=team;
                count++;
            }

            if(!is_found2){
                Team team;
                team.setName(name2);
                team.setScore_for(score2);
                team.setScore_against(score1);
                if(score2>score1){
                    team.setTotal_win(1);
                }else{
                    team.setTotal_loss(1);
                }

                teams[count]=team;
                count++;
            }
        }

    }else{
        cout<<"can not open"<<endl;
    }
}

bool compare(Team team1,Team team2){
    if(team1.getTotal_win()>team2.getTotal_win()){
        return true;
    }else if(team1.getTotal_win()<team2.getTotal_win()){
        return false;
    }
    else{
        if(team1.getTotal_loss()<team2.getTotal_loss()){
            return true;
        }else if(team1.getTotal_loss()>team2.getTotal_loss()){
            return false;
        }
        else{
            if((team1.getScore_for()-team1.getScore_against())>(team2.getScore_for()-team2.getScore_against())){
                return true;
            }else if((team1.getScore_for()-team1.getScore_against())<(team2.getScore_for()-team2.getScore_against())){
                return false;
            }
        }
    }
}


void Result::sort() {
    vector<Team> team_vector;
    for (int i = 0; i < count; i++) {
        team_vector.push_back(teams[i]);
    }

    std::sort(team_vector.begin(), team_vector.end(),compare);

    int i = 0;

    for (Team team : team_vector) {
        teams[i] = team;
        i++;
    }
}


void Result::print() {
    for(int i=0;i<count;i++){
        Team team=teams[i];
        cout<<setw(20)<<team.getName()<<setw(20)<<team.getTotal_win()<<setw(20)<<team.getTotal_loss()<<setw(20)<<team.getScore_for()<<setw(20)<<team.getScore_against()<<endl;
    }
}