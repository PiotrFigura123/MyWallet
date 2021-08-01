#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <time.h>
#include "MetodyPomocnicze.h"
#include "Markup.h"
using namespace std;

class FileWithUsers
{
    CMarkup xml;
public:
    fileWithUsers(){};

    void currentDate();
    void readUserFromFile();
    void saveUserInFile();
};

#endif
