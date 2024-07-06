/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:35:02 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/06 15:12:51 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <stdio.h>

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

int main(int argc, char **argv)
{
	t_fractal	fractal;

	initilize_fractal(&fractal);
	validate_input(&fractal, argc, argv, &(fractal.c));
	if (fractal.err < 0)
		return (print_error(fractal.err), EXIT_FAILURE);
	fractal.mlx = mlx_init(WIDTH, HEIGHT, "42-Fractol", true); 
	if (!(fractal.mlx))
		ft_error(&fractal);
	fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
	if (!(fractal.img))
		ft_error(&fractal);
	draw_fractal(&fractal);
	if (mlx_image_to_window(fractal.mlx, fractal.img, 0, 0) < 0)
		ft_error(&fractal);
	if (fractal.err < 0)
		clean_exit(&fractal);
	mlx_key_hook(fractal.mlx, esc_hook, (void *) &fractal);
	mlx_cursor_hook(fractal.mlx, cursor_coords, &fractal);
	mlx_close_hook(fractal.mlx, clean_close, &fractal);
	mlx_scroll_hook(fractal.mlx, scroll_trigger, &fractal);
	mlx_loop(fractal.mlx);
	clean_exit(&fractal);
}
