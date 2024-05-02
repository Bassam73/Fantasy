#include "user.h"
#include "admin.h"
#include <MyProfileGui.h>
#include <QString>
#include <regex>

User::User(int i , string u , string p , string l)
{
    id = i;
    name = u ;
    password = p;
    league = l;
}
User::User(){}


bool User::registerUser(){
    const regex userPattern("^[A-Z][a-z]{2,}$");
    const regex passPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    if(!regex_match(name,userPattern))return false;
    bool nameCheck= checkUsername(name);
    bool passCheck = regex_match(password, passPattern);
    cout << passCheck;

    Admin registerAdmin;

    if  (nameCheck == false || passCheck==false) return false;

    User registeredUser(id ,name , password , league);
    registerAdmin.usersList.push_back(registeredUser);
    return true;
}




bool User::checkUsername(string username){
    cout <<"WeARE IN CHECK USER"<<endl;
    Admin mainAdmin ;

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
bool User::checkRegisteredUser(string name ,string password){
    Admin login;

    for(int i=0;i<login.usersList.size();i++){
        if(login.usersList[i].name==name&&
            login.usersList[i].password==password){
            currentUserData.id=login.usersList[i].id;
            currentUserData.name=login.usersList[i].name;
            currentUserData.password=login.usersList[i].password;
            currentUserData.league=login.usersList[i].league;
            qDebug()<<currentUserData.name;
            return true;
        }
    }
    return false;
}
int User::forgetPassword(string username,string newPassword,string reNewPassword){
    bool isFound=false;
    bool passCheck;
    int i;
    for(i=0;i<Admin::usersList.size();i++){
        if(Admin::usersList[i].name==username){
            isFound=true;
            break;
        }
    }
    if(!isFound){
        return 1;
    }
    else{
        const regex passPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
        passCheck = regex_match(newPassword, passPattern);
        if(!passCheck){
            return 2;
        }
    }
    if(reNewPassword!=newPassword){
        return 3;
    }
    Admin::usersList[i].password=newPassword;
    return 4;

}





