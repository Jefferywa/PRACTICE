/**
 * Project Untitled
 */


#include "CPhone.h"

/**
 * CPhone implementation
 */


/**
 * @param phoneTitle
 * @param browser
 */
CPhone::CPhone(string phoneTitle, bool browser) 
: APhone(phoneTitle), browser(browser) {

}

bool CPhone::getBrowser() {
    return this->browser;
}

void CPhone::Show() {
    APhone::Show();
    cout << "Phone Browser: " << this->browser << '\n';
}
