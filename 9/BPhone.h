/**
 * Project Untitled
 */


#ifndef _BPHONE_H
#define _BPHONE_H

#include "APhone.h"


class BPhone: public APhone {
public: 
    BPhone(string phoneTitle, string phoneOS = "");
    string getPhoneOS();

    void Show() override;
private:
    string phoneOS;
};

#endif //_BPHONE_H