#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>
#include "MetodyPomocnicze.h"
#include "Users.h"
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>
#include "FileWithUsers.h"

using namespace std;
class UserMenager
{
    vector <User> users;
    FileWithUsers fileWithUsers;
    int loadIdOfLastUser();
    int idOfLoggedUser;
    User takeDataOfNewUser();

public:
    UserMenager(string nameOfFileWithUsers): fileWithUsers(nameOfFileWithUsers){
    idOfLoggedUser =0;
    users = fileWithUsers.readUserFromFile();
    };
    void userRegistration();
    void userLogin();
    void userLogout();
    void addIncome();

};

#endif
