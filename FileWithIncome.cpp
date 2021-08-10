#include "FileWithIncome.h"

vector <Income> FileWithIncome::loadIncomeOfUserFromFile(int LOGGED_USER_ID)
{
    //cout<<"LOGGED_USER_ID = "<<LOGGED_USER_ID<<endl;
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
        xml.FindElem("IncomeId");
        income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
        //cout<<"lastIncomeId = "<<atoi(MCD_2PCSZ(xml.GetData()))<<endl;
        lastIncomeId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("userId");
        user = (atoi(MCD_2PCSZ(xml.GetData())));
        //cout<<"User = "<<user<<endl;
        if(user==LOGGED_USER_ID)
        {
            income.setUserId(user);
            xml.FindElem( "incomeDate" );
            income.setIncomeDate(xml.GetData());
            xml.FindElem( "incomeComment" );
            income.setIncomeComment(xml.GetData());
            xml.FindElem( "incomeValue" );
            sumOfIncomes = sumOfIncomes+atoi(MCD_2PCSZ(xml.GetData()));
            income.setIncomevalue(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "incomeDateValue" );
            income.setIncomeDateValue(atoi(MCD_2PCSZ(xml.GetData())));

            incomes.push_back(income);
        }

        xml.OutOfElem();
    }
    //cout<<"sumOfIncomes = "<<sumOfIncomes<<endl;
    //cout<<"lastIncome = "<<lastIncomeId<<endl;
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
    xml.AddElem( "incomeDateValue", MetodyPomocnicze::konwerjsaIntNaString(income.getIncomeDateValue()));
    xml.Save( "income.xml" );

}

int FileWithIncome::getLastincomeId()
{
    return lastIncomeId;
}

int FileWithIncome::setNewLastincomeId()
{
    int newIncomeId = getLastincomeId()+1;
    return  newIncomeId ;
}




