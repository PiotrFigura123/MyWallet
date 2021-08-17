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
    outcomeMenager->displayLastMonthOutcomes();
    system("cls");
}

void MyWallet::displayChoosenPeriodBalance()
{
    system("CLS");
    cout<<"Start date: ";
    string startDate = MetodyPomocnicze::takeDateFromUser();
    cout<<"End date: ";
    string endDate = MetodyPomocnicze::takeDateFromUser();
    incomeMenager->choosenPeriodIncomes(startDate, endDate);
    system("cls");
    outcomeMenager->choosenPeriodOutcomes(startDate, endDate);
    system("cls");
    cout<<"Incomes = "<<incomeMenager->getSumOfIncomes()<<endl;
    cout<<"Outcomes = "<<outcomeMenager->getSumOfOutcomes()<<endl;
    cout<<"Balance = " <<incomeMenager->getSumOfIncomes() - outcomeMenager->getSumOfOutcomes()<<endl;
    system("pause");
}
 bool  MyWallet::isUserLogged()
 {
     return userMenager.isUserLogged();
 }

 void MyWallet::changePasswordOfUser()
 {
     userMenager.updateUserPassword();
 }
