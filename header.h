#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
​
#define TRUE 1
#define FALSE 0
#define EPSILON 0.00001
​
typedef struct s_color
{
    float red;
    float green;
    float blue;
} t_color;
​
typedef struct s_pixel
{
    t_color color;
} t_pixel;
​
typedef struct s_canva
{
    float width;
    float height;
    t_pixel *img;
} t_canva;
​
typedef struct s_tuple
{
    float x;
    float y;
    float z;
    float w;
} tuple;
​
/*t_canvass init_canvass(int width, int height)
{
    t_canvas result;
    
    result.width = width;
    result.height = height;
    result.img = (t_pixel *)malloc(sizeof(t_pixel) * width * height);
}*/
​
​
/*typedef struct s_projectile
{
    tuple position;
    tuple velocity;
​
} t_projectile;
​
typedef struct s_envir
{
    tuple gravity;
    tuple wind;
​
} t_envir;*/
int is_vec(tuple t);
int is_point(tuple t);
tuple vector(float x, float y, float z);
tuple point(float x, float y, float z);
int is_equal(float x, float y);
float ft_abs(float x);
tuple add_tuples(tuple t1, tuple t2);
tuple substract_tuples(tuple t1, tuple t2);
int tuples_are_equal(tuple t1, tuple t2);
tuple opposite_tuple(tuple t);
tuple scalar_multiply(float a, tuple t);
tuple scalar_divide(float a, tuple t);
float vec_magnitude(tuple t);
tuple normalise_vec(tuple t);
float scalar_product(tuple v1, tuple v2);
tuple cross_product(tuple v1, tuple v2);
t_color color(float x, float y, float z);
t_color add_colors(t_color c1, t_color c2);
t_color sub_colors(t_color c1, t_color c2);
t_color scalar_color(float a, t_color c);
t_color mult_color(t_color c1, t_color c2);
t_color pixel_at(t_canva c, float x, float y);
t_pixel get_pixel(t_canva c, float x, float y);
void write_pixel(t_canva *canva, float x, float y, t_color color);
t_canva init_canva(float width, float height);
int colors_are_equal(t_color c1, t_color c2);