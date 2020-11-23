#include "header.h"

void display3(int **result) {

   printf("\nOutput subMatrix:\n");
   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
         printf("%d  ", result[i][j]);
         if (j == 2)
            printf("\n");
      }
   }
}

void display2(int **result) {

   printf("\nOutput subMatrix:\n");
   for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
         printf("%d  ", result[i][j]);
         if (j == 1)
            printf("\n");
      }
   }
}

int det2x2(int **mat)
{
    
    return (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);
}

Mat3 submatrix4(int matrix[][4], int row, int column)
{   
    int i;
    int j;
    int k;
    int l;
    int **result = (int **)malloc(3 * sizeof(int *)); 
    for (i = 0; i < 3; i++) 
        result[i] = (int *)malloc(3 * sizeof(int));

    i = 0;
    j = 0;
    k = 0;
    l = 0;
    while (i < 3)
    {   
        if (k == row)
            k++;
        while (j < 3)
        {   
            if (l == column)
                l++;
            result[i][j] = matrix[k][l];   
            j++;
            l++;   
        }
        j = 0;
        l = 0;
        i++;
        k++;
    }
    display3(result);
}

int** submatrix3(int matrix[][3], int row, int column)
{   
    printf("here");
    int i;
    int j;
    int k;
    int l;
    int **result = (int **)malloc(2 * sizeof(int *)); 
    for (i = 0; i < 2; i++) 
         result[i] = (int *)malloc(2 * sizeof(int));

    i = 0;
    j = 0;
    k = 0;
    l = 0;
    while (i < 2)
    {   
        if (k == row)
            k++;
        while (j < 2)
        {   
            if (l == column)
                l++;
            result[i][j] = matrix[k][l];   
            j++;
            l++;   
        }
        j = 0;
        l = 0;
        i++;
        k++;
    }
    display2(result);
    return (result);
}

int minor3(int matrix[][3], int row, int column)
{
    //int submatrix[2][2] = submatrix3(matrix, row, column);
    int minor = det2x2(submatrix3(matrix, row, column));
    printf("minor: %d\n", minor);
    return (0);
}

int cofactor3(int matrix[][3], int row, int column)
{
    //int submatrix[2][2] = submatrix3(matrix, row, column);
    int minor;
    int cofactor;

    minor = det2x2(submatrix3(matrix, row, column));
    cofactor = 0;
    if((row + column) % 2 == 0)
        cofactor = minor;
    else
        cofactor = -1 * minor;
    printf("cofactor: %d\n", cofactor);
    return (0);
}