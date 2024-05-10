#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <map>

using namespace std;
class Player
{
public:

    string name;
    int kitNumber;
    int age;
    string position;
    int points;
    map<int,int>gwPoints;
    int id;

    int goals;
    int assists;
    int cleanSheets;
    int yellowCards;

    double cost;
    string team;
    Player();
    Player(string);
    Player(int, int, int,  string, string, string ,double,int point , int , int , int ,int);
    Player(int, int, int, string, string, string,map<int,int> , double,int point , int , int , int ,int);

};

#endif // PLAYER_H
