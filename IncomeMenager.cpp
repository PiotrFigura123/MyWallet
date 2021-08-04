#include "IncomeMenager.h"

void IncomeMenager::addIncomeOfLoggedUser()
{   Income income;
    //userMenager.getIdOfLoggedUser();
    income = takeIncomeOfUser();
    incomes.push_back(income);
    //cout<<endl<<"incomes size = "<<incomes.size();
    fileWithIncome.addIncomeOfLoggedUser(income);
}

Income IncomeMenager::takeIncomeOfUser()
{

    cout<<"Income registration: "<<endl;
    Income income;
    int incomeId, userId=2, incomeValue;
    string incomeDate, incomeComment;

    incomeId = takeIdOfLastIncomeFromFile();
    cout<<endl<<"INCOME ID = " <<2<<endl;
    cout<<endl<<"ID_LOGGED_USER = " <<2<<endl;
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

int IncomeMenager::takeIdOfLastIncomeFromFile()

{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
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
        //cout<<"Date correct 4,6,9,11."<<endl;
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
        //cout<<"Date correct 21."<<endl;
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
        //cout<<"Date correct 22."<<endl;
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

        }while(!checkDate(year,month,day));

    string syear = MetodyPomocnicze::konwerjsaIntNaString(year);
    cout<<"syear: "<<syear<<endl;
    string smonth = MetodyPomocnicze::konwerjsaIntNaString(month);
    string sday = MetodyPomocnicze::konwerjsaIntNaString(day);
    if(smonth.length()==1)
        smonth = "0"+smonth;
    if(sday.length()==1)
        sday="0"+sday;
    date = syear+"-"+smonth+"-"+sday;
    cout <<date<<endl;
    system("pause");
    return date;
}

