#ifndef FILEWITHBALANCE_H
#define FILEWITHBALANCE_H
#include <iostream>

using namespace std;

class FileWithBalance
{
    public:
    string startDate;
    string endDate;
    double incomeBalance;
    double outcomeBalance;

    void setStartDate(string date);
    void setEndDate(string date);
    void settIncomeBalance(double sumOgincomes);
    void setOutcomeBalance(double sumOfOutcomes);

    string getStartDate();
    string getEndDate();
    double getIncomeBalance();
    double getoutcomeBalance();
};

#endif
