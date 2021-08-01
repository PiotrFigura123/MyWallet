#include "Plik.h"

void FileWithUsers::readUserFromFile()
{
    bool bSuccess = xml.Load( "users.xml" );
    int ID;
    string login;
    string pass;
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("ID");
        MCD_STR strSN = xml.GetData();
        ID = atoi( MCD_2PCSZ(xml.GetData()));
        cout<<ID<<endl;
        xml.FindElem( "Login" );
        login = xml.GetData();
        cout<<login<<endl;
        pass = xml.FindElem( "Has" );
        cout<<pass<<endl;
        xml.OutOfElem();
    }


}
void FileWithUsers::saveUserInFile()
{
    string id, name, surename;
    bool bSuccess = xml.Load( "users.xml" );
    if(!bSuccess)
    {
        xml.AddElem( "Users" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "User" );
    xml.IntoElem();
    cout<<"id: ";
    cin>>id;
    cout<<"Name: ";
    cin>>name;
    cout<<"Sureame: ";
    cin>>surename;
    xml.AddElem( "ID", id );
    xml.AddElem( "Login", name );
    xml.AddElem( "Has", surename );

    xml.Save( "users.xml" );
}

void Plik::currentDate()
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


