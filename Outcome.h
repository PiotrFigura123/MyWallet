#ifndef OUTCOME_H
#define OUTCOME_H
#include <iostream>

using namespace std;

class Outcome
{
    int outcomeId;
    int userId;
    string outcomeDate;
    string outcomeComment;
    double outcomeValue;
    double outcomeDateValue;

public:
    int getOutcomeId();
    int getUserId();
    string getOutcomeDate();
    string getOutcomeComment();
    double getOutcomeValue();
    double getOutcomeDateValue();

    void setOutcomeId(int newOutcomeId);
    void setUserId(int newUserId);
    void setOutcomeDate(string newOutcomeDate);
    void setOutcomeComment(string newOutcomeComment);
    void setOutcomevalue(double newOutcomeValue);
    void setOutcomeDateValue(double newOutcomeDateValue);

    bool operator<(Outcome& p){return outcomeDateValue <p.outcomeDateValue;}
};

#endif

