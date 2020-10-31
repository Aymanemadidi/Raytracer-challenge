#include "header.h"

t_projectile tick(t_envir env, t_projectile proj)
{   
    t_projectile ret_proj;

    ret_proj.position.x = proj.position.x + proj.velocity.x;
    ret_proj.position.x = proj.position.x + proj.velocity.x;
    ret_proj.position.z = proj.position.z + proj.velocity.y;
    
    ret_proj.velocity.x = proj.velocity.x + env.gravity.x + env.wind.x;
    ret_proj.velocity.y = proj.velocity.y + env.gravity.y + env.wind.y;
    ret_proj.velocity.z = proj.velocity.z + env.gravity.z + env.wind.z;

    return (ret_proj);
}

int main()
{
    t_projectile proj;
    t_envir env;
    t_projectile ret_proj;
    int i;

    proj.position = point(0.0, 1.0, 0.0);
    proj.velocity = normalise_vec(vector(1, 1, 0));

    env.gravity = vector(0, -0.1, 0);
    env.wind = vector(-0.01, 0, 0);

    i = 0;

    while (i < 5)
    {   
        printf("Run number: %d\n", i);
        ret_proj = tick(env, proj);

        printf("position x: %f\n", ret_proj.position.x);
        printf("position y: %f\n", ret_proj.position.y);
        printf("position z: %f\n", ret_proj.position.z);

        printf("velocity x: %f\n", ret_proj.velocity.x);
        printf("velocity y: %f\n", ret_proj.velocity.y);
        printf("velocity z: %f\n\n\n", ret_proj.velocity.z);
        i++;
    }
}