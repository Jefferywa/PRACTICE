/**
 * Project Untitled
 */


#ifndef _CPHONE_H
#define _CPHONE_H

#include "APhone.h"


class CPhone: public APhone {
public: 
    
    /**
     * @param phoneTitle
     * @param browser
     */
    void CPhone(string phoneTitle, bool browser);
private: 
    void browser;
};

#endif //_CPHONE_H