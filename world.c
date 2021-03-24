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
    s2.transform = scaling(0.5, 0.5, 0.5);

    w.light = light;
    w.arr = (t_sphere*)malloc(2 * sizeof(t_sphere));
    w.arr[0] = s1;
    w.arr[1] = s2;

    return (w);
}

t_intersection** intersect_world(t_world *w, t_ray ray)
{
    t_intersection **result;
    t_intersection *temp;
    t_intersection ftemp;
    t_sphere s1;
    t_sphere s2;

    s1 = w->arr[0];
    s2 = w->arr[1];

    result = (t_intersection**)malloc(2 * sizeof(t_intersection*));
    result[0] = (t_intersection*)malloc(2 * sizeof(t_intersection));
    result[1] = (t_intersection*)malloc(2 * sizeof(t_intersection));
    result[0] = intersect(s2, ray);
    result[1] = intersect(s1, ray);

    temp = result[0];
    result[0] = a_less_b(result[0][0].t, result[1][0].t) ? result[0] : result[1];
    result[1] = a_less_b(result[0][0].t, result[1][0].t) == 0 ? temp : result[1];

    ftemp = result[0][1];
    if (result[0][1].t > result[1][1].t)
    {
        result[0][1].t = result[1][1].t;
        result[0][1].object_id = result[1][1].object_id;
        result[1][1].t = ftemp.t;
        result[1][1].object_id = ftemp.object_id;
    }
    ftemp = result[0][1];
    if (result[0][1].t > result[1][0].t)
    {
        result[0][1].t = result[1][0].t;
        result[0][1].object_id = result[1][0].object_id;
        result[1][0].t = ftemp.t;
        result[1][0].object_id = ftemp.object_id;
    }
     ftemp = result[1][0];
    if (result[1][0].t > result[1][1].t)
    {
        result[1][0].t = result[1][1].t;
        result[1][0].object_id = result[1][1].object_id;
        result[1][1].t = ftemp.t;
        result[1][1].object_id = ftemp.object_id;
    }
    printf("after\n1: %f\n", result[0][0].t);
    printf("2: %f\n", result[0][1].t);
    printf("3: %f\n", result[1][0].t);
    printf("4: %f\n", result[1][1].t);
    //printf("color: %f\n", w->arr[0].m.color.blue);
    

    return (result);
}

/*int main()
{
    t_world w;
    t_ray r;

    w = default_world();
    r = ray(point(0, 0, -5), vector(0, 0, 1));
    w.s3 = sphere(3);

    intersect_world(&w, r);
    //float arr[16] = {9,3,0,9,-5,-2,-6,-3,-4,9,6,4,-7,6,6,2};
    //float arr[16] = {0.5,0,0,0,0,0.5,0,0,0,0,0.5,0,0,0,0,1};
    //displayInv(inverse(init_matrix(arr)));
    //displayInv(inverse(scaling(0.5, 0.5, 0.5)));
    //printf("color: %f\n", w.arr[0].m.color.blue);
    return (0);
    
}*/