/**
 * Project Untitled
 */


#include "APhone.h"

/**
 * APhone implementation
 */


/**
 * @param phoneTitle
 */
APhone::APhone(string phoneTitle) : phoneTitle(phoneTitle) {
    
}

APhone::~APhone()
{

}

void APhone::Show() {
    cout << "Phone Title: " << this->phoneTitle << '\n';
}

string APhone::getPhoneName() {
    return this->phoneTitle;
}
