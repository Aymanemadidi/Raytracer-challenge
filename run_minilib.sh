#!/bin/sh

gcc -g -Wall -Wextra -Werror mlib_main.c  ./mlx.h -D NUM_THREADS=4 -D LINUX -L ./minilibx-linux -lmlx -lm -lX11 -lXext -lpthread