#include "header.h"

int **translation(int x, int y, int z)
{
    int i;
    int j;
    int **result;

    i = 0;
    j = 0;
    result = (int **)malloc(4 * sizeof(int *));
    while (i < 4)
    {
        result[i] = (int *)malloc(4 * sizeof(int));
        i++;
    }
        
    i = 0;
    while (i < 4)
    {
        while (j < 4)
        {   
            if (i == j)
               result[i][j] = 1;
            else if (j == 3)
                if (i == 0)
                    result[i][j] = x;
                else if (i == 1)
                    result[i][j] = y;
                else if (i == 2)
                    result[i][j] = z;
            else                   
                result[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    display(result);
    return (result);
}