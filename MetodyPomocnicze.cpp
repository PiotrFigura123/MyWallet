#include "MetodyPomocnicze.h"

void choosenPeriod();
string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}
string MetodyPomocnicze::wczytajLinie()
{
    string wejscie = "";
    cin>>wejscie;
    return wejscie;
}
char MetodyPomocnicze::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
char MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add outcome" << endl;
    cout << "3. Display current month balance" << endl;
    cout << "4. Display last month balanc" << endl;
    cout << "5. Choose Your period and show balance" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}
char MetodyPomocnicze::wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}
bool MetodyPomocnicze::checkDate(int year, int month, int day)
{
    cout<<"yeas: "<<year<< " month: "<<month<<" day: "<<day<<endl;
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||(month == 8) || (month == 10) || (month == 12))
    {
        if(day <= 31)
        {
            return true;
        }
        else
            cout<<"Outcorrect date, please provide new one"<<endl;
        return false;
    }
    else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
    {
        if(day <= 30)
        {
            return true;
        }
        else
            cout<<"Incorrect date, please provide new one"<<endl;
        return false;
    }
    else if ((month == 2) && (year % 4 == 0))
    {
        if(day <= 29)
        {
            return true;
        }
        else
            cout<<"Incorrect date, please provide new one"<<endl;
        return false;
    }
    else if ((month == 2) && (year % 4 != 0))
    {
        if(day <= 28)
        {
            return true;
        }
        else
            cout<<"Incorrect date, please provide new one"<<endl;
        return false;
    }
    else
        cout<<"Incorrect date, please provide new one"<<endl;
    return false;
}
double MetodyPomocnicze::convertDateIntoValue(string date)
{
    double sum=0;
    string syear, smonth,sday;
    int year,month,day;
    syear = date.substr(0,4);
    smonth = date.substr(5,2);
    sday = date.substr(8,2);

    year = MetodyPomocnicze::konwersjaStringNaInt(syear);
    month = MetodyPomocnicze::konwersjaStringNaInt(smonth);
    day = MetodyPomocnicze::konwersjaStringNaInt(sday);
    year = year*500;
    month = month*32;
    sum = year+month+day;
    return sum;
}
string MetodyPomocnicze:: konwerjsaDoubleNaString(double dbl)
{
    ostringstream strs;
    strs << dbl;
    string str = strs.str();
    return str;
}
double MetodyPomocnicze::takeValueFromUser()
{
    string svalue;
    cin >>svalue;
    replace( svalue.begin(), svalue.end(), ',', '.');
    double value = stod(svalue);
    return value;
}
string MetodyPomocnicze::takeDateFromUser()
{
    int year=0,month=0,day=0;
    string date;
    do
    {
        cout<<" Year(after 2000): ";
        cin>>year;
        while(year<2000)
        {
            cout<<"Incorrect year, put new please: ";
            cin>>year;
        }

        cout<<"Month: ";
        cin>>month;
        while( 1>month || month>12)
        {
            cout<<"Incorrect month, put new please: ";
            cin>>month;
        }
        cout<<"Day: ";
        cin>>day;

    }
    while(!checkDate(year,month,day));

    string syear = MetodyPomocnicze::konwerjsaIntNaString(year);
    string smonth = MetodyPomocnicze::konwerjsaIntNaString(month);
    string sday = MetodyPomocnicze::konwerjsaIntNaString(day);
    if(smonth.length()==1)
        smonth = "0"+smonth;
    if(sday.length()==1)
        sday="0"+sday;
    date = syear+"-"+smonth+"-"+sday;
    return date;
}

string MetodyPomocnicze::setCurrentDate()
{
    int year, month, day;
    string currentDay, syear,smonth,sday;
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);
    year = nowLocal.tm_year+1900;
    month = nowLocal.tm_mon+1;
    day = nowLocal.tm_mday;
    syear =  MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_year+1900);
    smonth = MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_mon+1);
    sday = MetodyPomocnicze::konwerjsaIntNaString(nowLocal.tm_mday);
    if(smonth.length()==1)
        smonth="0"+smonth;
    if(sday.length()==1)
        sday="0"+sday;
    currentDay = syear+"-"+smonth+"-"+sday;
    return currentDay;

}

