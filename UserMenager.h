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
#include "IncomeMenager.h"
#include "FileWithIncome.h"
#include "OutcomeMenager.h"

using namespace std;
class UserMenager
{
    int idOfLoggedUser;
    vector <User> users;
    FileWithUsers fileWithUsers;
    User takeDataOfNewUser();
    int loadIdOfLastUser();

public:
    UserMenager(string nameOfFileWithUsers): fileWithUsers(nameOfFileWithUsers)
    {
    idOfLoggedUser =0;
    users = fileWithUsers.readUserFromFile(nameOfFileWithUsers);

    };

    void displauAllUsers();
    void userRegistration();
    void userLogin();
    void userLogout();
    void addIncomeOfLoggedUser();
    int getIdOfLoggedUser();


};

#endif
