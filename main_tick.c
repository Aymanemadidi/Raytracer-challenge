#include "header.h"

void tick(t_envir env, t_projectile *proj)
{   

    proj->position.x = proj->position.x + proj->velocity.x;
    proj->position.y = proj->position.y + proj->velocity.y;
    proj->position.z = proj->position.z + proj->velocity.z;
    
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
    proj.velocity = normalise_vec(vector(5, 5, 1));

    env.gravity = vector(0, -0.1, 0);
    env.wind = vector(-0.01, 0, 0);

    t_canvas canva = init_canva(15, 15);
    int *d ;
    d = NULL;
    t_color red = color(1, 0, 0);
    t_color red2 = color(0, 0, 0);
    same_color_canva(&canva, red2);  

    i = 0;

    while (i < 20)
    {   

        tick(env, &proj);

        write_pixel(&canva, (int)proj.position.x, canva.height - (int)proj.position.y, red);
        /*printf("position x: %f\n", proj.position.x);
        printf("position y: %f\n", proj.position.y);
        printf("position z: %f\n", proj.position.z);

        printf("velocity x: %f\n", proj.velocity.x);
        printf("velocity y: %f\n", proj.velocity.y);
        printf("velocity z: %f\n\n\n", proj.velocity.z);*/
        i++;
    }
    d = construct_ppm(canva);
    ppm_second(d,canva);
}