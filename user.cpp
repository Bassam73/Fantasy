#include "user.h"
#include "admin.h"

#include <regex>

User::User(string u , string p , string l)
{
    name = u ;
    password =p ;
    league = l;
}



bool User::registerUser(){
    const regex userPattern("^[A-Z][a-z]{2,}$");
    const regex passPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    if(!regex_match(name,userPattern))return false;
    bool nameCheck= checkUsername(name);
    bool passCheck = regex_match(password, passPattern);
    cout << passCheck;

    Admin registerAdmin;

    if  (nameCheck == false || passCheck==false) return false;
    // int id = 1+ (rand() % 1000);
    cout <<league;
    User registeredUser(name , password , league);
      registerAdmin.usersList.push_back(registeredUser);
    return true;
};




bool User::checkUsername(string username){
    cout <<"WeARE IN CHECK USER"<<endl;
    Admin mainAdmin ;
    cout<<mainAdmin.usersList.size()<<"Size"<<endl;
    if (mainAdmin.usersList.empty()) {
        return true;
    }
    for(int i = 0 ; i < mainAdmin.usersList.size();i++){
        if(mainAdmin.usersList[i].name == username){
            return false;
        }
    }

    return true;
}







