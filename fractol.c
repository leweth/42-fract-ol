/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:35:02 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/04 17:55:02 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <unistd.h>
#define WIDTH 1000
#define HEIGHT 1000

static void ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void clean_close(void* param)
{
	mlx_t *mlx;

	mlx = param;
	mlx_terminate(mlx);
	exit(EXIT_FAILURE);
}
static void	esc_hook(mlx_key_data_t keydata, void* param)
{
	mlx_t *mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(mlx);
		exit(EXIT_FAILURE);
	}
}

#include <stdio.h>

static t_complex	rescale(t_complex z)
{
	t_complex	z0;

	z0.x = (((z.x - 0.0) * (+2 - (-2)) / (WIDTH - 0)) + (-2));
	z0.y = (((z.y - 0.0) * (+2 - (-2)) / (HEIGHT - 0)) + (-2));
	return (z0);
}
#include <math.h>

#include <math.h>

void draw_pixel(t_pixel pixel, uint32_t color, uint16_t iters)
{
    int alpha;
    int transparency;
    int dx, dy, distance;
    int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;

    (void) iters;
    alpha = (color >> 24) & 0xFF;

    dx = pixel.i - centerX;
    dy = pixel.j - centerY;
    distance = sqrt(dx * dx + dy * dy);
    transparency = alpha * (1 - (float)distance / (sqrt(centerX * centerX + centerY * centerY)));

    color = (color & 0x00FFFFFF) | (transparency << 24);
    mlx_put_pixel(pixel.img, pixel.i, pixel.j, color);
}








static int	color_set(mlx_image_t *img, t_complex c, size_t iters)
{
	u_int32_t	i;
	u_int32_t	j;
	t_complex	z0;
	t_complex	der;

	i = 0;
	der = (t_complex){1.0, 0.0};
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			z0 = (t_complex){i, j};
			if (is_in_set(rescale(z0), iters, c) == true)
				draw_pixel((t_pixel){img, i, j}, 0x000000FF, iters);
			else
				draw_pixel((t_pixel){img, i, j}, 0xFFFFFFFF, iters);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	color_set2(mlx_image_t *img, size_t iters)
{
	u_int32_t	i;
	u_int32_t	j;
	t_complex	c;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			c = (t_complex){i, j};
			if (is_in_set((t_complex){0, 0}, iters, rescale(c)) == true)
				draw_pixel((t_pixel){img, i, j}, 0x000000FF, iters);
				// ft_put_pixel(img, i, j, 0);
			else
				draw_pixel((t_pixel){img, i, j}, 0xFFFFFFFF, iters);
				// ft_put_pixel(img, i, j, 0xFFFFFFF);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_complex	c;
	int			set;
	int 		ret;

	set = validate_input(argc, argv, &c);
	if (set == FAILURE)
		exit(EXIT_FAILURE);
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true); 
	if (!mlx)
		ft_error();
	ret = 0;
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (set == MANDELBROT)
	{
		if (color_set2(img, 100) < 0)
			return (printf("Error in rendering..\n"));
	}
	else if (set == JULIA)
	{
		if (color_set(img, c, 100) < 0)
			return (printf("Error in rendering..\n"));
	}
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0)) // you should generally draw less images 
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	// ft_memset(img->pixels, 0xFF0000FF, img->width * img->height * sizeof(int32_t));

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// param = (t_params){img, c, 42};
	mlx_key_hook(mlx, esc_hook, mlx);
	mlx_close_hook(mlx, clean_close, mlx);
	// mlx_loop_hook(mlx, esc_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
