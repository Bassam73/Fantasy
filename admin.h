#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <vector>
#include "user.h"
#include "team.h"
using namespace std;
class Admin
{
public:
    static vector<User> usersList;

    static vector<Team> plTeamsList;

    static vector<Team> ligaTeamsList;


    Admin();
   bool addTeams(string,string);
};




#endif // ADMIN_H
