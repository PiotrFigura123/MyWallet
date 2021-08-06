#include "Income.h"

int Income::getIncomeId()
{
    return incomeId;
}

int Income::getUserId()
{
    return userId;
}
string Income::getIncomeDate()
{
    return incomeDate;
}
string Income::getIncomeComment()
{
    return incomeComment;
}
int Income::getIncomeValue()
{
    return incomeValue;
}
double Income::getIncomeDateValue()
{
    return incomeDateValue;
}

void Income::setIncomeId(int newIncomeId)
{
    incomeId = newIncomeId;
}
void Income::setIncomeDate(string newIncomeDate)
{
    incomeDate = newIncomeDate;
}
void Income::setIncomeComment(string newIncomeComment)
{
    incomeComment = newIncomeComment;
}
void Income::setIncomevalue(int newIncomeValue)
{
    incomeValue = newIncomeValue;
}

void Income::setUserId(int newUserId)
{
    userId = newUserId;
}

void Income::setIncomeDateValue(double newIncomeDateValue)
{
    incomeDateValue = newIncomeDateValue;
}
