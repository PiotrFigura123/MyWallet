#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <time.h>
#include <vector>
#include "MetodyPomocnicze.h"
#include "Users.h"
#include "Markup.h"
using namespace std;

class FileWithUsers
{
    CMarkup xml;
    const string NAME_OF_FILE_WITH_USERS;
    //bool checkIfLoginExist(User user);
    string takeIDOfLastUser();

public:
   FileWithUsers(string nameOfFileWithUsers): NAME_OF_FILE_WITH_USERS(nameOfFileWithUsers){

    };

    void currentDate();
    vector <User> readUserFromFile(string nameOfFileWithUsers);
    void addUserToFile(User user);
};

#endif
