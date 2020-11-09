#include "header.h"
​
t_canva init_canva(float width, float height)
{
    t_canva result;
​
    result.width = width;
    result.height = height;
    result.img = (t_pixel *)malloc(sizeof(t_pixel) * width * height);
​
    return (result);
}
​
/*void fill_img(t_canva *canva)
{
    int i = 0;
    while (canva->img[0] != '\0')
    {
        canva->img->color = color(0, 0, 0);
        canva->img++; 
    }s
}*/
​
void write_pixel(t_canva *canva, float x, float y, t_color color)
{   
    canva->img[(int)((y * canva->width) + x)].color.red = color.red;
    canva->img[(int)((y * canva->width) + x)].color.green = color.green;
    canva->img[(int)((y * canva->width) + x)].color.blue = color.blue;
}
​
t_color pixel_at(t_canva canva, float x, float y)
{
    return (canva.img[(int)((y * canva.width) + x)].color);
}
