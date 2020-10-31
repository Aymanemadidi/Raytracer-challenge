#include "header.h"

int is_vec(tuple t)
{
    if (t.w == 0.0)
        return (TRUE);
    return (FALSE);  
}

int is_point(tuple t)
{
    if (t.w == 1.0)
        return (TRUE);
    return (FALSE);  
}

tuple vector(float x, float y, float z)
{   
    tuple vect;

    vect.x = x;
    vect.y = y;
    vect.z = z;
    vect.w = 0.0;

    return (vect);
}

tuple point(float x, float y, float z)
{   
    tuple point;

    point.x = x;
    point.y = y;
    point.z = z;
    point.w = 1.0;

    return (point);
}