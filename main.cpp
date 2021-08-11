#include <iostream>
#include "MyWallet.h"
#include "UserMenager.h"

using namespace std;
int main()
{
    MyWallet myWallet("users.xml", "income.xml", "outcome.xml");
    char chooseOptionFromUserMenu = '0';
    char wyboru = '0';
    while(true)
    {
LOOP:
        chooseOptionFromUserMenu = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();

        switch (chooseOptionFromUserMenu)
        {
        case '1':
            myWallet.userRegistration();
            break;
        case '2':
        {
            myWallet.userLogin();

                while(myWallet.isUserLogged())
                {
                    wyboru = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();
                    switch (wyboru)
                    {
                    case '1':
                        myWallet.addIncomeOfLoggedUser();
                        break;
                    case '2':
                        myWallet.addOutcomeOfLoggedUser();
                        break;
                    case '3':
                        myWallet.displayCurrentMonthBalance();
                        break;
                    case '4':
                        myWallet.displayLastMonthBalance();
                        break;
                    case '5':
                        myWallet.displayChoosenPeriodBalance();
                        break;
                    case '6':

                        break;
                    case '7':
                        myWallet.changePasswordOfUser();
                        //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                        break;
                    case '8':
                        myWallet.userLogout();
                        goto LOOP;
                        break;
                    }
            }
        }
        case '9':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }






    //myWallet.userRegistration();
   myWallet.userLogin();

  //myWallet.addIncomeOfLoggedUser();
  //myWallet.addIncomeOfLoggedUser();
   //myWallet.displayAllIncomes();
   //myWallet.addOutcomeOfLoggedUser();

   //myWallet.userLogin();
   //myWallet.addOutcomeOfLoggedUser();
   //myWallet.displayCurrentMonthBalance();
//myWallet.displayLastMonthBalance();
  myWallet.displayChoosenPeriodBalance();
   //myWallet.displayAllIncomesInOrder();
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
