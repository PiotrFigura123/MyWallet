#include "FileWithOutcome.h"

vector <Outcome> FileWithOutcome::loadOutcomeOfUserFromFile(int LOGGED_USER_ID)
{

    Outcome outcome;
    vector <Outcome> outcomes;
    int outcomeId;
    int user;
    string outcomeDate;
    string outcomeComment;
    int outcomeValue;

    bool bSuccess = xml.Load( NAME_OF_FILE_WITH_OUTCOMES );
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("outcome"))
    {
        xml.IntoElem();
        xml.FindElem("OutcomeId");
        outcome.setOutcomeId(atoi(MCD_2PCSZ(xml.GetData())));
        lastOutcomeId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("userId");
        user = (atoi(MCD_2PCSZ(xml.GetData())));
        if(user==LOGGED_USER_ID)
        {
            outcome.setUserId(user);
            xml.FindElem( "outcomeDate" );
            outcome.setOutcomeDate(xml.GetData());
            xml.FindElem( "outcomeComment" );
            outcome.setOutcomeComment(xml.GetData());
            xml.FindElem( "outcomeValue" );
            sumOfOutcomes = sumOfOutcomes+atoi(MCD_2PCSZ(xml.GetData()));
            outcome.setOutcomevalue(stod(MCD_2PCSZ(xml.GetData())));

            xml.FindElem( "outcomeDateValue" );
            outcome.setOutcomeDateValue(atoi(MCD_2PCSZ(xml.GetData())));

            outcomes.push_back(outcome);
        }

        xml.OutOfElem();
    }

    return outcomes;
}



void FileWithOutcome::addOutcomeOfLoggedUser(Outcome outcome)
{
    bool bSuccess = xml.Load( NAME_OF_FILE_WITH_OUTCOMES );

    if(!bSuccess)
    {
        xml.AddElem( "outcomes" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "outcome" );
    xml.IntoElem();
    xml.AddElem( "OutcomeId",MetodyPomocnicze::konwerjsaIntNaString(outcome.getOutcomeId())) ;
    xml.AddElem( "userId", MetodyPomocnicze::konwerjsaIntNaString(outcome.getUserId()));
    xml.AddElem( "outcomeDate",outcome.getOutcomeDate());
    xml.AddElem( "outcomeComment", outcome.getOutcomeComment());
    xml.AddElem( "outcomeValue", MetodyPomocnicze::konwerjsaDoubleNaString(outcome.getOutcomeValue()));
    xml.AddElem( "outcomeDateValue", MetodyPomocnicze::konwerjsaIntNaString(outcome.getOutcomeDateValue()));
    xml.Save( "outcome.xml" );

}

int FileWithOutcome::getLastOutcomeId()
{
    return lastOutcomeId;
}

int FileWithOutcome::setNewLastOutcomeId()
{
    lastOutcomeId = getLastOutcomeId()+1;
    return  lastOutcomeId ;
}

int FileWithOutcome::getSumOfOutcomes()
{
    return sumOfOutcomes;
}
