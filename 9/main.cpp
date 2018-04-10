#include <iostream>
#include <vector>
#include <string>
#include "Phone.h"

using namespace std;

int main() {
    string obj_name;
    string obj_os;
    bool obj_browser;
    int obj_type;
    int P = 2;
    Model *arr[P];

    for(int i = 0; i < P; i++) {
        cout << "Adding Tea entities\n";
        cout << "Enter name: ";
        cin >> obj_name;
        cout << "\nEnter os: ";
        cin >> obj_os;
        cout << "\nEnter browser: ";
        cin >> obj_browser;
        cout << "\nEnter type: ";
        cin >> obj_type;
        Model *Phone_Model = new Phone(obj_name, obj_os, obj_browser, obj_type);
        arr[i] = Phone_Model;
    }

    for(int i = 0; i < P; i++) {
        if(arr[i]->getWeight() <= 150) {
            cout << "\nTea entities with weight <= 150: \n";
            arr[i]->Show();
        }
    }

    for(int i = 0; i < P; i++) {
        delete arr[i];
    }

    return 0;







}