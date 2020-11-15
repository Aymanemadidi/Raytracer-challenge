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

int		len(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char *str;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

int    *construct_ppm(t_canvas canva)
{
    int *fd1 = (int*)malloc(sizeof(int));
    *fd1 = open("test.ppm", O_RDWR);
    int h = (int)canva.height;
    int w = (int)canva.width;
    char *h1 = ft_itoa(h);
    char *w1 = ft_itoa(w);
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
    char *test_red = ft_itoa(pixel_at(canva, 0, 0).red * 255);
    int z = 0;
    /*while (i < h)
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
    j = 0;*/
    while (i < h)
    {   
        while (j < w)
        {   

            write(*fd, test_red, 3);//.red; 
            write(*fd, " ", 1);
            write(*fd, "0", 1);//.green;
            write(*fd, " ", 1);     
            write(*fd, "0", 1);//.blue;
            write(*fd, " ", 1);            
            j++;
        }
        j = 0;
        write(*fd, "\n", 1);
        i++;
    }
    t_color result_color1 = pixel_at(canva, 0, 0);
    printf("red = %d\ngreen = %d\nblue = %d\n\n", result_color1.red, result_color1.green, result_color1.blue);
    t_color result_color2 = pixel_at(canva, 0, 1);
    printf("red = %d\ngreen = %d\nblue = %d\n", result_color2.red, result_color2.green, result_color2.blue);
    //printf("%c\n", test[1][0]);
}

int     main()
{   
    t_canvas canva = init_canva(5, 3);
    int *d ;
    d = NULL;
    t_color red = color(1, 0, 0);
    t_color red2 = color(1, 0, 1);
    write_pixel(&canva, 0, 0, red);
    write_pixel(&canva, 0, 1, red2);
    write_pixel(&canva, 1, 0, red);
    d = construct_ppm(canva);
    ppm_second(d,canva);
    printf("fd: %d\n", *d);

    return (0);
}