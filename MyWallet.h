#ifndef MYWALLET_H
#define MYWALLET_H
#include <iostream>
#include "MetodyPomocnicze.h"
#include "UserMenager.h"
#include "IncomeMenager.h"
#include "OutcomeMenager.h"

using namespace std;

class MyWallet
{
    UserMenager userMenager;
    IncomeMenager *incomeMenager;
    OutcomeMenager *outcomeMenager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_OUTCOMES;

public:
    MyWallet(string nameOfFileWithUsers, string nameOfFileWithIncomes,string nameOfFileWithOutcomes ):
        userMenager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes),NAME_OF_FILE_WITH_OUTCOMES(nameOfFileWithOutcomes)
    {
        outcomeMenager =NULL;
        incomeMenager = NULL;
    };
    ~MyWallet()
    {
        delete incomeMenager;
        delete outcomeMenager;
        incomeMenager = NULL;
        outcomeMenager =NULL;
    };
    void userRegistration();
    void userLogin();
    void userLogout();
    void addIncomeOfLoggedUser();
    void addOutcomeOfLoggedUser();
    void dispiayAllUsers();
    void displayAllIncomes();
    void currentMonthBalance();
};




#endif
