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
    APhone(String phoneTitle);
    virtual ~APhone();
    
    string getPhoneName();

    virtual void show() = 0;
private: 
    string phoneTitle;
};

#endif //_APHONE_H