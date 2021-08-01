#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;
class User
{
    int id;
    string login;
    string password;
    string name;
    string surename;
public:

    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string nweName);
    void setSurename(string newSurename);

    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurename();
};

#endif
