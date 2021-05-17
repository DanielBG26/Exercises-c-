
#include "MultMatriu.h"

void multiplicaMatriu(int m1[N][N],int m2[N][N],int result[N][N])
{
    
    for(int i=0; i < N;i++)
    {
        for(int j=0; j <N;j++)
        {
            result[i][j] = (m1[i][0]*m2[0][j])+(m1[i][1]*m2[1][j])+(m1[i][2]*m2[2][j]);
        }
    }
}
