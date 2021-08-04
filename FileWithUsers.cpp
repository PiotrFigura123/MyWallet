#include "FileWithUsers.h"

vector <User> FileWithUsers::readUserFromFile(string nameOfFileWithUsers)
{
    User user;
    vector <User> users;

    bool bSuccess = xml.Load( "users.xml" );
    int ID;
    string login, name, surename, pass;
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("ID");
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

    }

return users;
}


void FileWithUsers::addUserToFile(User user)
{

    bool bSuccess = xml.Load( "users.xml" );

    if(!bSuccess)
    {
        xml.AddElem( "Users" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "User" );
    xml.IntoElem();
    xml.AddElem( "ID", user.getId());
    xml.AddElem( "Login", user.getLogin());
    xml.AddElem( "Password", user.getPassword());
    xml.AddElem( "Name", user.getName());
    xml.AddElem( "Surename", user.getSurename() );
    xml.Save( "users.xml" );

}

void FileWithUsers::currentDate()
{
    int rok, miesiac, dzien;
    string currentDay, year,month,day;
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);
    rok = nowLocal.tm_year+1900;
    miesiac = nowLocal.tm_mon+1;
    dzien = nowLocal.tm_mday;
    cout<<MetodyPomocnicze::checkDate(rok,miesiac, dzien);
    year =  MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_year+1900);
    month = MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_mon+1);
    day = MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_mday);
    currentDay = year+"-"+month+"-"+day;
    cout<<currentDay<<endl;
}

