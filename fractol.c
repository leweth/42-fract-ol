/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:35:02 by mben-yah          #+#    #+#             */
/*   Updated: 2024/06/27 10:34:33 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/MLX42/MLX42.h"
#include "./lib/printf/ft_printf.h"
#include "lib/libft/libft.h"
// #include "./utils/utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h> // including this in .h will make it seem for other files as an include that is unecessary, why not just include it when needed
#define WIDTH 256
#define HEIGHT 256
// if there is something I need in multiple files then it should be declared in the header, else here is just fine

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

int main(int argc, char **argv)
{
	if (argc != 2)
		exit(EXIT_FAILURE);
	(void) argv;
	mlx_set_setting(MLX_MAXIMIZED, true); // The window will go full screen if the second parameter is set to true
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true); // I should set the resizing to false in fractol I believe
	if (!mlx)
		ft_error(); // prints the error and quits the program, insightful error projection

	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0)) // you should generally draw less images
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	ft_memset(img->pixels, 0xFF0000FF, img->width * img->height * sizeof(int32_t));

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
