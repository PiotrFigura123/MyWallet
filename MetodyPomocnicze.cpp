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
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
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

int MetodyPomocnicze::compareDates(int y, int m, int d)
{
    int sum=0;
    sum = y*1000+m*50+d;
    return sum;
}
