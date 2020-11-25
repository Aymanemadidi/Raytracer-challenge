#include "header.h"

t_canvas init_canva(float width, float height)
{
    t_canvas result;

    result.width = width;
    result.height = height;
    result.img = (t_pixel *)malloc(sizeof(t_pixel) * width * height);

    return (result);
}

void    same_color_canva(t_canvas *canva, t_color color)
{   
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < canva->width) //5
    {
        while (j < canva->height)//4 => 0,1,2,3
        {
            write_pixel(canva, i, j, color);
            j++;
        }
        j = 0;
        i++;
    }
    //printf("color: %f\n", pixel_at(*canva, 0, 3).red);
}

/*void fill_img(t_canva *canva)
{
    int i = 0;
    while (canva->img[0] != '\0')
    {
        canva->img->color = color(0, 0, 0);
        canva->img++; 
    }
}*/

void write_pixel(t_canvas *canva, int x, int y, t_color color)
{   
    canva->img[(int)((y * canva->width) + x)].color.red = color.red;
    //printf("write red: %f\n", canva->img->color.red);
    canva->img[(int)((y * canva->width) + x)].color.green = color.green;
    canva->img[(int)((y * canva->width) + x)].color.blue = color.blue;
}

void write_pixel2(t_canvas *canva, float x, float y, t_color color)
{   
    canva->img[(int)((40 * y * (canva->width) + 40 * x + (canva->width * (5 + canva->height))/2))/*/2)) + x + canva->width/2 * canva->height/2) + 6000*/].color.red = color.red;
    //printf("write red: %f\n", canva->img->color.red);
    canva->img[(int)((40 * y * (canva->width) + 40 * x + (canva->width * (5 + canva->height))/2))/*/2)) + x + canva->width/2 * canva->height/2) + 6000*/].color.green = color.green;
    canva->img[(int)((40 * y * (canva->width) + 40 * x + (canva->width * (5 + canva->height))/2))/*/2)) + x + canva->width/2 * canva->height/2) + 6000*/].color.blue = color.blue;
}

t_color pixel_at(t_canvas canva, float x, float y)
{
    return (canva.img[(int)((y * canva.width) + x)].color);
}
