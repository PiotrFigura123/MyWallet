#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream>

using namespace std;
class MetodyPomocnicze
{
    static char wczytajZnak();
    public:
        static string konwerjsaIntNaString(int liczba);
        static int konwersjaStringNaInt(string liczba);
        static string wczytajLinie();
        static char wybierzOpcjeZMenuGlownego();
        static char wybierzOpcjeZMenuUzytkownika();
        static bool checkDate(int year, int month , int day);
        static int compareDates(int y, int m, int d);
};

#endif // METODYPOMOCNICZE_H

