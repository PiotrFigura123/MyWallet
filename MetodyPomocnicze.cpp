#include "MetodyPomocnicze.h"

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
    cout << "6. none" << endl;
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
    if ((month = 1) || (month = 3) || (month = 5) || (month = 7) ||
        (month = 8) || (month = 10) || (month = 12))
    {
        day <= 31;
        return true;
    }
    else if ((month = 4) || (month = 6) || (month = 9) || (month = 11))
    {
        day <= 30;
        return true;
    }
    else if ((month = 2) && (year % 4 == 0))
    {
    day <= 29;
    return true;
    }
    else if ((month = 2) && (year % 4 != 0))
    {
        day <= 28;
        return true;
    }
    else
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
    //cout<<"syear ="<<syear<<" smonth ="<<smonth<<" sday = "<<sday<<endl;

    year = MetodyPomocnicze::konwersjaStringNaInt(syear);
    month = MetodyPomocnicze::konwersjaStringNaInt(smonth);
    day = MetodyPomocnicze::konwersjaStringNaInt(sday);
    system("pause");
    //cout<<"Year: "<<year<<endl;
    //cout<<"Month: "<<month<<endl;
    //cout<<"Day: "<<day<<endl;
    year = year*500;
    month = month*32;
    //cout<<"Year: "<<year<<endl;
    //cout<<"Month: "<<month<<endl;
    sum = year+month+day;
    //cout<<"SUM = "<<sum<<endl;
    return sum;
}
