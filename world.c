#include "header.h"

t_world world()
{
    t_world w;

    return (w);
}

t_world default_world()
{
    t_world w;
    t_light light;
    t_sphere s1;
    t_sphere s2;

    light = point_light(point(-10, 10, -10), color(1, 1, 1));
    s1 = sphere(1);
    s2 = sphere(2);
    s1.m.color = color(0.8, 1.0, 0.6);
    s1.m.diffuse = 0.7;
    s1.m.specular = 0.2;
    s1.transform = scaling(0.5, 0.5, 0.5);

    w.light = light;
    w.arr = (t_sphere*)malloc(2 * sizeof(t_sphere));
    w.arr[0] = s1;
    w.arr[1] = s2;

    return (w);
}

t_intersection** intersect_world(t_world w, t_ray ray)
{
    t_intersection **result;
    t_sphere s1;

    s1 = sphere(3);

    result = (t_intersection**)malloc(2 * sizeof(t_intersection*));
    result[0] = (t_intersection*)malloc(2 * sizeof(t_intersection));
    result[1] = (t_intersection*)malloc(2 * sizeof(t_intersection));
    result[0] = intersect(s1, ray);
    //result[1] = intersect(w.arr[1], ray);

    /*printf("1: %f\n", result[0][0].t);
    printf("2: %f\n", result[0][1].t);
    printf("3: %f\n", result[1][0].t);
    printf("4: %f\n", result[1][1].t);*/

    //printf("color: %f\n", w.arr[0].m.color.blue);
    

    return (result);
}

int main()
{
    t_world w;
    t_ray r;

    w = default_world();
    r = ray(point(0, 0, -5), vector(0, 0, 1));

    intersect_world(w, r);
    //printf("color: %f\n", w.arr[0].m.color.blue);
    return (0);
    
}