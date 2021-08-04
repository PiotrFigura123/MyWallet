#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>
#include "FileWithIncome.h"
#include "Income.h"
#include "UserMenager.h"
#include "MetodyPomocnicze.h"
#include "Markup.h"
using namespace std;
class IncomeMenager
{
        int ID_LOGGED_USER;
        vector <Income> incomes;
        FileWithIncome fileWithIncome;
        Income takeIncomeOfUser();
        int takeIdOfLastIncomeFromFile();
        bool checkDate(int year, int month, int day);
        string takeDateFromUser();
public:
    IncomeMenager()//string nameOfFileWithIncomes, int idOfLoggedUser ):fileWithIncome(nameOfFileWithIncomes),ID_LOGGED_USER(idOfLoggedUser)
    {
    cout<<"Jestem w income menager"<<endl;
    incomes = fileWithIncome.loadIncomeOfUserFromFile(ID_LOGGED_USER);
    };




    void addIncomeOfLoggedUser();

};


#endif
