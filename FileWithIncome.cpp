#include "FileWithIncome.h"

vector <Income> FileWithIncome::loadIncomeOfUserFromFile(int LOGGED_USER_ID)
{
    Income income;
    vector <Income> incomes;
    int incomeId;
    int user;
    string incomeDate;
    string incomeComment;
    int incomeValue;

    bool bSuccess = xml.Load( "income.xml" );
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("income"))
    {
        xml.IntoElem();
        xml.FindElem("incomeId");
        //MCD_STR strSN = xml.GetData();
        income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
        lastIncomeId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("userId");
        //MCD_STR strSN = xml.GetData();
        user = (atoi(MCD_2PCSZ(xml.GetData())));
        if(user==LOGGED_USER_ID)
        {
            income.setUserId(user);
            xml.FindElem( "incomeDate" );
            income.setIncomeDate(xml.GetData());
            xml.FindElem( "incomeComment" );
            income.setIncomeComment(xml.GetData());
            xml.FindElem( "incomeValue" );
            //MCD_STR strSN = xml.GetData();
            income.setIncomevalue(atoi(MCD_2PCSZ(xml.GetData())));

            incomes.push_back(income);
        }

        xml.OutOfElem();
    }

    return incomes;
}


void FileWithIncome::addIncomeOfLoggedUser(Income income)
{
    bool bSuccess = xml.Load( "income.xml" );

    if(!bSuccess)
    {
        xml.AddElem( "incomes" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "income" );
    xml.IntoElem();
    xml.AddElem( "IncomeId",MetodyPomocnicze::konwerjsaIntNaString(income.getIncomeId())) ;
    xml.AddElem( "userId", MetodyPomocnicze::konwerjsaIntNaString(income.getUserId()));
    xml.AddElem( "incomeDate",income.getIncomeDate());
    xml.AddElem( "incomeComment", income.getIncomeComment());
    xml.AddElem( "incomeValue", MetodyPomocnicze::konwerjsaIntNaString(income.getIncomeValue()));
    xml.Save( "income.xml" );

}
