#ifndef INCOME_H
#define INCOME_H
#include <iostream>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    string incomeDate;
    string incomeComment;
    int incomeValue;

public:
    int getIncomeId();
    int getUserId();
    string getIncomeDate();
    string getIncomeComment();
    int getIncomeValue();

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setIncomeDate(string newIncomeDate);
    void setIncomeComment(string newIncomeComment);
    void setIncomevalue(int newIncomeValue);

};

#endif

