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
public:
    FileWithIncome(){
        };
    vector <Income> loadIncomeOfUserFromFile(int ID_LOGGED_USER);
    void addIncomeOfLoggedUser(Income income);
};



#endif
