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
    float cost;
    string team;
    Player();
    Player(string);
    Player(int, int, int,  string, string, string ,float);
    Player(int, int, int, string, string, string,map<int,int> , float);

};

#endif // PLAYER_H
