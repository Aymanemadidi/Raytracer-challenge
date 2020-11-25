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

int **scaling(int x, int y, int z)
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
            result[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    result[0][0] = x;
    result[1][1] = y;
    result[2][2] = z;
    result[3][3] = 1;
    display(result);
    return (result);
}

float **rotation_x(double r)
{
    int i;
    int j;
    float **result;

    i = 0;
    j = 0;
    result = (float **)malloc(4 * sizeof(float *));
    while (i < 4)
    {
        result[i] = (float *)malloc(4 * sizeof(float));
        i++;
    }    
    i = 0;
    while (i < 4)
    {
        while (j < 4)
        {   
            result[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    result[0][0] = 1;
    result[1][1] = cos(r);
    result[1][2] = -sin(r);
    result[2][2] = cos(r);
    result[2][1] = sin(r);
    result[3][3] = 1;
    displayInv(result);
    return (result);
}

float **rotation_y(double r)
{
    int i;
    int j;
    float **result;

    i = 0;
    j = 0;
    result = (float **)malloc(4 * sizeof(float *));
    while (i < 4)
    {
        result[i] = (float *)malloc(4 * sizeof(float));
        i++;
    }    
    i = 0;
    while (i < 4)
    {
        while (j < 4)
        {   
            result[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    result[0][0] = cos(r);
    result[0][2] = sin(r);
    result[2][0] = -sin(r);
    result[2][2] = cos(r);
    result[1][1] = 1;
    result[3][3] = 1;
    displayInv(result);
    return (result);
}

float **rotation_z(double r)
{
    int i;
    int j;
    float **result;

    i = 0;
    j = 0;
    result = (float **)malloc(4 * sizeof(float *));
    while (i < 4)
    {
        result[i] = (float *)malloc(4 * sizeof(float));
        i++;
    }    
    i = 0;
    while (i < 4)
    {
        while (j < 4)
        {   
            result[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    result[0][0] = cos(r);
    result[1][0] = sin(r);
    result[0][1] = -sin(r);
    result[1][1] = cos(r);
    result[2][2] = 1;
    result[3][3] = 1;
    displayInv(result);
    return (result);
}

float**shearing(t_shear s)
{
    int i;
    int j;
    float **result;

    i = 0;
    j = 0;
    result = (float **)malloc(4 * sizeof(float *));
    while (i < 4)
    {
        result[i] = (float *)malloc(4 * sizeof(float));
        i++;
    }    
    i = 0;
    while (i < 4)
    {
        while (j < 4)
        {   
            if (i == j)
                result[i][j] = 1;
            else    
                result[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    result[0][1] = s.x_y;
    result[0][2] = s.x_z;
    result[1][0] = s.y_x;
    result[1][2] = s.y_z;
    result[2][0] = s.z_x;
    result[2][1] = s.z_y;
    displayInv(result);
    return (result);
}