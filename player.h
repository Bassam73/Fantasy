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
    string nationality;
    int age;
    string position;
    int points;
    map<int,int>gwPoints;
    int id;
    string team;
    Player();
    Player(string);
    Player(int, int, int, string, string, string, string);
    Player(int, int, int, string, string, string, string,map<int,int>);

};

#endif // PLAYER_H
