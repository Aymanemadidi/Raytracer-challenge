#include "header.h"

t_canva canva(float width, float height)
{
    t_canva canva;

    canva.width = width;
    canva.height = height;
    canva.color = color(0, 0, 0);

    return (canva);
}

t_pixel write_pixel(t_canva canva, float x, float y, t_color color)
{   
    t_pixel pix;

    pix.x = x;
    pix.y = y;
    pix.color = color;
    pix.canva = canva;

    return (pix);
}

t_pixel get_pixel(t_canva c, float x, float y)
{   
    t_pixel pix;
    pix.x = x;
    pix.y = y;
    pix.canva = c;
    return (pix);
}

t_color pixel_at(t_canva c, float x, float y)
{   
    return (get_pixel(c, x, y).color);
}
