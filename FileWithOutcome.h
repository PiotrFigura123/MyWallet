#ifndef FILEWITHOUTCOME_H
#define FILEWITHOUTCOME_H
#include <iostream>
#include <vector>
#include "Outcome.h"
#include "Markup.h"
#include "MetodyPomocnicze.h"

class FileWithOutcome
{
    CMarkup xml;
    const string NAME_OF_FILE_WITH_OUTCOMES;
    int sumOfOutcomes;
    int lastOutcomeId;
public:
    FileWithOutcome(string nameOfFilesWithOutcome):NAME_OF_FILE_WITH_OUTCOMES(nameOfFilesWithOutcome)
     {
        lastOutcomeId=0;

        };
    vector <Outcome> loadOutcomeOfUserFromFile(int LOGGED_USER_ID);
    void addOutcomeOfLoggedUser(Outcome outcome);
    int getLastOutcomeId();
    int setNewLastOutcomeId();
    int getSumOfOutcomes();
};



#endif
