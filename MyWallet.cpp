#include "MyWallet.h"

using namespace std;

void MyWallet::userRegistration()
{
    userMenager.userRegistration();

}
void MyWallet::userLogin()
{
    userMenager.userLogin();
    incomeMenager = new IncomeMenager(NAME_OF_FILE_WITH_INCOMES, userMenager.getIdOfLoggedUser());
    outcomeMenager = new OutcomeMenager(NAME_OF_FILE_WITH_OUTCOMES, userMenager.getIdOfLoggedUser());
}


void MyWallet::userLogout()
{
    userMenager.userLogout();

}

void MyWallet::addIncomeOfLoggedUser()
{
   incomeMenager->addIncomeOfLoggedUser(userMenager.getIdOfLoggedUser());
}
void MyWallet::addOutcomeOfLoggedUser()
{
   outcomeMenager->addOutcomeOfLoggedUser(userMenager.getIdOfLoggedUser());
}

void  MyWallet::dispiayAllUsers()
{
    userMenager.displauAllUsers();
}

void MyWallet::displayAllIncomesInOrder()
{
   incomeMenager->displayAllIncomesInOrder();
}

void MyWallet::displayCurrentMonthBalance()
{   system("cls");
    incomeMenager->displayCurrentMonthIncomesInOrder();
    system("cls");
    outcomeMenager->displayCurrentMonthOutcomesInOrder();
    system("cls");
}
void MyWallet::displayLastMonthBalance()
{
    system("cls");
    incomeMenager->displayLastMonthIncomes();
    system("cls");
    //outcomeMenager->displayChoosenPerionOutcomes();
    system("cls");
}
