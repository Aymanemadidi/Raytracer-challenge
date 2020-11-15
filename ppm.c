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

int    *construct_ppm(t_canvas canva)
{
    int *fd1 = (int*)malloc(sizeof(int));
    *fd1 = open("test.ppm", O_RDWR);
    int h = (int)canva.height;
    int w = (int)canva.width;
    char *h1 = itoa(h);
    char *w1 = itoa(w);
    printf("w1: %c\n", w1[0]);
    write(*fd1, "P3\n", 3);
    write(*fd1, w1, ft_strlen((const char*)w1));
    write(*fd1, " ", 1);
    write(*fd1, h1, ft_strlen((const char*)h1));
    write(*fd1, "\n", 1);
    write(*fd1, "255", 3);
    write(*fd1, "\n", 1);
    return (fd1);
}

void ppm_second(int *fd, t_canvas canva)
{   
    t_color	red = color(1, 0, 0);
    t_color	green = color(0, 0.5, 0);
    t_color	blue = color(0, 0, 1);
    t_rgb_color rgb;
    //int *fd = (int*)malloc(sizeof(int));
    //*fd = open("test.ppm", O_RDWR);
    rgb.red = 0;
    rgb.green = 0;
    rgb.red = 0;
    int i = 0;
    int j = 0;
    int h = (int)canva.height;
    int w = (int)canva.width;
    char test[w][h];
    while (i < h)
    {
        test[0][i] = '0';
        i++;
    }
    i = 0;
    while (i < h)
    {   
        while (j < h)
        {
            test[j][i] = '0';
            j++;
        } 
        i++;     
    }
    i = 0;
    j = 0;
    while (i < h)
    {   
        printf("here\n");
        while (j < w)
        {   
            write(*fd, "0", 1);
            write(*fd, " ", 1);
            j++;
        }
        j = 0;
        write(*fd, "\n", 1);
        i++;
    }
    //printf("%c\n", test[1][0]);
}

int     main()
{   
    t_canvas canva = init_canva(10, 3);
    int *d ;
    d = NULL;
    d = construct_ppm(canva);
    ppm_second(d,canva);
    printf("fd: %d\n", *d);

    return (0);
}