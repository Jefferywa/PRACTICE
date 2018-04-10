#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <ctime>
#include <locale>
#include "files.h"
#include "func.h"

using namespace std;

/*struct internetStore
{ 
    internetStore *prev;
    string title;
    string desc; 
    string price;
    string category;
    internetStore *next;
};

void sFile(internetStore *&first) 
{
    ofstream out("storage.txt");
    if(out) {
        internetStore *buf;
        buf = first;
        bool flag = true;
        while (buf != NULL) {
            int len;
            len = first->title.length();

            out.write((char*)&len, sizeof(len));
            if(!out) {
                flag = false;
            }

            if(flag)
                out.write(buf->title.c_str(), len);
            if(!out) {
                flag = false;
            }
            
            len = buf->desc.length();

            if(flag)
                out.write((char*)&len, sizeof(len));
            if(!out) {
                flag = false;
            }

            if(flag)
                out.write(buf->desc.c_str(), len);
            if(!out) {
                flag = false;
            }
            
            len = first->price.length();

            out.write((char*)&len, sizeof(len));
            if(!out) {
                flag = false;
            }

            if(flag)
                out.write(buf->price.c_str(), len);
            if(!out) {
                flag = false;
            }

            len = buf->category.length();

            out.write((char*)&len, sizeof(len));
            if(!out) {
                flag = false;
            }

            if(flag)
                out.write(buf->category.c_str(), len);
            if(!out) {
                flag = false;
            }

            buf = buf->next;
        }
    } else {
        cout << "ERROR: open file";
    }
}

void lFile(internetStore *&first, internetStore *&last)
{
    first = NULL;
    if(checkFile("storage.txt")) {
        internetStore *f;
        bool flag;
        flag = true;
        ifstream in("storage.txt");
        while((!in.eof())&&(flag)) {

            if (f = new internetStore) {
                int i, len;
                char chr;

                f->title = "";
                in.read((char *)&len, sizeof(len));

                if(!in) {
                    flag = false;
                }

                if((!in.eof())&&(flag)) {
                    for(i = 0; i < len; i++) 
                    {
                        in.read((char *)&chr, 1);
                        if(!in) {
                            flag = false;
                        } else {
                            f->title = f->title + chr;
                        }
                    }
                }
                   
                f->desc = "";
                in.read((char *)&len, sizeof(len));
                if(!in) {
                    flag = false;
                } else {
                    for(i = 0; i < len; i++) {
                        in.read((char *)&chr, 1);
                        f->desc = f->desc + chr;
                    }
                }
                
                f->price = "";
                in.read((char *)&len, sizeof(len));
                if(!in) {
                    flag = false;
                } else {
                    for(i = 0; i < len; i++) {
                        in.read((char *)&chr, 1);
                        f->price = f->price + chr;
                    }
                }

                f->category = "";
                in.read((char *)&len, sizeof(len));
                if(!in) {
                    flag = false;
                } else {
                    for(i = 0; i < len; i++) {
                        in.read((char *)&chr, 1);
                        f->category = f->category + chr;
                    }
                }

                if((!in.eof())&&(flag)) {
                    if(first == NULL) {
                        first = f;
                        last = first;
                    } else {
                        last->next = f;
                        f->prev = last;
                        last = last->next;
                    }
                    f->next = NULL;
                }
            } else { 
                cout << "ERROR: file memory access\n";
            }
        }
        if(!flag) {
            cout << "ERROR: read file\n";
        }
    }
}

void enterInfo(internetStore *&buff)
{
    cout << "Enter product name: ";
    getline(std::cin, buff->title);

    cout << "Enter product description: ";
    getline(std::cin, buff->desc);
    
    cout << "Enter the price of the product: ";
    getline(std::cin, buff->price);

    cout << "Enter product category: ";
    getline(std::cin, buff->category);

}

void addInfo(internetStore *&first, internetStore *&last)
{
    internetStore *buf = 0;
    buf = new internetStore;
    enterInfo(buf);
    if(first == NULL) {
        first = buf;
        last = first;
    } else {
        last->next = buf;
        buf->prev = last;
        last = last->next;
    }
    sFile(first);
}

int showInfo(internetStore *&first)
{
    internetStore *buf;
    int records = 0;
    buf = first;
    int i = 1;
    while (buf != NULL) {
        records++;
        cout << "[" << i << "] " << "[Product title: " << buf->title << "][Product desc: " << buf->desc << "][Product price:  " << buf->price << "][Product category: " << buf->category << "]";
        buf = buf->next;
        i++;
    }
    return records;
}

void deleteInfo(internetStore *&first, internetStore *&last)
{
    int records;
    bool end = false;
    records = showInfo(first);
    cout << "["<< records + 1 << "]Exit\n";
    bool flag;
    int number = 0;
    do {
        cout << "Records number: ";
        cin >> number;
        if(!cin) {
            flag = true;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            if(cin.get() != '\n') {
                flag = true;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                if(number < 1 || number > records) {
                    if(number = records = 1) {
                        end = true;
                        flag = false;
                    } else {
                        flag = true;
                        cout << "Bad enter!\n";
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                } else flag = false;
            }
        }
    } while(flag);
    if(!end) {
        int i;
        internetStore *f = first;
        for(i = 1; i < number; i++) {
            f = f->next;
        }
        if(f->prev != NULL) {
            f->prev->next = f->next;
        }
        if(f->next != NULL) {
            f->next->prev = f->prev;
        }
        if(f == first) {
            first = f->next;
        }
        if(f == last) {
            last = f->prev;
        }
        delete f;
        sFile(first);
    }
}

void editInfo(internetStore *&first)
{
    int records;
    bool end = false;
    records = showInfo(first);
    cout << "["<<records + 1 << "]Exit\n";
    bool flag;
    int number = 0;
    do {
        cout << "Record's number: ";
        cin >> number;
        if(!cin) {
            flag = true;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            if(cin.get() != '\n') {
                flag = true;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                if(number < 1 || number > records) {
                    if(number == records + 1) {
                        end = true;
                        flag = false;
                    } else {
                        flag = true;
                        cout << "Bad enter!\n";
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                } else flag = false;
            }
        }
    } while(flag);
    if(!end) {
        int i;
        internetStore *f = first;
        for(i = 1; i < number; i++) {
            f = f->next;
        }
        enterInfo(f);
    }
    sFile(first);
}*/


int main() {
    internetStore *first = NULL, *last = NULL;
    lFile(first, last);
    bool exit = false;
    last = first;
    while(not exit) {
        cout << "\nINTERNET STORE DATABASE\n";
        cout << "Select action \n";
        cout << "1) Add new product\n";
        cout << "2) Show products\n";
        cout << "3) Edit product\n";
        cout << "4) Delete product\n";
        cout << "5) Exit\n";
        int buf;
        if((buf = cin.get()) != EOF) {
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            if(buf != '\n') {
                switch(buf) {
                    case '1': cout << "ADD NEW PRODUCT\n"; addInfo(first, last); break;
                    case '2': cout << "SHOW PRODUCTS\n"; showInfo(first); break;
                    case '3': cout << "EDIT PRODUCT\n"; editInfo(first); break;
                    case '4': cout << "DELETE PRODUCT\n"; deleteInfo(first, last); break;
                    case '5': cout << "EXIT\n"; exit = true; break;
                    default: cout << "ERROR\n"; break;
                }
            }
        }
    }
    delete(first);
}
