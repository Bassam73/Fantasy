#include "player.h"
#include "admin.h"
Player::Player() {


}
Player::Player(string nam){
    name = nam;
}

Player::Player(int pId, int kit , int ag  , string nam  ,string pos, string te , double co,int point,int go,int as , int cs , int yc){
    kitNumber = kit ;
    age = ag ;
    name = nam ;
    position = pos;
    team = te;
    id = pId;
    cost = co;
    points=point;
    for (int i = 1; i <19 ; ++i) {
        gwPoints[i]=0;
    }
    goals = go;
    assists = as;
    cleanSheets = cs;
    yellowCards = yc;
}

Player::Player(int pId, int kit , int ag  , string nam ,  string pos, string te,map<int,int>gw , double co,int point  ,int go,int as , int cs , int yc)
{
    kitNumber = kit ;
    age = ag ;
    name = nam ;
    position = pos;
    team = te;
    id = pId;
    points=point;
    gwPoints=gw;
    cost = co;
    goals = go;
    assists = as;
    cleanSheets = cs;
    yellowCards = yc;

}
//Player player1(id , kit, age, name, pos, te,gw,co,points , goals , assists , cleanSheets , yellowCards);
