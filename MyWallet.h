#ifndef MYWALLET_H
#define MYWALLET_H
#include <iostream>
#include "MetodyPomocnicze.h"
#include "UserMenager.h"
#include "IncomeMenager.h"

using namespace std;

class MyWallet
{
    UserMenager userMenager;
    IncomeMenager incomeMenager;
   // OutcomeMenager outcomeMenager;
    const string NAME_OF_FILE_WITH_INCOMES;
    //const string NAME_OF_FILE_WITH_OUTCOMES;

public:
    MyWallet(string nameOfFileWithUsers, string nameOfFileWithIncomes):
        userMenager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes)
    {
    };
    void userRegistration();
    void userLogin();
    void userLogout();
    void addIncomeOfLoggedUser();
    void dispiayAllUsers();
    };


#endif
