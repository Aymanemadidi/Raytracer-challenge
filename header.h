#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define EPSILON 0.00001
#define M_PI 3.14159265358979323846

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

typedef struct s_ray
{
    tuple origin;
    tuple direction;
} t_ray;

typedef struct s_material
{
    t_color color;
    float ambient;
    float diffuse;
    float specular;
    float shiness;
} t_material;

typedef struct s_sphere
{
    int id;
    int radius;
    float **transform;
    tuple origin;
    t_material m;
} t_sphere;

typedef struct s_intersection
{
    float t;
    int object_id;
    //int defined;
} t_intersection;

typedef struct s_light
{
    tuple position;
    t_color intensity;
} t_light;

typedef struct s_world
{   
    t_light light;
    t_sphere *arr;
    t_sphere s3;
} t_world;


/*t_canvasss init_canvasss(int width, int height)
{
    t_canvass result;
    
    result.width = width;
    result.height = height;
    result.img = (t_pixel *)malloc(sizeof(t_pixel) * width * height);
}*/


/*typedef struct s_projectile
{
    tuple position;
    tuple velocity;

} t_projectile;

typedef struct s_envir
{
    tuple gravity;
    tuple wind;

} t_envir;*/

typedef struct s_shear
{
    float x_y;
    float x_z;
    float y_x;
    float y_z;
    float z_x;
    float z_y;
} t_shear;

int is_vec(tuple t);
int is_point(tuple t);
int	ft_strlen(const char *str);
tuple vector(float x, float y, float z);
tuple point(float x, float y, float z);
int is_equal(float x, float y);
int a_less_b(float a, float b);
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
void write_pixel2(t_canvas *canva, float x, float y, t_color color);
void    same_color_canva(t_canvas *canva, t_color color);
t_canvas init_canva(float width, float height);
int colors_are_equal(t_color c1, t_color c2);
void ppm_second(int *fd, t_canvas canva);
int    *construct_ppm(t_canvas canva);
void display3(int **result);
void display2(int **result);
void displayInv(float **result);
void display(int **result);
float** init_matrix(float arr[16]);
float** submatrix4(float **matrix, int row, int column);
int** submatrix3(float **matrix, int row, int column);
float minor3(float **matrix, int row, int column);
float cofactor3(float** matrix, int row, int column);
float determinant(float **m);
float determinant3(float **m);
float** transpose_matrix(float **buff);
float **inverse(float **matrix);
float cofactor4(float **matrix, int row, int column);
float **translation(float x, float y, float z);
float **scaling(float x, float y, float z);
float **rotation_x(double r);
float **rotation_y(double r);
float **rotation_z(double r);
float **shearing(t_shear s);
float** identity_matrix();
tuple mat_tuple(float** m, tuple t);
tuple mat_tuple_float(float **m, tuple t);
t_ray transform(t_ray r, float **trans_matrix);
void set_transform(t_sphere *s, float **trans_matrix);
t_ray ray(tuple origin, tuple direction);
tuple posit(t_ray ray, float t);
t_sphere sphere(int id);
t_intersection hit(t_intersection *xs);
t_intersection* intersect(t_sphere s, t_ray ray);
t_intersection intersection(float t, int object_id);
float cal_delta(t_ray *ray, t_sphere *s);
tuple normal_at(t_sphere s, tuple p);
tuple reflect(tuple in, tuple normal);
t_light point_light(tuple position, t_color intensity);
t_material material();
t_color lightning(t_material m, t_light l, tuple point, tuple eyev, tuple normalv);


