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
        const int LOGGED_USER_ID;
        vector <Income> incomes;
        FileWithIncome fileWithIncome;
        Income takeIncomeOfUser(int userId);
        int takeIdOfLastIncomeFromFile();
        bool checkDate(int year, int month, int day);
        string takeDateFromUser();
        string setCurrentDate();
        int convertDateIntoInt(string date);

public:
    IncomeMenager(string nameOfFileWithIncomes, int idOfLoggedUser):
    fileWithIncome(nameOfFileWithIncomes), LOGGED_USER_ID(idOfLoggedUser)
    {

    incomes = fileWithIncome.loadIncomeOfUserFromFile(LOGGED_USER_ID);
    //cout<<"Jestem w konstruktorze. Incomes size = "<<endl;
    };
    void addIncomeOfLoggedUser(int userId);
    void displayAllIncomes();
    void displayAllIncomesInOrder();
};


#endif
