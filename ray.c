#include "header.h"

t_ray ray(tuple origin, tuple direction)
{
    t_ray r;

    r.origin = origin;
    r.direction = direction;

    return (r);
}

tuple position(t_ray ray, float t)
{
    return (add_tuples(ray.origin, scalar_multiply(t, ray.direction)));
}

t_sphere sphere(int id)
{
    t_sphere s;
    s.id = id;
    s.radius = 1;
    s.origin = point(0, 0, 0);
    
    return (s);
}

float cal_delta(t_ray *ray, t_sphere *s)
{
    tuple sphere_to_ray;
    float a;
    float b;
    float c;
    float delta;

    sphere_to_ray = substract_tuples(ray->origin, point(0, 0, 0));
    a = scalar_product(ray->direction, ray->direction);
    b = 2 * scalar_product(ray->direction, sphere_to_ray);
    c = scalar_product(sphere_to_ray, sphere_to_ray) - 1;
    delta = (b * b) - 4 * a *c;
    return (delta);
}

t_intersection intersection(float t, int object_id)
{
    t_intersection i;
    i.t = t;
    i.object_id = object_id;

    return (i);
}

t_intersection* intersect(t_sphere s, t_ray ray)
{
    tuple sphere_to_ray;
    t_intersection *result;
    float a;
    float b;
    float delta;
    
    sphere_to_ray = substract_tuples(ray.origin, point(0, 0, 0));
    a = scalar_product(ray.direction, ray.direction);
    b = 2 * scalar_product(ray.direction, sphere_to_ray);
    result = (t_intersection*)malloc(2 * sizeof(t_intersection));
    delta = cal_delta(&ray, &s);
    if (delta < 0)
        return (NULL);
    result[0] = intersection((-b - sqrt(delta)) / 2 * a, 1);
    result[1] = intersection((-b + sqrt(delta)) / 2 * a, 1);
    return (result);
}

t_intersection* intersections(t_intersection i1, t_intersection i2)
{
    t_intersection* result;
    result = malloc(2 * sizeof(t_intersection));

    result[0] = i1;
    result[1] = i2;
    return (result);
}

t_intersection hit(t_intersection *xs)
{
    if (xs[0].t < 0 && xs[1].t < 0)
        return;
    if (xs[0].t > xs[1].t)
        return (xs[1]);
    else
        return (xs[0]);    
}

int main()
{   
    t_ray r = ray(point(0, 0, -5), vector(0, 0, 1));
    t_sphere s = sphere(1);
    t_intersection *xs;

    xs = NULL;
    xs = intersect(s, r);
    printf("first: %f\nseconf: %f\n", xs[0].t, xs[1].t);
    return (0);
}