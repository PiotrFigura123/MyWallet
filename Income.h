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
    double incomeValue;
    double incomeDateValue;

public:
    int getIncomeId();
    int getUserId();
    string getIncomeDate();
    string getIncomeComment();
    double getIncomeValue();
    double getIncomeDateValue();

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setIncomeDate(string newIncomeDate);
    void setIncomeComment(string newIncomeComment);
    void setIncomevalue(double newIncomeValue);
    void setIncomeDateValue(double newIncomeDateValue);

    bool operator<(Income& p){return incomeDateValue <p.incomeDateValue;}
};


#endif

