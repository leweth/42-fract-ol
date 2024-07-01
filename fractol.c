/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:35:02 by mben-yah          #+#    #+#             */
/*   Updated: 2024/06/27 19:34:02 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/MLX42/MLX42.h"
#include "./lib/printf/ft_printf.h"
#include "lib/libft/libft.h"
#include "utils/utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h> // including this in .h will make it seem for other files as an include that is unecessary, why not just include it when needed
#define WIDTH 1000
#define HEIGHT 1000
// if there is something I need in multiple files then it should be declared in the header, else here is just fine
#include <signal.h>

static void ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno)); // they seem to set up a specific error enum then set to it errors, after setting the function mlx_strerror would print the corresponding description of the error.
	exit(EXIT_FAILURE);
}

static void ft_hook(void* param)
{
	const mlx_t* mlx = param; // Mlx handle that carries important data corresponding to the program

	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

static void	rescale(t_complex *z)
{
	z->x = ((z->x - 0) * (2 - (-2)) / WIDTH) - 2;
	z->y = ((z->y - 0) * (2 - (-2)) / HEIGHT) - 2;

}

#include <stdio.h>
static int	color_set(mlx_image_t *img, t_complex c, size_t iters)
{
	size_t		i;
	t_complex	z0;

	i = 0;
	z0.x = 0;
	z0.y = 0;
	while (i < iters)
	{
		rescale(&z0);
		if (is_in_set(z0, iters, c))
			mlx_put_pixel(img, z0.x, z0.y, 0xFFFFFFFF);
		else
			mlx_put_pixel(img, z0.x, z0.y, 0x00000000);
		i++;
		// z0 = c_sum(z0, (t_complex) {0.2, 0.3});
	}
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		exit(EXIT_FAILURE);
	(void) argv;
	mlx_set_setting(MLX_MAXIMIZED, false); // The window will go full screen if the second parameter is set to true
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true); // I should set the resizing to false in fractol I believe
	if (!mlx)
		ft_error(); // prints the error and quits the program, insightful error projection

	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0)) // you should generally draw less images 
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	// ft_memset(img->pixels, 0xFF0000FF, img->width * img->height * sizeof(int32_t));

	t_complex	c = {0.54, 0.54};
	color_set(img, c, 10000);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
