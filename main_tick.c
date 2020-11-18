#include "header.h"

void tick(t_envir env, t_projectile *proj)
{   

    proj->position.x = proj->position.x + proj->velocity.x;
    proj->position.x = proj->position.x + proj->velocity.x;
    proj->position.z = proj->position.z + proj->velocity.y;
    
    proj->velocity.x = proj->velocity.x + env.gravity.x + env.wind.x;
    proj->velocity.y = proj->velocity.y + env.gravity.y + env.wind.y;
    proj->velocity.z = proj->velocity.z + env.gravity.z + env.wind.z;
}

int main()
{
    t_projectile proj;
    t_envir env;
    int i;

    proj.position = point(0.0, 1.0, 0.0);
    proj.velocity = normalise_vec(vector(1, 1, 0));

    env.gravity = vector(0, -0.1, 0);
    env.wind = vector(-0.01, 0, 0);

    i = 0;

    while (i < 5)
    {   
        printf("Run number: %d\n", i);
            tick(env, &proj);

        printf("position x: %f\n", proj.position.x);
        printf("position y: %f\n", proj.position.y);
        printf("position z: %f\n", proj.position.z);

        printf("velocity x: %f\n", proj.velocity.x);
        printf("velocity y: %f\n", proj.velocity.y);
        printf("velocity z: %f\n\n\n", proj.velocity.z);
        i++;
    }
}