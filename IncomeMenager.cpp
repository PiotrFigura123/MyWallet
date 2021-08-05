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
    system("CLS");
    cout<<"Income registration: "<<endl;
    Income income;
    int incomeId, incomeValue;
    string incomeDate, incomeComment;

    incomeId = fileWithIncome.setNewLastincomeId();
    //cout<<endl<<"INCOME ID = " <<incomeId<<endl;
    //cout<<endl<<"ID_LOGGED_USER = " <<userId<<endl;
    incomeDate = takeDateFromUser();

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
    return income;
}

/*int IncomeMenager::takeIdOfLastIncomeFromFile()

{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}*/

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


void IncomeMenager::displayAllIncomes()
{
    for (int i=0; i<incomes.size(); i++)
    {

        cout<<"InomeId: "<< incomes[i].getIncomeId()<<endl;
        cout<<"userId: "<<incomes[i].getUserId()<<endl;
        cout<<"data: "<<incomes[i].getIncomeDate()<<endl;
        cout<<"wartosc: "<<incomes[i].getIncomeValue()<<endl;
        cout<<"Comment: "<<incomes[i].getIncomeComment()<<endl<<endl;

    }
    system("pause");
}

