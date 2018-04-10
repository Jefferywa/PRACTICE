#ifndef FILEDB_FUNC_H
#define FILEDB_FUNC_H

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "files.h"

struct internetStore
{
    internetStore *prev;
    std::string title;
    std::string desc;
    std::string price;
    std::string category;
    internetStore *next;
};

void sFile(internetStore *&first);
void lFile(internetStore *&first, internetStore *&last);
void enterInfo(internetStore *&buff);
void addInfo(internetStore *&first, internetStore *&last);
int showInfo(internetStore *&first);
void deleteInfo(internetStore *&first, internetStore *&last);
void editInfo(internetStore *&first);

#endif
