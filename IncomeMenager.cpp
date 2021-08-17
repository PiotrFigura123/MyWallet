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
    int incomeId;
    double incomeValue ;
    string incomeDate, incomeComment;
    double incomeDateValue;
    incomeId = fileWithIncome.getLastincomeId()+1;

    cout<<"Current date? [y/n] : ";
    cin>>chooseDate;
    if(chooseDate=='n')
         incomeDate = MetodyPomocnicze::takeDateFromUser();

    else
        incomeDate = MetodyPomocnicze::setCurrentDate();

    incomeDateValue = MetodyPomocnicze::convertDateIntoValue(incomeDate);
    cout<<endl<<"Date: "<<incomeDate<<endl;
    cout<<"Income comment: ";
    cin.ignore();
    getline(cin, incomeComment);

    cout<<"Income value: ";
    incomeValue = MetodyPomocnicze::takeValueFromUser();


    income.setIncomeId(incomeId);
    income.setUserId(userId);
    income.setIncomeDate(incomeDate);
    income.setIncomeComment(incomeComment);
    income.setIncomevalue(incomeValue);
    income.setIncomeDateValue(incomeDateValue);
    return income;
}

void IncomeMenager::displayCurrentMonthIncomesInOrder()
{
    sort(incomes.begin(),incomes.end());

    string currentMonth;
    string incomeMonth;
    sumOfIncomes=0;
    currentMonth = (MetodyPomocnicze::setCurrentDate()).substr(0,7);
    cout<< " ------INCOMES------"<<endl;
    for (int i=0; i<incomes.size(); i++)
    {
        incomeMonth = (incomes[i].getIncomeDate()).substr(0,7);
        if( currentMonth == incomeMonth)
        {
            cout<<"data: "<<incomes[i].getIncomeDate()<<endl;
            cout<<"Comment: "<<incomes[i].getIncomeComment()<<endl;
            sumOfIncomes = sumOfIncomes+incomes[i].getIncomeValue();
            cout<<"wartosc: "<<incomes[i].getIncomeValue()<<endl<<endl;

        }
    }


    cout<<"Sum of incomes = "<<sumOfIncomes<<endl;
    system("pause");
}

void IncomeMenager::displayLastMonthIncomes()
{
    sort(incomes.begin(),incomes.end());
    string lastMonthDate,incomeDate, syear,smonth;
    int month;
    sumOfIncomes=0;
    syear = (MetodyPomocnicze::setCurrentDate()).substr(0,4);
    smonth = (MetodyPomocnicze::setCurrentDate()).substr(5,2);
    month = MetodyPomocnicze::konwersjaStringNaInt(smonth)-1;
    smonth =MetodyPomocnicze::konwerjsaIntNaString(month);
    if(smonth.length()==1)
        smonth = "0"+smonth;
    lastMonthDate= syear+"-"+smonth;
    system("cls");
    cout<< " ------INCOMES------"<<endl;
    for (int i=0; i<incomes.size(); i++)
    {
        incomeDate = (incomes[i].getIncomeDate()).substr(0,7);
      if( incomeDate == lastMonthDate)
        {
            cout<<"data: "<<incomes[i].getIncomeDate()<<endl;
            cout<<"Comment: "<<incomes[i].getIncomeComment()<<endl;
            sumOfIncomes = sumOfIncomes+incomes[i].getIncomeValue();
            cout<<"wartosc: "<<incomes[i].getIncomeValue()<<endl<<endl;
        }
    }
    cout<<"Sum of incomes = "<<sumOfIncomes<<endl;

    system("pause");
}

void IncomeMenager::choosenPeriodIncomes(string startDate, string endDate)
{
    string incomeDate;
    cout<<"Start date, "<<startDate<<endl;
    cout<<"End date, "<<endDate<<endl;
    while((MetodyPomocnicze::convertDateIntoValue(startDate)>MetodyPomocnicze::convertDateIntoValue(endDate)))
    {
        cout<<"Start date should be before end date!!"<<endl;
        cout<<"Start date, ";
        startDate = MetodyPomocnicze::takeDateFromUser();
        cout<<"End date, ";
        endDate = MetodyPomocnicze::takeDateFromUser();

    }

    cout<<"Display all incomes from "<<startDate<<" till "<<endDate<<endl;

    displayIncomesInChoosenPeriod(startDate,endDate);

}

void IncomeMenager::displayIncomesInChoosenPeriod(string startDate, string endDate)
{
    int startDateValue, endDateValue, incomeDateValue;
    sumOfIncomes=0;

    sort(incomes.begin(),incomes.end());
    startDateValue = MetodyPomocnicze::convertDateIntoValue(startDate);
    endDateValue = MetodyPomocnicze::convertDateIntoValue(endDate);
    system("cls");
    cout<< " ------INCOMES------"<<endl;
    for (int i=0; i<incomes.size(); i++)
    {
        incomeDateValue = incomes[i].getIncomeDateValue();
        if( incomeDateValue>=startDateValue && incomeDateValue<=endDateValue)
        {
            cout<<"incomeId: "<<incomes[i].getIncomeId()<<endl;
            cout<<"data: "<<incomes[i].getIncomeDate()<<endl;
            cout<<"Comment: "<<incomes[i].getIncomeComment()<<endl;
            sumOfIncomes = sumOfIncomes+incomes[i].getIncomeValue();
            cout<<"wartosc: "<<incomes[i].getIncomeValue()<<endl<<endl;
        }
    }
    cout<<"Sum of incomes = "<<sumOfIncomes<<endl;
system("pause");

}

double IncomeMenager::getSumOfIncomes()
{
    return sumOfIncomes;
}
