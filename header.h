#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define EPSILON 0.00001

typedef int (*Mat)[4];
typedef int (*Mat3)[3];
typedef int (*Mat2)[2];

typedef struct s_rgb_color
{
    int red;
    int green;
    int blue;
} t_rgb_color;

typedef struct s_color
{
    float red;
    float green;
    float blue;
} t_color;

typedef struct s_pixel
{
    t_color color;
} t_pixel;

typedef struct s_canva
{
    int width;
    int height;
    t_pixel *img;
} t_canvas;

typedef struct s_tuple
{
    float x;
    float y;
    float z;
    float w;
} tuple;

/*t_canvasss init_canvasss(int width, int height)
{
    t_canvass result;
    
    result.width = width;
    result.height = height;
    result.img = (t_pixel *)malloc(sizeof(t_pixel) * width * height);
}*/


typedef struct s_projectile
{
    tuple position;
    tuple velocity;

} t_projectile;

typedef struct s_envir
{
    tuple gravity;
    tuple wind;

} t_envir;

int is_vec(tuple t);
int is_point(tuple t);
int	ft_strlen(const char *str);
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
t_color pixel_at(t_canvas c, float x, float y);
t_pixel get_pixel(t_canvas c, float x, float y);
void write_pixel(t_canvas *canva, int x, int y, t_color color);
void    same_color_canva(t_canvas *canva, t_color color);
t_canvas init_canva(float width, float height);
int colors_are_equal(t_color c1, t_color c2);
void ppm_second(int *fd, t_canvas canva);
int    *construct_ppm(t_canvas canva);
void display3(int result[][3]);
void display2(int **result);
Mat3 submatrix4(int matrix[][4], int row, int column);
int** submatrix3(int matrix[][3], int row, int column);
int minor3(int matrix[][3], int row, int column);

