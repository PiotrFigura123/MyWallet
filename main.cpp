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
                    case '7':
                        myWallet.changePasswordOfUser();
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
}
