/**
 * Project Untitled
 */


#include "BPhone.h"

/**
 * BPhone implementation
 */


/**
 * @param phoneTitle
 * @param phoneOS
 */
BPhone::BPhone(String phoneTitle, string phoneOS) 
    : APhone(phoneTitle), phoneOS(phoneOS) {

}

int BPhone::getPhoneOS() {
    return this->phoneOS;
}

void BPhone::Show() {
    APhone::Show();
    cout << "Phone OS: " << this->phoneOS << '\n';
}