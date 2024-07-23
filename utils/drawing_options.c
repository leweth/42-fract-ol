/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:43:46 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/08 17:44:18 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	draw_julia(t_fractal fractal, t_complex c, uint32_t iters)
{
	u_int32_t	i;
	u_int32_t	j;
	t_complex	z0;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			z0 = (t_complex){i, j};
			fractal.pixel_coords = (t_pixel){i, j};
			render_fractal(fractal, rescale(fractal, z0), iters, c);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	draw_mandelbrot(t_fractal fractal, uint32_t iters)
{
	u_int32_t	i;
	u_int32_t	j;
	t_complex	c;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT / 2)
		{
			fractal.pixel_coords = (t_pixel){i, j};
			c = rescale(fractal, (t_complex){i, j});
			if (is_in_mandelbrot_set(c.x, c.y) == true)
			{
				mlx_put_pixel(fractal.img, i, j, WHITE);
				mlx_put_pixel(fractal.img, i, HEIGHT - j - 1, WHITE);
			}
			else
				render_fractal(fractal, (t_complex){0, 0}, iters, c);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

void	draw_fractal(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT)
	{
		if (draw_mandelbrot(*fractal, fractal->iters) < 0)
			fractal->err = RENDERING_ERR;
	}
	else if (fractal->type == JULIA)
	{
		if (draw_julia(*fractal, fractal->c, fractal->iters) < 0)
			fractal->err = RENDERING_ERR;
	}
}
