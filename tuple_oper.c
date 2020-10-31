#include "header.h"

tuple add_tuples(tuple t1, tuple t2)
{
    tuple t_sum;

    t_sum.x = t1.x + t2.x;
    t_sum.y = t1.y + t2.y;
    t_sum.z = t1.z + t2.z;
    if (t1.w == 1.0 && t2.w == 1.0)
        t_sum.w = 0.0;
    else
        t_sum.w = t1.w + t2.w;

    return (t_sum);
}

tuple substract_tuples(tuple t1, tuple t2)
{
    tuple t_sub;

    t_sub.x = t1.x - t2.x;
    t_sub.y = t1.y - t2.y;
    t_sub.z = t1.z - t2.z;
    if (t1.w == 0.0 && t2.w == 1.0)
        t_sub.w = 1.0;
    else    
        t_sub.w = t1.w - t2.w;

    return (t_sub);
}

tuple opposite_tuple(tuple t)
{
    t.x *= -1;
    t.y *= -1;
    t.z *= -1;
    t.w *= -1;

    return (t);
}

tuple scalar_multiply(float a, tuple t)
{
    t.x *= a;
    t.y *= a;
    t.z *= a;
    t.w *= a;

    return (t);
}

tuple scalar_divide(float a, tuple t)
{
    t.x /= a;
    t.y /= a;
    t.z /= a;
    t.w /= a;

    return (t);
}