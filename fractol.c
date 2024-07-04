/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:35:02 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/04 19:19:53 by mben-yah         ###   ########.fr       */
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
uint32_t smooth_color(double t)
{
    // Define a black to white color palette
    uint32_t colors[] = {
    0x264653FF,  // Charcoal
    0x2A9D8FFF,  // Persian green
    0xE9C46AFF,  // Saffron
    0xF4A261FF,  // Sandy brown
    0xE76F51FF,  // Burnt sienna
    0x8ECAE6FF,  // Light blue
    0x219EBCFF,  // Blue (cerulean)
    0x023047FF,  // Prussian blue
    0xFFB703FF,  // Amber
    0xFB8500FF   // Orange
};


    int num_colors = sizeof(colors) / sizeof(colors[0]);
    
    double scaled_t = t * (num_colors - 1);
    int index = (int)scaled_t;
    double frac = scaled_t - index;
    
    uint32_t color1 = colors[index];
    uint32_t color2 = colors[min(index + 1, num_colors - 1)];
    
    uint8_t r = (1 - frac) * ((color1 >> 16) & 0xFF) + frac * ((color2 >> 16) & 0xFF);
    uint8_t g = (1 - frac) * ((color1 >> 8) & 0xFF) + frac * ((color2 >> 8) & 0xFF);
    uint8_t b = (1 - frac) * (color1 & 0xFF) + frac * (color2 & 0xFF);
    
    return (r << 16) | (g << 8) | b;
}

void draw_pixel(t_pixel pixel, uint32_t color, uint16_t iters)
{
	(void) pixel;
	(void) iters;
	(void) color;
    mlx_put_pixel(pixel.img, pixel.i, pixel.j, color);

}
static int color_set(mlx_image_t *img, t_complex c, size_t iters)
{
    u_int32_t i;
    u_int32_t j;
    t_complex z0;
    
    i = 0;
    while (i < WIDTH)
    {
        j = 0;
        while (j < HEIGHT)
        {
            z0 = (t_complex){i, j};
            t_complex z = rescale(z0);
            size_t iter;
            
            for (iter = 0; iter < iters; iter++)
            {
                if (c_magnitude(z) > 2)
                    break;
                z = quad_iter(z, c);
            }
            
            if (iter == iters)
                draw_pixel((t_pixel){img, i, j}, WHITE, iters); // Black for points in the set
            else
            {
                double t = (double)iter / iters;
                uint32_t color = smooth_color(t);
                draw_pixel((t_pixel){img, i, j}, color, iter);
            }
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
		if (color_set2(img, 500000) < 0)
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
