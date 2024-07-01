/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:35:02 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/01 18:42:12 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <unistd.h>
#define WIDTH 1000
#define HEIGHT 1000
// if there is something I need in multiple files then it should be declared in the header, else here is just fine

static void ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno)); // they seem to set up a specific error enum then set to it errors, after setting the function mlx_strerror would print the corresponding description of the error.
	exit(EXIT_FAILURE);
}

/* static void ft_hook(void* param)
{
	const mlx_t* mlx = param; // Mlx handle that carries important data corresponding to the program

	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
} */
#include <stdio.h>

static t_complex	rescale(t_complex z)
{
	t_complex	z0;

	z0.x = (((z.x - 0.0) * (+2 - (-2)) / (WIDTH - 0)) + (-2));
	z0.y = (((z.y - 0.0) * (+2 - (-2)) / (HEIGHT - 0)) + (-2));
	// printf("%lf --- %lf\n", z0.x, z0.y);
	return (z0);
}

static int	color_set(mlx_image_t *img, t_complex c, size_t iters)
{
	u_int32_t	i;
	u_int32_t	j;
	t_complex	z0;
	// t_complex	z;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			z0 = (t_complex){i, j};
			if (is_in_set(rescale(z0), iters, c) == true)
			{
				// printf("allo");
				mlx_put_pixel(img, i, j, 0x00000000);
				// exit(1);
			}
			else
				mlx_put_pixel(img, i, j, 0x000000FF);
			j++;
		}
		i++;
	}
	// printf("//END//\n");
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
			{
				// printf("allo");
				mlx_put_pixel(img, i, j, 0x00000000);
				// exit(1);
			}
			else
				mlx_put_pixel(img, i, j, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
	// printf("//END//\n");
	return (SUCCESS);
}

void	ft_wrapper(void *param)
{
	t_params	*infos;
	int			ret;

	infos = (t_params *) param;
	ret = color_set(infos->img, infos->c, infos->iters);
	printf("%d\n", ret);
}

int main(int argc, char **argv)
{
	// t_params	param;

	if (argc != 2)
		exit(EXIT_FAILURE);
	(void) argv;
	mlx_set_setting(MLX_MAXIMIZED, false); // The window will go full screen if the second parameter is set to true
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false); 
	if (!mlx)
		ft_error();
	

	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
/* 	t_complex	c = {-0.54, 0.54};
	int ret = color_set(img, c, 100);
	ft_printf("%d\n", ret);*/
	
	int ret = color_set2(img, 1000);
	ft_printf("%d\n", ret);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0)) // you should generally draw less images 
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	// ft_memset(img->pixels, 0xFF0000FF, img->width * img->height * sizeof(int32_t));

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// param = (t_params){img, c, 42};
	// mlx_loop_hook(mlx, ft_wrapper, &param);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
