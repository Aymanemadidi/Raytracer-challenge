#include "header.h"

typedef float (Mat)[4];

int matrix_is_equal(float (*mat_a)[4], float (*mat_b)[4])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 4)
    {
        while (j < 4)
        {
            if (mat_a[i][j] != mat_b[i][j])
                return (0);
            j++;    
        }
        j = 0;
        i++;
    }
    return (1);
}


int main()
{
    float mat_a[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,8,7,6}, {5,4,3,2}};
    float mat_b[4][4] = {{-2,1,2,3}, {3,2,1,-1}, {4,3,6,5}, {1,2,7,8}};
    float mat_sys_r[4][4] = {{20,22,50,48}, {44,54,114,108}, {40,58,110,102}, {16,26,46,42}};

    /*Mat mat_r = */matrix_multiply(mat_a, mat_b);
    //printf("%d\n", matrix_is_equal(mat_r, mat_sys_r));

}