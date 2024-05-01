#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
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
    int id;
    string team;
    Player();
    Player(string);
    Player(int, int, int, string, string, string, string);

};

#endif // PLAYER_H
