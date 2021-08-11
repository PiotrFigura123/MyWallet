#include "IncomeMenager.h"

void IncomeMenager::addIncomeOfLoggedUser(int userId)
{
    Income income;
    income = takeIncomeOfUser(userId);
    incomes.push_back(income);
    fileWithIncome.addIncomeOfLoggedUser(income);
}

Income IncomeMenager::takeIncomeOfUser(int userId)
{
    char chooseDate;
    system("CLS");
    cout<<"Income registration: "<<endl;
    Income income;
    int incomeId, incomeValue ;
    string incomeDate, incomeComment;
    double incomeDateValue;
    incomeId = fileWithIncome.setNewLastincomeId();

    cout<<"Current date? [y/n] : ";
    cin>>chooseDate;
    if(chooseDate=='n')
        incomeDate = takeDateFromUser();
    else
        incomeDate = setCurrentDate();

    incomeDateValue = MetodyPomocnicze::convertDateIntoValue(incomeDate);
    cout<<endl<<"Date: "<<incomeDate<<endl;
    cout<<"Income comment: ";
    cin>>incomeComment;
    cout<<"Income value: ";
    cin>>incomeValue;


    income.setIncomeId(incomeId);
    income.setUserId(userId);
    income.setIncomeDate(incomeDate);
    income.setIncomeComment(incomeComment);
    income.setIncomevalue(incomeValue);
    income.setIncomeDateValue(incomeDateValue);
    return income;
}

bool IncomeMenager::checkDate(int year, int month, int day)
{
    cout<<"yeas: "<<year<< " month: "<<month<<" day: "<<day<<endl;
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||(month == 8) || (month == 10) || (month == 12))
    {
        if(day <= 31)
        {
            return true;
        }
        else
            cout<<"Incorrect date, please provide new one"<<endl;
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

string IncomeMenager::takeDateFromUser()
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


void IncomeMenager::displayAllIncomesInOrder()
{
    for (int i=0; i<incomes.size(); i++)
    {

        cout<<"InomeId: "<< incomes[i].getIncomeId()<<endl;
        cout<<"userId: "<<incomes[i].getUserId()<<endl;
        cout<<"data: "<<incomes[i].getIncomeDate()<<endl;
        cout<<"Comment: "<<incomes[i].getIncomeComment()<<endl;
        cout<<"wartosc: "<<incomes[i].getIncomeValue()<<endl;

    }
    system("pause");
}

void IncomeMenager::displayCurrentMonthIncomesInOrder()
{
    vector <Income> incomesInOrder;
    string currentMonth;
    string incomeMonth;
    int sumOfIncomes=0;
    currentMonth = (setCurrentDate()).substr(0,7);;
    for (int i=0; i<incomes.size(); i++)
    {
        incomeMonth = (incomes[i].getIncomeDate()).substr(0,7);
        if( currentMonth == incomeMonth)
        {
            cout<<"data: "<<incomes[i].getIncomeDate()<<endl;
            cout<<"Comment: "<<incomes[i].getIncomeComment()<<endl;
            sumOfIncomes = sumOfIncomes+incomes[i].getIncomeValue();
            cout<<"wartosc: "<<incomes[i].getIncomeValue()<<endl;

        }
    }


    cout<<"Sum of incomes = "<<sumOfIncomes<<endl;
    system("pause");
}

string IncomeMenager::setCurrentDate()
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
    syear =  MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_year+1900);
    smonth = MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_mon+1);
    sday = MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_mday);
    if(smonth.length()==1)
        smonth="0"+smonth;
    if(sday.length()==1)
        sday="0"+sday;
    currentDay = syear+"-"+smonth+"-"+sday;
    return currentDay;

}


void IncomeMenager::displayLastMonthIncomes()
{
    string lastMonthDate,incomeDate, syear,smonth;
    int month, sumOfIncomes=0;
    syear = (setCurrentDate()).substr(0,4);
    smonth = (setCurrentDate()).substr(5,2);
    month = MetodyPomocnicze::konwersjaStringNaInt(smonth)-1;
    smonth =MetodyPomocnicze::konwerjsaIntNaString(month);
    if(smonth.length()==1)
        smonth = "0"+smonth;
    lastMonthDate= syear+"-"+smonth;

    for (int i=0; i<incomes.size(); i++)
    {
        incomeDate = (incomes[i].getIncomeDate()).substr(0,7);
      if( incomeDate == lastMonthDate)
        {
            cout<<"data: "<<incomes[i].getIncomeDate()<<endl;
            cout<<"Comment: "<<incomes[i].getIncomeComment()<<endl;
            sumOfIncomes = sumOfIncomes+incomes[i].getIncomeValue();
            cout<<"wartosc: "<<incomes[i].getIncomeValue()<<endl;
        }
    }
    cout<<"Sum of incomes = "<<sumOfIncomes<<endl;

    system("pause");
}

void IncomeMenager::choosenPeriodIncomes()
{
    string startDate,endDate,incomeDate;
    cout<<"Start date, ";
    startDate = takeDateFromUser();
    cout<<"End date, ";
    endDate = takeDateFromUser();

    while((MetodyPomocnicze::convertDateIntoValue(startDate)>MetodyPomocnicze::convertDateIntoValue(endDate)))
    {
        cout<<"Start date should be before end date!!"<<endl;
        cout<<"Start date, ";
        startDate = takeDateFromUser();
        cout<<"End date, ";
        endDate = takeDateFromUser();
    }

    cout<<"Display all incomes from "<<startDate<<" till "<<endDate<<endl;

    displayIncomesInChoosenPeriod(startDate,endDate);

}

void IncomeMenager::displayIncomesInChoosenPeriod(string startDate, string endDate)
{
    int startDateValue, endDateValue, incomeDateValue;
    int sumOfIncomes=0;

    startDateValue = MetodyPomocnicze::convertDateIntoValue(startDate);
    endDateValue = MetodyPomocnicze::convertDateIntoValue(endDate);
    for (int i=0; i<incomes.size(); i++)
    {
        incomeDateValue = incomes[i].getIncomeDateValue();
        //cout<<incomeDateValue<<endl;
        if( incomeDateValue>=startDateValue && incomeDateValue<=endDateValue)
        {
            cout<<"incomeId: "<<incomes[i].getIncomeId()<<endl;
            cout<<"data: "<<incomes[i].getIncomeDate()<<endl;
            cout<<"Comment: "<<incomes[i].getIncomeComment()<<endl;
            sumOfIncomes = sumOfIncomes+incomes[i].getIncomeValue();
            cout<<"wartosc: "<<incomes[i].getIncomeValue()<<endl;
        }
    }
    cout<<"Sum of incomes = "<<sumOfIncomes<<endl;
system("pause");

}
