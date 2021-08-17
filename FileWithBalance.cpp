#include "FileWithBalance.h"

void FileWithBalance::setStartDate(string date)
{
    startDate = date;
}
void FileWithBalance::setEndDate(string date)
{
    endDate = date;
}
void FileWithBalance::settIncomeBalance(double sumOfIncomes)
{
    incomeBalance = sumOfIncomes;
}
void FileWithBalance::setOutcomeBalance(double sumOfOutcomes)
{
    outcomeBalance = sumOfOutcomes;
}
string FileWithBalance::getStartDate()
{
    return startDate;
}
string FileWithBalance::getEndDate()
{
    return endDate;
}
double FileWithBalance::getIncomeBalance()
{
    return incomeBalance;
}
double FileWithBalance::getoutcomeBalance()
{
    return outcomeBalance;
}

