#include "header.h"

float vec_magnitude(tuple t)
{
    float mag_x; 
    float mag_y; 
    float mag_z;

    mag_x = t.x * t.x; 
    mag_y = t.y * t.y;
    mag_z = t.z * t.z;

    return (sqrt(mag_x + mag_y + mag_z));
}

tuple normalise_vec(tuple t)
{
    float mag_vec;

    mag_vec = vec_magnitude(t);
    t.x = t.x/mag_vec;
    t.y = t.y/mag_vec;
    t.z = t.z/mag_vec;
    t.w = t.w/mag_vec;

    return (t);
}

float scalar_product(tuple v1, tuple v2)
{
    return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) 
    + (v1.w * v2.w));
}

tuple cross_product(tuple v1, tuple v2)
{
    return (vector((v1.y * v2.z - v1.z * v2.y),
     (v1.z * v2.x - v1.x * v2.z),
      v1.x * v2.y - v1.y * v2.x));
}