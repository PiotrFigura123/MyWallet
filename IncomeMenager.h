#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <string>
#include "FileWithIncome.h"
#include "Income.h"
#include "UserMenager.h"
#include "MetodyPomocnicze.h"
#include "Markup.h"
#include "FileWithBalance.h"
using namespace std;

class IncomeMenager
{
        const int LOGGED_USER_ID;
        vector <Income> incomes;
        FileWithIncome fileWithIncome;
        FileWithBalance fileWithBalance;
        Income takeIncomeOfUser(int userId);
        int takeIdOfLastIncomeFromFile();
        void displayIncomesInChoosenPeriod(string startDate,string endDate);
        string startDate;
        double sumOfIncomes;

public:
    IncomeMenager(string nameOfFileWithIncomes, int idOfLoggedUser):
    fileWithIncome(nameOfFileWithIncomes), LOGGED_USER_ID(idOfLoggedUser)
    {

    incomes = fileWithIncome.loadIncomeOfUserFromFile(LOGGED_USER_ID);

    };
    void addIncomeOfLoggedUser(int userId);
    void displayCurrentMonthIncomesInOrder();
    void displayLastMonthIncomes();
    void choosenPeriodIncomes(string startDate, string endDate);
    double getSumOfIncomes();
};



#endif
