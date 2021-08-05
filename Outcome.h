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
    int outcomeValue;

public:
    int getOutcomeId();
    int getUserId();
    string getOutcomeDate();
    string getOutcomeComment();
    int getOutcomeValue();

    void setOutcomeId(int newOutcomeId);
    void setUserId(int newUserId);
    void setOutcomeDate(string newOutcomeDate);
    void setOutcomeComment(string newOutcomeComment);
    void setOutcomevalue(int newOutcomeValue);

};

#endif

