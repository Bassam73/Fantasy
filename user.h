#ifndef USER_H
#define USER_H


#include <iostream>
using namespace std;
class User
{
public:
    int id;
    string name ;
    string password;
    string league;
    User(string , string , string );
    User();
    bool registerUser();
    bool checkUsername(string );
    bool isValidPassword(string);
    bool checkRegisteredUser(string, string);

};


#endif // USER_H
