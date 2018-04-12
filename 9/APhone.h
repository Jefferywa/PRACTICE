/**
 * Project Untitled
 */


#ifndef _APHONE_H
#define _APHONE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class APhone {
public: 
    APhone(string phoneTitle);
    virtual ~APhone();
    
    string getPhoneName();

    virtual void Show() = 0;
private: 
    string phoneTitle;
};

#endif //_APHONE_H