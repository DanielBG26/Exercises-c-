#include <iostream>
#include "substring.h"

using namespace std;

int main()
{
    char str[MAX_STRING];
    char subStr[MAX_STRING];
    int posicio;
    

    cin.getline(str, MAX_STRING, '\n');
    cout << endl;
    cin.getline(subStr, MAX_STRING, '\n');;
    

    esSubString(str, subStr, posicio);
    
    return 0;

}