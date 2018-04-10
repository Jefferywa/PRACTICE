#include "files.h"

using namespace std;

bool checkFile(const char* file_name) 
{
    ifstream file;
    file.open(file_name);
    
    if(!file) {
        return 0;
    } else {
        file.close();
        return 1;
    }
}
