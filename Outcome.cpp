#include "Outcome.h"

int Outcome::getOutcomeId()
{
    return outcomeId;
}

int Outcome::getUserId()
{
    return userId;
}
string Outcome::getOutcomeDate()
{
    return outcomeDate;
}
string Outcome::getOutcomeComment()
{
    return outcomeComment;
}
int Outcome::getOutcomeValue()
{
    return outcomeValue;
}

double Outcome::getOutcomeDateValue()
{
    return outcomeDateValue;
}

void Outcome::setOutcomeId(int newOutcomeId)
{
    outcomeId = newOutcomeId;
}
void Outcome::setOutcomeDate(string newOutcomeDate)
{
    outcomeDate = newOutcomeDate;
}
void Outcome::setOutcomeComment(string newOutcomeComment)
{
    outcomeComment = newOutcomeComment;
}
void Outcome::setOutcomevalue(int newOutcomeValue)
{
    outcomeValue = newOutcomeValue;
}

void Outcome::setUserId(int newUserId)
{
    userId = newUserId;
}
void Outcome::setOutcomeDateValue(double newOutcomeDateValue)
{
    outcomeDateValue = newOutcomeDateValue;
}
