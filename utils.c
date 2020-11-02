#include "header.h"

float ft_abs(float x)
{
    if (x < 0)
        x *= -1;
    return (x);    
}

int is_equal(float x, float y)
{
    if (ft_abs(x - y) < EPSILON)
        return (TRUE);
    else
        return (FALSE);
        
}

int tuples_are_equal(tuple t1, tuple t2)
{
    if (t1.x == t2.x && t1.y == t2.y && t1.z == t2.z && t1.w == t2.w)
        return (TRUE);
    else
        return (FALSE);
        
}