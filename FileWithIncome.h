#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H
#include <iostream>
#include <vector>
#include "Income.h"
#include "Markup.h"
#include "MetodyPomocnicze.h"

class FileWithIncome
{
    CMarkup xml;
    const string NAME_OF_FILE_WITH_INCOMES;
    int sumOfIncomes;
    int lastIncomeId;
public:
    FileWithIncome(string nameOfFilesWithIncome):NAME_OF_FILE_WITH_INCOMES(nameOfFilesWithIncome)
     {
        lastIncomeId=0;
        sumOfIncomes=0;
        };
    vector <Income> loadIncomeOfUserFromFile(int LOGGED_USER_ID);
    void addIncomeOfLoggedUser(Income income);
    int getLastincomeId();
    int setNewLastincomeId();
};



#endif
