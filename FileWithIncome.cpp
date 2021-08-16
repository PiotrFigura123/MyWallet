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

    bool bSuccess = xml.Load( NAME_OF_FILE_WITH_INCOMES );
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("income"))
    {
        xml.IntoElem();
        xml.FindElem("IncomeId");
        income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
        lastIncomeId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("userId");
        user = (atoi(MCD_2PCSZ(xml.GetData())));
        if(user==LOGGED_USER_ID)
        {
            income.setUserId(user);
            xml.FindElem( "incomeDate" );
            income.setIncomeDate(xml.GetData());
            xml.FindElem( "incomeComment" );
            income.setIncomeComment(xml.GetData());
            xml.FindElem( "incomeValue" );
            sumOfIncomes = sumOfIncomes+atoi(MCD_2PCSZ(xml.GetData()));
            income.setIncomevalue(stod(MCD_2PCSZ(xml.GetData())));

            xml.FindElem( "incomeDateValue" );
            income.setIncomeDateValue(atoi(MCD_2PCSZ(xml.GetData())));

            incomes.push_back(income);
        }

        xml.OutOfElem();
    }

    return incomes;
}


void FileWithIncome::addIncomeOfLoggedUser(Income income)
{
    bool bSuccess = xml.Load( NAME_OF_FILE_WITH_INCOMES );

    if(!bSuccess)
    {
        xml.AddElem( NAME_OF_FILE_WITH_INCOMES );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "income" );
    xml.IntoElem();
    xml.AddElem( "IncomeId",MetodyPomocnicze::konwerjsaIntNaString(income.getIncomeId())) ;
    xml.AddElem( "userId", MetodyPomocnicze::konwerjsaIntNaString(income.getUserId()));
    xml.AddElem( "incomeDate",income.getIncomeDate());
    xml.AddElem( "incomeComment", income.getIncomeComment());
   xml.AddElem( "incomeValue", MetodyPomocnicze::konwerjsaDoubleNaString(income.getIncomeValue()));
    xml.AddElem( "incomeDateValue", MetodyPomocnicze::konwerjsaIntNaString(income.getIncomeDateValue()));
    xml.Save( "income.xml" );
    system("pause");
    lastIncomeId++;
}

int FileWithIncome::getLastincomeId()
{
    return lastIncomeId;
}

void FileWithIncome::setNewLastincomeId(int id)
{
    lastIncomeId = id++;
}

void FileWithIncome::setLastIncomeId(int id)
{
    lastIncomeId = id;
}




