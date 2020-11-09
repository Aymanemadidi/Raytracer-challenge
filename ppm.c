#include "header.h"

int    construct_ppm(/*t_canvas canva*/)
{
    int fd1;
    int fd2;

    fd1 = open("test.ppm", O_WRONLY);
    //write(fd, "P3", 2);
    write(fd1,"P3\n", 3);
    close(fd1);
    return (fd1);
}

int     main()
{   
    t_canvas canva = init_canva(4.0, 5.0);
    /*int d;
    canva = init_canva(5, 4);*/
    int d = construct_ppm(/*canva*/);
    printf("fd: %d\n", d);

    return (0);
}