#ifndef MYWALLET_H
#define MYWALLET_H
#include <iostream>
#include "MetodyPomocnicze.h"
#include "UserMenager.h"


using namespace std;

class MyWallet
{
    UserMenager userMenager;

public:
    MyWallet(string nameOfFileWithUsers): userMenager(nameOfFileWithUsers){
    };
    void userRegistration();
    void userLogin();
    void userLogout();
    void addIncome();
};

#endif
