#include "header.h"

t_color color(float x, float y, float z)
{
    t_color c;

    if (x > 1)
        c.red = 1;
    else if (x < 0)
        c.red = 0;
    else
        c.red = x;

    if (y > 1)
        c.green = 1;
    else if (y < 0)
        c.green = 0;
    else
        c.green = y;

    if (z > 1)
        c.blue = 1;
    else if (z < 0)
        c.blue = 0;
    else
        c.blue = z;                

    return (c);
}

t_color add_colors(t_color c1, t_color c2)
{
    t_color c_sum;

    c_sum.red = c1.red + c2.red;
    c_sum.green = c1.green + c2.green;
    c_sum.blue = c1.blue + c2.blue;

    return (c_sum);
}

t_color sub_colors(t_color c1, t_color c2)
{
    t_color c_sum;

    c_sum.red = c1.red - c2.red;
    c_sum.green = c1.green - c2.green;
    c_sum.blue = c1.blue - c2.blue;

    return (c_sum);
}

t_color scalar_color(float a, t_color c)
{
    c.red *= a;
    c.green *= a;
    c.blue *= a;

    return (c);
}

t_color mult_color(t_color c1, t_color c2)
{   
    t_color c_mult;

    c_mult.red = c1.red * c2.red;
    c_mult.green = c1.green * c2.green;
    c_mult.blue = c1.blue * c2.blue;

    return (c_mult);
}

int colors_are_equal(t_color c1, t_color c2)
{
    if (c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue)
        return (TRUE);
    else
        return (FALSE);
        
}