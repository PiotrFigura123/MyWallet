#include "OutcomeMenager.h"

void OutcomeMenager::addOutcomeOfLoggedUser(int userId)
{
    Outcome outcome;
    outcome = takeOutcomeOfUser(userId);
    outcomes.push_back(outcome);
    fileWithOutcome.addOutcomeOfLoggedUser(outcome);
}

Outcome OutcomeMenager::takeOutcomeOfUser(int userId)
{
    char chooseDate;
    system("CLS");
    cout<<"Outcome registration: "<<endl;
    Outcome outcome;
    int outcomeId;
    double outcomeValue;
    string outcomeDate, outcomeComment;
    double outcomeDateValue;

    outcomeId = fileWithOutcome.setNewLastOutcomeId();

    cout<<"Current date? [y/n] : ";
    cin>>chooseDate;
    if(chooseDate=='n')
    outcomeDate = MetodyPomocnicze::takeDateFromUser();
    else
    outcomeDate = MetodyPomocnicze::setCurrentDate();

    outcomeDateValue = MetodyPomocnicze::convertDateIntoValue(outcomeDate);
    cout<<endl<<"Date: "<<outcomeDate<<endl;
    cout<<"Outcome comment: ";
    cin>>outcomeComment;
    cout<<"Outcome value: ";
    outcomeValue = MetodyPomocnicze::takeValueFromUser();


    outcome.setOutcomeId(outcomeId);
    outcome.setUserId(userId);
    outcome.setOutcomeDate(outcomeDate);
    outcome.setOutcomeComment(outcomeComment);
    outcome.setOutcomevalue(outcomeValue);
    outcome.setOutcomeDateValue(outcomeDateValue);
    return outcome;
}

void OutcomeMenager::displayAllOutcomes()
{
    for (int i=0; i<outcomes.size(); i++)
    {

        cout<<"OutomeId: "<< outcomes[i].getOutcomeId()<<endl;
        cout<<"userId: "<<outcomes[i].getUserId()<<endl;
        cout<<"data: "<<outcomes[i].getOutcomeDate()<<endl;
        cout<<"wartosc: "<<outcomes[i].getOutcomeValue()<<endl;
        cout<<"Comment: "<<outcomes[i].getOutcomeComment()<<endl<<endl;

    }
    system("pause");
}

void OutcomeMenager::displayCurrentMonthOutcomesInOrder()
{
    string currentMonth;
    string outcomeMonth;
    double sumOfOutcomes=0;
    currentMonth = (MetodyPomocnicze::setCurrentDate()).substr(0,7);
    sort(outcomes.begin(),outcomes.end());
    system("CLS");
    cout<<" -------OUTCOMES------"<<endl;
    for (int i=0; i<outcomes.size(); i++)
    {
        outcomeMonth = (outcomes[i].getOutcomeDate()).substr(0,7);

        if( currentMonth == outcomeMonth)
        {
        cout<<"data: "<<outcomes[i].getOutcomeDate()<<endl;
        cout<<"Comment: "<<outcomes[i].getOutcomeComment()<<endl;
        sumOfOutcomes = sumOfOutcomes+outcomes[i].getOutcomeValue();
        cout<<"wartosc: "<<outcomes[i].getOutcomeValue()<<endl<<endl;
        }


    }
    cout<<"Sum of outcomes = "<<sumOfOutcomes<<endl;
    system("pause");
}

void OutcomeMenager::displayLastMonthOutcomes()
{
    sort(outcomes.begin(),outcomes.end());
    string lastMonthDate,outcomeDate, syear,smonth;
    int month;
    double sumOfOutcomes=0;
    syear = (MetodyPomocnicze::setCurrentDate()).substr(0,4);
    smonth = (MetodyPomocnicze::setCurrentDate()).substr(5,2);
    month = MetodyPomocnicze::konwersjaStringNaInt(smonth)-1;
    smonth =MetodyPomocnicze::konwerjsaIntNaString(month);
    if(smonth.length()==1)
        smonth = "0"+smonth;
    lastMonthDate= syear+"-"+smonth;
    system("CLS");
    cout<<" -------OUTCOMES------"<<endl;
    for (int i=0; i<outcomes.size(); i++)
    {
        outcomeDate = (outcomes[i].getOutcomeDate()).substr(0,7);
      if( outcomeDate == lastMonthDate)
        {
            cout<<"data: "<<outcomes[i].getOutcomeDate()<<endl;
            cout<<"Comment: "<<outcomes[i].getOutcomeComment()<<endl;
            sumOfOutcomes = sumOfOutcomes+outcomes[i].getOutcomeValue();
            cout<<"wartosc: "<<outcomes[i].getOutcomeValue()<<endl<<endl;
        }
    }
    cout<<"Sum of outcomes = "<<sumOfOutcomes<<endl;

    system("pause");
}

void OutcomeMenager::choosenPeriodOutcomes()
{
    string startDate,endDate,incomeDate;
    cout<<"Start date, ";
    startDate = MetodyPomocnicze::takeDateFromUser();
    cout<<"End date, ";
    endDate = MetodyPomocnicze::takeDateFromUser();

    while((MetodyPomocnicze::convertDateIntoValue(startDate)>MetodyPomocnicze::convertDateIntoValue(endDate)))
    {
        cout<<"Start date should be before end date!!"<<endl;
        cout<<"Start date, ";
        startDate = MetodyPomocnicze::takeDateFromUser();
        cout<<"End date, ";
        endDate = MetodyPomocnicze::takeDateFromUser();
    }

    cout<<"Display all incomes from "<<startDate<<" till "<<endDate<<endl;

    displayOutcomesInChoosenPeriod(startDate,endDate);

}

void OutcomeMenager::displayOutcomesInChoosenPeriod(string startDate, string endDate)
{
    sort(outcomes.begin(),outcomes.end());
    int startDateValue, endDateValue, outcomeDateValue;
    double sumOfOutcomes=0;

    startDateValue = MetodyPomocnicze::convertDateIntoValue(startDate);
    endDateValue = MetodyPomocnicze::convertDateIntoValue(endDate);
    system("CLS");
    cout<<" -------OUTCOMES------"<<endl;
    for (int i=0; i<outcomes.size(); i++)
    {
        outcomeDateValue = outcomes[i].getOutcomeDateValue();
        if( outcomeDateValue>=startDateValue && outcomeDateValue<=endDateValue)
        {
            cout<<"data: "<<outcomes[i].getOutcomeDate()<<endl;
            cout<<"Comment: "<<outcomes[i].getOutcomeComment()<<endl;
            sumOfOutcomes = sumOfOutcomes+outcomes[i].getOutcomeValue();
            cout<<"wartosc: "<<outcomes[i].getOutcomeValue()<<endl<<endl;
        }
    }
    cout<<"Sum of outcomes = "<<sumOfOutcomes<<endl;
system("pause");

}

