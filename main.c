#include "header.h"

int is_vec(tuple t);
int is_point(tuple t);

int main()
{
    /*tuple vec1;
    tuple point1;

    vec1.x = 5.0;
    vec1.y = 10.0;
    vec1.z = 2.0;
    vec1.w = 0.0;

    point1.x = 6.0;
    point1.y = 8.0;
    point1.z = 5.0;
    point1.w = 1.0;

    if (is_vec(vec1))
        printf("Test1 Passed\n");
    if (is_vec(point1))    
        printf("This should not pass\n");
    if (is_point(point1))
        printf("Test2 Passed\n");
    if (is_point(vec1))    
        printf("This should not pass\n");
    tuple vec2;
    tuple point2;

    vec2 = vector(1.0, 3.0, 4.0);
    point2 = point(4.0, 8.0, 7.0);

    if (vec2.w == 0.0)
        printf("Test3 Passed\n");
    if (point2.w == 1.0)
        printf("Test4 Passed\n");
    tuple sum_p;
    tuple vec3;
    sum_p = add_tuples(point1, point2);
    vec3 = vector(10.0, 16.0, 12.0);


//---Equality Test------

    if (tuples_are_equal(sum_p, vec3))
        printf("Equality test passed\n");
    else    
        printf("Equality test NOT passed\n");

//---Magnitude Test------

    float mag_vec3;
    mag_vec3 = sqrt((10.0 * 10.0) + 
    (16.0 * 16.0) + (12.0 * 12.0));

    if (vec_magnitude(vec3) == mag_vec3)
        printf("Magnitude Test Passed\n");
    else
        printf("Magnitude Test NOT Passed");

//----Produit Scalaire Test------
    tuple vec4 = vector(1, 2, 3);    
    tuple vec5 = vector(2, 3, 4);

    float scalair_prod = 20.0;
    if (scalar_product(vec4, vec5) == scalair_prod)
        printf("Scalar Product Test Passed\n");*/

    //----------Pixel_at Test-------------
    
    t_canva	canvas;
    t_color	red = color(1, 0, 0);
    //t_pixel *ptr1;
    //t_color red = color (1, 0, 0);
    //t_color out_color;
    //int i = 0;

    canvas = init_canva(10, 20);
    write_pixel(&canvas, 2, 3, red);
    t_color result_color = pixel_at(canvas, 2, 3);
    printf("red = %f\tgreen = %f\tblue = %f\n", result_color.red, result_color.green, result_color.blue);
    //ptr1 = canva_ptr->img;
    //write_pixel(canva_ptr, 2, 3, red);
    //canva_ptr.color = red;

    //red = color(1, 0, 0);

    /*printf("%f\n", canva_ptr->img[32].color.red);
    printf("%f\n", canva_ptr->img[32].color.green);
    printf("%f\n", canva_ptr->img[32].color.blue);*/
}