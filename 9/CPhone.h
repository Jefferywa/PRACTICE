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
	CPhone(string phoneTitle, bool browser);
    bool getBrowser();
	void Show();

  private: 
    bool browser;
};

#endif //_CPHONE_H
