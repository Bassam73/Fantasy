#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <vector>
#include "user.h"
using namespace std;

class Admin
{
public:
    vector<User> usersList ;
    Admin();
};

#endif // ADMIN_H
