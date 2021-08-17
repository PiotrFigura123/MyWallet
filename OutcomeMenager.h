#ifndef OUTCOMEMENAGER_H
#define OUTCOMEMENAGER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>
#include "FileWithOutcome.h"
#include "UserMenager.h"
#include "MetodyPomocnicze.h"
#include "Outcome.h"
#include "Markup.h"
#include "FileWithBalance.h"
using namespace std;
class OutcomeMenager:public FileWithBalance
{
        const int LOGGED_USER_ID;
        vector <Outcome> outcomes;
        FileWithOutcome fileWithOutcome;
        Outcome takeOutcomeOfUser(int userId);
        int takeIdOfLastOutcomeFromFile();
        void displayOutcomesInChoosenPeriod(string startDate,string endDate);
        double sumOfOutcomes;

public:
    OutcomeMenager(string nameOfFileWithOutcomes, int idOfLoggedUser):
    fileWithOutcome(nameOfFileWithOutcomes), LOGGED_USER_ID(idOfLoggedUser)
    {

    outcomes = fileWithOutcome.loadOutcomeOfUserFromFile(LOGGED_USER_ID);

    };
    void addOutcomeOfLoggedUser(int userId);
    void displayAllOutcomes();
    void displayCurrentMonthOutcomesInOrder();
    void displayLastMonthOutcomes();
    void choosenPeriodOutcomes(string startDate, string endDate);
    double getSumOfOutcomes();

};


#endif
