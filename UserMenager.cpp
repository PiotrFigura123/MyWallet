#include "UserMenager.h"
using namespace std;

void UserMenager::userRegistration()
{
    cout<<users.size();
    User user = takeDataOfNewUser();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);


}

User UserMenager::takeDataOfNewUser()
{
    cout<<"Rejestracja uzytkownika: "<<endl;
    User user;
    int id;
    id = loadIdOfLastUser();
    string login,password,name,surename;

    cout<<"Login: ";
    cin>>login;
    cout<<"Password: ";
    cin>>password;
    cout<<"Name: ";
    cin>>name;
    cout<<"Surename: ";
    cin>>surename;

    user.setId(id);
    user.setLogin(login);
    user.setPassword(password);
    user.setName(name);
    user.setSurename(surename);
    return user;
}

int UserMenager:: loadIdOfLastUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}
void UserMenager::userLogin()
{
    User user;
    string login = "", password = "";

    cout << endl << "Login: ";
    cin>>login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin>>password;

                if (itr -> getPassword() == password)
                {
                    idOfLoggedUser = itr ->getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    cout<<idOfLoggedUser;
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;

}


