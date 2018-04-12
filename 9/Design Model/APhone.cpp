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
void APhone::APhone(String phoneTitle) : phoneTitle(phoneTitle) {
    
}

APhone::~APhone()
{

}


virtual void APhone::Show() {
    cout << "Phone Title: " << this->phoneTitle << '\n';
}

void APhone::getPhoneName() {
    return this->phoneTitle;
}