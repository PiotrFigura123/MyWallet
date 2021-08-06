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
    int outcomeId, outcomeValue;
    string outcomeDate, outcomeComment;
    double outcomeDateValue;

    outcomeId = fileWithOutcome.setNewLastOutcomeId();

    cout<<"Current date? [y/n] : ";
    cin>>chooseDate;
    if(chooseDate=='n')
    outcomeDate = takeDateFromUser();
    else
    outcomeDate = setCurrentDate();

    outcomeDateValue = MetodyPomocnicze::convertDateIntoValue(outcomeDate);
    cout<<endl<<"Date: "<<outcomeDate<<endl;
    cout<<"Outcome comment: ";
    cin>>outcomeComment;
    cout<<"Outcome value: ";
    cin>>outcomeValue;


    outcome.setOutcomeId(outcomeId);
    outcome.setUserId(userId);
    outcome.setOutcomeDate(outcomeDate);
    outcome.setOutcomeComment(outcomeComment);
    outcome.setOutcomevalue(outcomeValue);
    outcome.setOutcomeDateValue(outcomeDateValue);
    return outcome;
}

/*int outcomeMenager::takeIdOfLastoutcomeFromFile()

{
    if (outcomes.empty() == true)
        return 1;
    else
        return outcomes.back().getIncomeId() + 1;
}*/

bool OutcomeMenager::checkDate(int year, int month, int day)
{
    cout<<"yeas: "<<year<< " month: "<<month<<" day: "<<day<<endl;
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||(month == 8) || (month == 10) || (month == 12))
    {
        if(day <= 31)
        {
            return true;
        }
        else
            cout<<"Outcorrect date, please provide new one"<<endl;
        return false;
    }
    else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
    {
        if(day <= 30)
        {
            return true;
        }
        else
            cout<<"Incorrect date, please provide new one"<<endl;
        return false;
    }
    else if ((month == 2) && (year % 4 == 0))
    {
        if(day <= 29)
        {
            return true;
        }
        else
            cout<<"Incorrect date, please provide new one"<<endl;
        return false;
    }
    else if ((month == 2) && (year % 4 != 0))
    {
        if(day <= 28)
        {
            return true;
        }
        else
            cout<<"Incorrect date, please provide new one"<<endl;
        return false;
    }
    else
        cout<<"Incorrect date, please provide new one"<<endl;
    return false;
}

string OutcomeMenager::takeDateFromUser()
{
    int year=0,month=0,day=0;
    string date;
    do
    {
        cout<<" Year(after 2000): ";
        cin>>year;
        while(year<2000)
        {
            cout<<"Incorrect year, put new please: ";
            cin>>year;
        }

        cout<<"Month: ";
        cin>>month;
        while( 1>month || month>12)
        {
            cout<<"Incorrect month, put new please: ";
            cin>>month;
        }
        cout<<"Day: ";
        cin>>day;

    }
    while(!checkDate(year,month,day));

    string syear = MetodyPomocnicze::konwerjsaIntNaString(year);
    string smonth = MetodyPomocnicze::konwerjsaIntNaString(month);
    string sday = MetodyPomocnicze::konwerjsaIntNaString(day);
    if(smonth.length()==1)
        smonth = "0"+smonth;
    if(sday.length()==1)
        sday="0"+sday;
    date = syear+"-"+smonth+"-"+sday;
    return date;
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

string OutcomeMenager::setCurrentDate()
{
    int year, month, day;
    string currentDay, syear,smonth,sday;
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);
    year = nowLocal.tm_year+1900;
    month = nowLocal.tm_mon+1;
    day = nowLocal.tm_mday;
    //cout<<MetodyPomocnicze::checkDate(rok,miesiac, dzien);
    syear =  MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_year+1900);
    smonth = MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_mon+1);
    sday = MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_mday);
    if(smonth.length()==1)
        smonth="0"+smonth;
    if(sday.length()==1)
        sday="0"+sday;
    currentDay = syear+"-"+smonth+"-"+sday;
    //cout<<currentDay<<endl;
    return currentDay;

}
