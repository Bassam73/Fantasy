#ifndef USER_H
#define USER_H

#include <QString>
#include <iostream>
using namespace std;
class User
{
public:
    int id;
    string name ;
    string password;
    string league;
    User(int , string , string , string );
    User();
    bool registerUser();
    bool checkUsername(string );
    bool isValidPassword(string);
    bool checkRegisteredUser(string, string);

};


#endif // USER_H
