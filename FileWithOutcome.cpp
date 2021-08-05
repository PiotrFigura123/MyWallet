#include "FileWithOutcome.h"

vector <Outcome> FileWithOutcome::loadOutcomeOfUserFromFile(int LOGGED_USER_ID)
{
    //cout<<"LOGGED_USER_ID = "<<LOGGED_USER_ID<<endl;
    Outcome outcome;
    vector <Outcome> outcomes;
    int outcomeId;
    int user;
    string outcomeDate;
    string outomeComment;
    int outcomeValue;

    bool bSuccess = xml.Load( "outcome.xml" );
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("outcome"))
    {
        xml.IntoElem();
        xml.FindElem("OutcomeId");
        outcome.setOutcomeId(atoi(MCD_2PCSZ(xml.GetData())));
        //cout<<"lastIncomeId = "<<atoi(MCD_2PCSZ(xml.GetData()))<<endl;
        lastOutcomeId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("userId");
        user = (atoi(MCD_2PCSZ(xml.GetData())));
        //cout<<"User = "<<user<<endl;
        if(user==LOGGED_USER_ID)
        {
            outcome.setUserId(user);
            xml.FindElem( "outcomeDate" );
            outcome.setOutcomeDate(xml.GetData());
            xml.FindElem( "outcomeComment" );
            outcome.setOutcomeComment(xml.GetData());
            xml.FindElem( "outcomeValue" );
            outcome.setOutcomevalue(atoi(MCD_2PCSZ(xml.GetData())));

            outcomes.push_back(outcome);
        }

        xml.OutOfElem();
    }
    cout<<"lastOutcome = "<<lastOutcomeId<<endl;
    return outcomes;
}


void FileWithOutcome::addOutcomeOfLoggedUser(Outcome outcome)
{
    bool bSuccess = xml.Load( "outcome.xml" );

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
    xml.AddElem( "outcomeValue", MetodyPomocnicze::konwerjsaIntNaString(outcome.getOutcomeValue()));
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

