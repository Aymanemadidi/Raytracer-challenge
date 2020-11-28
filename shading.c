#include "header.h"

tuple normal_at(t_sphere s, tuple p)
{
    tuple object_point;
    tuple object_normal;
    tuple world_normal;

    object_point = mat_tuple(inverse(s.transform), p);
    object_normal = substract_tuples(object_point, point(0, 0, 0));
    world_normal = mat_tuple(transpose_matrix(inverse(s.transform)), object_normal);
    printf("x: %f\n", world_normal.x);
    printf("y: %f\n", world_normal.y);
    printf("z: %f\n", world_normal.z);
    printf("w: %f\n", world_normal.w);
    return normalise_vec(world_normal);
}

tuple reflect(tuple in, tuple normal)
{
    return (substract_tuples(in, scalar_multiply((float)2 * 
            scalar_product(in, normal), normal)));
}

int main()
{
    t_sphere s;
    tuple n;
    tuple v;
    tuple r;

    v = vector(1, -1, 0);
    n = vector(0, 1, 0);
    r = reflect(v, n);

    printf("x: %f\n", r.x);
    printf("y: %f\n", r.y);
    printf("z: %f\n", r.z);
    printf("w: %f\n", r.w);


    //set_transform(&s, translation(0, 1, 0));
    //n = normal_at(s, point(0, 1.70711, -0.70711));
    return (0);
}