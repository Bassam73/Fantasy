#include "player.h"
#include "admin.h"
Player::Player() {


}
Player::Player(string nam){
    name = nam;
}

Player::Player(int pId, int kit , int ag  , string nam  ,string pos, string te , float co){
    kitNumber = kit ;
    age = ag ;
    name = nam ;
    position = pos;
    team = te;
    id = pId;
    cost = co;
    points=0;
    for (int i = 1; i <19 ; ++i) {
        gwPoints[i]=0;
    }
}

Player::Player(int pId, int kit , int ag  , string nam ,  string pos, string te,map<int,int>gw , float co){
    kitNumber = kit ;
    age = ag ;
    name = nam ;
    position = pos;
    team = te;
    id = pId;
    points=0;
    gwPoints=gw;
    cost = co;
}
