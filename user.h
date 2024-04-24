#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std ;
#include <vector>


class User
{
public:
    int id;
    string name ;
    string league ;
    string password;
    User(vector<User> & usersList);
    User(string name , string league , string password, int id);
    User();
    int points;
    bool registerUser(string name , string password , string league);
    bool userNameCheck(const string& username);
    vector<User> list;


};

#endif // USER_H
