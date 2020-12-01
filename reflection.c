#include "header.h"

t_light point_light(tuple position, t_color intensity)
{
    t_light light;

    light.position = position;
    light.intensity = intensity;
    return (light);
}

t_material material()
{
    t_material m;

    m.color = color(1, 1, 1);
    m.ambient = 0.1;
    m.diffuse = 0.9;
    m.specular = 0.9;
    m.shiness = 200;

    return (m);
}

t_color lightning(t_material m, t_light l, tuple point, tuple eyev, tuple normalv)
{
    t_color effective_color;
    tuple lightv;
    t_color ambient;
    t_color diffuse;
    t_color specular;
    tuple reflectv;

    float light_dot_normal;
    float reflect_dot_eye;
    double factor;

    effective_color = mult_color(m.color, l.intensity);
    lightv = normalise_vec(substract_tuples(l.position, point));
    ambient = scalar_color(m.ambient, effective_color);
    light_dot_normal = scalar_product(lightv, normalv);
    if (light_dot_normal < 0)
    {
        diffuse = color(0, 0, 0);
        specular = color(0, 0, 0);
    }
    else
    {
        diffuse = scalar_color(m.diffuse * light_dot_normal, effective_color);

        reflectv = reflect(scalar_multiply(-1, lightv), normalv);
        reflect_dot_eye = scalar_product(reflectv, eyev);
        if (reflect_dot_eye <= 0)
            specular = color(0, 0, 0);
        else
        {
            factor = pow((double)reflect_dot_eye, (double)m.shiness);
            specular = scalar_color(factor * m.specular, l.intensity);
        }   
    }
    return (add_colors(add_colors(ambient, diffuse), specular));
}

/*int main()
{
    t_material m;
    tuple position;
    tuple eyev;
    tuple normalv;
    t_light light;
    t_color result;

    m = material();
    position = point(0, 0, 0);
//--test1--

 /*   eyev = vector(0, 0, -1);
    normalv = vector(0, 0, -1);
    light = point_light(point(0, 0, -10), color(1, 1, 1));
    result = lightning(m, light, position, eyev, normalv);
    printf("red: %f\n", result.red);
    printf("green: %f\n", result.green);
    printf("blue: %f\n", result.blue);*/

//--test2--
/*    eyev = vector(0, sqrt(2)/2, -1 * sqrt(2)/2);
    normalv = vector(0, 0, -1);
    light = point_light(point(0, 0, -10), color(1, 1, 1));
    result = lightning(m, light, position, eyev, normalv);
    printf("red: %f\n", result.red);
    printf("green: %f\n", result.green);
    printf("blue: %f\n", result.blue);*/

//--test3--
/*  eyev = vector(0, 0, -1);
    normalv = vector(0, 0, -1);
    light = point_light(point(0, 10, -10), color(1, 1, 1));
    result = lightning(m, light, position, eyev, normalv);
    printf("red: %f\n", result.red);
    printf("green: %f\n", result.green);
    printf("blue: %f\n", result.blue);*/

//--test4--
/*  eyev = vector(0, -1 * sqrt(2)/2, -1 * sqrt(2)/2);
    normalv = vector(0, 0, -1);
    light = point_light(point(0, 10, -10), color(1, 1, 1));
    result = lightning(m, light, position, eyev, normalv);
    printf("red: %f\n", result.red);
    printf("green: %f\n", result.green);
    printf("blue: %f\n", result.blue);

//--test5--
    eyev = vector(0, 0, -1);
    normalv = vector(0, 0, -1);
    light = point_light(point(0, 0, 10), color(1, 1, 1));
    result = lightning(m, light, position, eyev, normalv);
    printf("red: %f\n", result.red);
    printf("green: %f\n", result.green);
    printf("blue: %f\n", result.blue);      

}*/