#include "player.h"
#include "admin.h"
Player::Player() {


}
Player::Player(string nam){
    name = nam;
}

Player::Player(int pId, int kit , int ag  , string nam ,  string nation ,string pos, string te){
    kitNumber = kit ;
    age = ag ;
    name = nam ;
    nationality = nation ;
    position = pos;
    team = te;
    id = pId;
    points=0;
}

