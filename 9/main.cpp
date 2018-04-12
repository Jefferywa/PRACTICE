#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "APhone.h"
#include "BPhone.h"
#include "CPhone.h"

using namespace std;

int main()
{
    vector<APhone*> phones;
    string phoneTitle;
    int input = -1, sub_input = -1;

    do {
        cout << "[1] => Add phone"           << '\n';
        cout << "[2] => View all phone"     << '\n';
        cout << "[3] => View phone with name *Nokia" << '\n';
        cout << "[0] => Exit"                  << '\n';
        cout << '\n' << ":>";
        cin >> input;

        if (cin.good()) {

            system("cls");
            switch (input) {
                case 1: {

                    cout << "Enter phone title: ";
                    cin >> phoneTitle;

                    cout << "Choose phone type for create: " << '\n';
                    cout << "[1] => Teacher with browser" << '\n';
                    cout << "[2] => Teacher without browser"   << '\n';
                    cout << "[0] => Back"                      << '\n';
                    cin >> sub_input;

                    do {

                        if (cin.good()) {

                            switch (sub_input) {
                                case 1: {
                                    string phoneOS;
                                    cout << "Enter phone os: ";
                                    cin >> phoneOS;

                                    phones.push_back(
                                        new BPhone(phoneTitle, phoneOS)
                                    );
                                } break;
                                case 2: {
                                    bool browser;
                                    cout << "Enter broswer available (true/false): ";
                                    cin >> browser;

                                    phones.push_back(
                                        new CPhone(phoneTitle, browser)
                                    );
                                } break;
                            }

                            sub_input = 0;
                        }  else if (cin.fail()) {
                            cin.clear();
                            cin.sync();
                            sub_input = -1;
                        } else if (cin.bad()) {
                            cerr << "Fatal error. Standard input stream is broken" << '\n';
                        }

                    } while (sub_input != 0);

                    system("cls");
                } break;
                case 2: {
                    if (!phones.empty()) {
                        unsigned int number = 0;
                        for (APhone *i : phones) {
                            if (i != nullptr) {
                                cout << "Phone: " << number << '\n';
                                i->Show();
                                cout << setfill('-') << setw(50) << '\n';
                            } else {
                                cerr << "Pointer: " << number << " in [phones] array  is null" << '\n';
                            }
                            number++;
                        }
                    } else {
                        cout << "Phones not found" << '\n';
                    }
                    system("pause");
                } break;
                case 3: {
                    if (!phones.empty()) {
                        unsigned int number = 0;
                        for (APhone *i : phones) {
                            if (i != nullptr) {
								if (i->getPhoneName()[0] == 'A' || i->getPhoneName()[0] == 'a')
                                {
                                    cout << "Phones: " << number << '\n';
                                    i->Show();
                                    cout << setfill('-') << setw(50) << '\n';
                                }
                            } else {
                                cerr << "Pointer: " << number << " in [phones] array  is null" << '\n';
                            }
                            number++;
                        }
                    } else {
                        cout << "Phones not found" << '\n';
                    }
                    system("pause");
                } break;
            }

        } else if (cin.fail()) {
            cin.clear();
            cin.sync();
            input = -1;
        } else if (cin.bad()) {
            cerr << "Fatal error. Standard input stream is broken" << '\n';
        }

        system("cls");
    } while(input != 0);

    try
    {
        if (!phones.empty()) {
            unsigned int number = 0;
            for (APhone *i : phones) {
                if (i != nullptr) {
                    delete i;
                } else {
                    cerr << "Pointer: " << number << " in [Phones] array  is null" << '\n';
                }
                number++;
            }
        }
    } catch (out_of_range &e) {
        cerr << e.what() << '\n';
    }

}
