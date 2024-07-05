/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:35:02 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/05 12:35:29 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <unistd.h>

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

int main(int argc, char **argv)
{
	t_complex	c;
	int			set;
	int 		ret;
	t_fractal	fractal;

	set = validate_input(argc, argv, &c);
	if (set == FAILURE)
		exit(EXIT_FAILURE);
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true); 
	if (!mlx)
		ft_error();
	fractal.palette = color_palette();
	if (!fractal.palette)
		return (mlx_terminate(mlx), EXIT_FAILURE);
	ret = 0;
	fractal.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (set == MANDELBROT)
	{
		if (draw_mandelbrot(fractal, 1000) < 0)
			return (ft_printf("Error in rendering..\n"));
	}
	else if (set == JULIA)
	{
		if (draw_julia(fractal, c, 1000) < 0)
			return (ft_printf("Error in rendering..\n"));
	}
	if (!fractal.img || (mlx_image_to_window(mlx, fractal.img, 0, 0) < 0))
		ft_error();
	mlx_key_hook(mlx, esc_hook, mlx);
	mlx_close_hook(mlx, clean_close, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (free(fractal.palette), fractal.palette = NULL, EXIT_SUCCESS);
}
