#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <time.h>
#include "FileWithBalance.h"
using namespace std;
class MetodyPomocnicze
{

public:
static bool checkDate(int year, int month , int day);
static string konwerjsaIntNaString(int liczba);
static int konwersjaStringNaInt(string liczba);
static string wczytajLinie();
static char wybierzOpcjeZMenuGlownego();
static char wybierzOpcjeZMenuUzytkownika();

static double convertDateIntoValue(string date);
static string konwerjsaDoubleNaString(double liczba);
static double takeValueFromUser();
static string takeDateFromUser();
static string setCurrentDate();
static char wczytajZnak();


};

#endif // METODYPOMOCNICZE_H

