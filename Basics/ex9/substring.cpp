#include "substring.h"
#include <string.h>
#include <iostream>
using namespace std;

bool esSubString(char str[], char subStr[], int& posicio)
{
  
    
    
    bool Trobat = false;
    
    if(subStr[0] == ',')
    {
        cout << 4;
        cout << "SI";
    }
    
    else for (int i = 0; i < 20;i++)
                {
                    if (str[i] == subStr[0])
                        {
                         if (str[i+1] == subStr[1])
                            {
                             if (str[i+2] == subStr[2])
                             {
                    
                                Trobat = true;
                                posicio = i;

                                cout << posicio;
                                cout << endl;
                                cout << "SI";
                                cout << endl;
                        
                             }
                            }
                        }
        
                }
    if (Trobat == false)
    {
        cout << "NO";
    }

    return Trobat;
    
}