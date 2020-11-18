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
    int i;
    int j;
    int count;
    int h = (int)canva.height;
    int w = (int)canva.width;
    int len_red;
    int len_green;
    int len_blue;
    float num_red;
    float num_green;
    float num_blue;
    i = 0;
    j = 0;
    count = 0;
    while (j < h)
    {   
        while (i < w)
        {  
            num_red = pixel_at(canva, i, j).red * 255;
            num_green = pixel_at(canva, i, j).green * 255;
            num_blue = pixel_at(canva, i, j).blue * 255;

            num_red = (num_red - floor(num_red) == 0) ? num_red : num_red + 1;
            num_green = (num_green - floor(num_green) == 0) ? num_green : num_green + 1;
            num_blue = (num_blue - floor(num_blue) == 0) ? num_blue : num_blue + 1;        

            len_red = strlen(ft_itoa((int)num_red));
            len_green = strlen(ft_itoa((int)num_green));
            len_blue = strlen(ft_itoa((int)num_blue));
          
            write(*fd, ft_itoa((int)num_red), len_red); 
            write(*fd, " ", 1);
            write(*fd, ft_itoa((int)num_green), len_green);
            write(*fd, " ", 1);     
            write(*fd, ft_itoa((int)num_blue), len_blue);
            if (i + 1 != w)
            {
                write(*fd, " ", 1);
                count++;
            }
            count += len_red + len_green + len_blue + 2;
            if (count > 70)
            {
                write(*fd, "\n", 1);
                count = 0;
            }
            i++;
        }
        count = 0;
        i = 0;
        write(*fd, "\n", 1);
        j++;
    }
}

int     main()
{   
    t_canvas canva = init_canva(400, 400);
    int *d ;
    d = NULL;
    t_color red = color(1, 0, 0);
    t_color red2 = color(1, 0.8, 0.6);
    same_color_canva(&canva, red2);
    //t_color result_before = pixel_at(canva, 0, 3);
    //write_pixel(&canva, 0, 0, red);
    //write_pixel(&canva, 2, 1, color(-0.5, 0.5, 0));
    write_pixel(&canva, 4, 2, color(0, 0, 1.5));
    /*write_pixel(&canva, 0, 1, red2);
    write_pixel(&canva, 1, 0, red);*/
    d = construct_ppm(canva);
    ppm_second(d,canva);
    //t_color result = pixel_at(canva, 0, 3);
    //printf("reeeeed_bef: %f\nreeeeed_after: %f\n", result_before.red, result.red);
    printf("fd: %d\n", *d);

    return (0);
}