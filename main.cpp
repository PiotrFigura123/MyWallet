#include <iostream>
#include "MyWallet.h"
#include "UserMenager.h"

using namespace std;
int main()
{
    MyWallet myWallet("users.xml", "income.xml", "outcome.xml");
    //myWallet.userRegistration();
   myWallet.userLogin();
   myWallet.addOutcomeOfLoggedUser();
   myWallet.addOutcomeOfLoggedUser();
   myWallet.addOutcomeOfLoggedUser();
   myWallet.addOutcomeOfLoggedUser();
   //myWallet.userLogin();
   //myWallet.addOutcomeOfLoggedUser();
   //myWallet.currentMonthBalance();
   //myWallet.displayAllIncomes();
   //myWallet.dispiayAllUsers();
}


/*  Find element
xml.FindElem(); // root ORDER element
xml.IntoElem(); // inside ORDER
while ( xml.FindElem("ITEM") )
{
    xml.IntoElem();
    xml.FindElem( "SN" );
    MCD_STR strSN = xml.GetData();
    xml.FindElem( "QTY" );
    int nQty = atoi( MCD_2PCSZ(xml.GetData()) );
    xml.OutOfElem();
}

 to find element contained in some ELEMENT
xml.ResetPos(); // top of document
xml.FindElem(); // ORDER element is root
xml.IntoElem(); // inside ORDER
while ( xml.FindElem("ITEM") )
{
    xml.FindChildElem( "SN" );
    if ( xml.GetChildData() == strFindSN )
        break; // found
}*/
