#include "header.h"

/*t_canvas *get_w_h()
{
    t_canvas c;
    c = init_canva(4.0, 5.0);
    return c;
}*/

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char * itoa(int num) {
   int count = 1;
   int n = num;
   while(n > 10) { n = n/10; count++; }

   char *str = malloc(count+1);

   str[count] = '\0';
   
   n = num;

   for(int i = count-1; i >= 0; i--) {
      str[i] =  (n%10) + '0';
      n = n /10;
   }

   return str;

}

int    construct_ppm(t_canvas canva)
{
    int fd1;
    fd1 = open("test.ppm", O_RDWR);
    int h = (int)canva.height;
    int w = (int)canva.width;
    char *h1 = itoa(h);
    char *w1 = itoa(w);
    write(fd1, "P3\n", 3);
    write(fd1, w1, ft_strlen((const char*)w1));
    write(fd1, " ", 1);
    write(fd1, h1, ft_strlen((const char*)h1));
    write(fd1, "\n", 1);
    write(fd1, "255", 3);
    write(fd1, "\n", 1);
    close(fd1);
    return (&fd1);
}

void ppm_second(int *fd, t_canvas canva)
{   
    t_color	red = color(1, 0, 0);
    t_color	green = color(0, 0.5, 0);
    t_color	blue = color(0, 0, 1);
    t_rgb_color rgb;
    rgb.red = 0;
    rgb.green = 0;
    rgb.red = 0;
    int i = 0;
    int j = 0;
    int h = (int)canva.height;
    int w = (int)canva.width;
    while (i < h)
    {
        while (j < w)
        {
            write()
        }
    }
} 

/*int     main()
{   
    t_canvas canva = init_canva(80, 40);
    int *d = construct_ppm(canva);
    printf("fd: %d\n", *d);

    return (0);
}*/