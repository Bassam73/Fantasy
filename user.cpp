#include "user.h"

User::User(vector<User> & usersList) {
    list = usersList;
}




bool User::registerUser(string name , string password , string league){
    bool check= userNameCheck(name);

    if  (check == false) return false;
    int id = 1+ (rand() % 1000);

    cout<<id;



}




bool User::userNameCheck(const string& username) {
    if (list.empty()) {
        return true;
    }
    for(int i = 0 ; i < list.size();i++){
        if(list[i].name == username){
            return false;
        }
    }

    return true;
}
