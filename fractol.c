/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:35:02 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/06 10:01:41 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

static void	clean_exit(t_fractal *fractal)
{
	if (fractal->mlx)
		mlx_terminate(fractal->mlx);
	print_error(fractal->err);
	exit(EXIT_SUCCESS);
}

static void ft_error(t_fractal *fractal)
{
	ft_printf("%s\n", mlx_strerror(mlx_errno));
	clean_exit(fractal);
}

static void clean_close(void* param)
{
	t_fractal *fractal;

	fractal = param;
	clean_exit(fractal);
}
static void	esc_hook(mlx_key_data_t keydata, void* param)
{
	t_fractal *fractal;

	fractal = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		clean_exit(fractal);
}

static void	draw_fractal(t_fractal *fractal, t_complex c)
{
	if (fractal->type == MANDELBROT)
	{	
		if (draw_mandelbrot(*fractal, 1000) < 0)
			fractal->err = RENDERING_ERR;
	}
	else if (fractal->type == JULIA)
	{	
		if (draw_julia(*fractal, c, 1000) < 0)
			fractal->err = RENDERING_ERR;
	}
}
int main(int argc, char **argv)
{
	t_fractal	fractal;
	t_complex	c;

	initilize_fractal(&fractal);
	if (fractal.err < 0)
		return (print_error(fractal.err), EXIT_FAILURE);
	validate_input(&fractal, argc, argv, &c);
	if (fractal.err < 0)
		return (print_error(fractal.err), EXIT_FAILURE);
	fractal.mlx = mlx_init(WIDTH, HEIGHT, "42-Fractol", true); 
	if (!fractal.mlx)
		ft_error(&fractal);
	fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
	if (!fractal.img)
		ft_error(&fractal);
	draw_fractal(&fractal, c);
	if (mlx_image_to_window(fractal.mlx, fractal.img, 0, 0) < 0)
		ft_error(&fractal);
	if (fractal.err < 0)
		clean_exit(&fractal);
	mlx_key_hook(fractal.mlx, esc_hook, (void *) &fractal);
	mlx_close_hook(fractal.mlx, clean_close, (void *) &fractal);
	mlx_loop(fractal.mlx);
	clean_exit(&fractal);
}
