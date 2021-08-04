#include "MyWallet.h"

using namespace std;

void MyWallet::userRegistration()
{
    userMenager.userRegistration();

}
void MyWallet::userLogin()
{
    userMenager.userLogin();

}

void MyWallet::userLogout()
{
    userMenager.userLogout();

}

void MyWallet::addIncomeOfLoggedUser()
{
   incomeMenager.addIncomeOfLoggedUser();
}

void  MyWallet::dispiayAllUsers()
{
    userMenager.displauAllUsers();
}
