/**
 * Project Untitled
 */


#ifndef _BPHONE_H
#define _BPHONE_H

#include "APhone.h"


class BPhone: public APhone {
public: 
    BPhone(String phoneTitle, string phoneOS);
    string getPhoneOS();

    void Show() override;
private: 
    void phoneOS;
};

#endif //_BPHONE_H