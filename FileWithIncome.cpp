#include "FileWithIncome.h"

 vector <Income> FileWithIncome::loadIncomeOfUserFromFile(int ID_LOGGED_USER)
 {
   /* Income income;
    vector <Income> incomes;

    bool bSuccess = xml.Load( "income.xml" );
    int incomeId, userId;
    string date, comment, value;

    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("userId"))
    {
        xml.IntoElem();
        while(xml.FindElem("userId"));
        MCD_STR strSN = xml.GetData();
        user.setId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Login" );
        user.setLogin(xml.GetData());
        xml.FindElem( "Password" );
        user.setPassword(xml.GetData());
        xml.FindElem( "Name" );
        user.setName(xml.GetData());
        xml.FindElem( "Surename" );
        user.setSurename(xml.GetData());
        users.push_back(user);
        xml.OutOfElem();
        return Income;
*/
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
