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
using namespace std;

class IncomeMenager
{
        const int LOGGED_USER_ID;
        vector <Income> incomes;
        FileWithIncome fileWithIncome;
        Income takeIncomeOfUser(int userId);
        int takeIdOfLastIncomeFromFile();
        bool checkDate(int year, int month, int day);
        void displayIncomesInChoosenPeriod(string startDate,string endDate);


public:
    IncomeMenager(string nameOfFileWithIncomes, int idOfLoggedUser):
    fileWithIncome(nameOfFileWithIncomes), LOGGED_USER_ID(idOfLoggedUser)
    {

    incomes = fileWithIncome.loadIncomeOfUserFromFile(LOGGED_USER_ID);

    };
    void addIncomeOfLoggedUser(int userId);
    void displayAllIncomesInOrder();
    void displayCurrentMonthIncomesInOrder();
    void displayLastMonthIncomes();
    void choosenPeriodIncomes();
};



#endif
