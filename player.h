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
    double cost;
    string team;
    Player();
    Player(string);
    Player(int, int, int,  string, string, string ,double,int point);
    Player(int, int, int, string, string, string,map<int,int> , double,int point);

};

#endif // PLAYER_H
