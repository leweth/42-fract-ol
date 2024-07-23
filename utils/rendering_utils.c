/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:56:15 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/14 16:24:49 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

bool	is_in_mandelbrot_set(double x, double y)
{
	double	p;
	double	q;

	p = sqrt((x - 0.25) * (x - 0.25) + y * y);
	if (x < p - 2 * p * p + 0.25)
		return (true);
	q = (x + 1) * (x + 1) + y * y;
	if (q <= 0.0625)
		return (true);
	return (false);
}

void	color_palette(uint32_t *colors)
{
	colors[0] = DEEP_SPACE;
	colors[1] = COSMIC_COBALT;
	colors[2] = NEBULA_PINK;
	colors[3] = STARDUST_BLUE;
	colors[4] = GALACTIC_PURPLE;
	colors[5] = CELESTIAL_CYAN;
	colors[6] = SOLAR_ORANGE;
	colors[7] = ASTEROID_GRAY;
	colors[8] = PULSAR_GREEN;
	colors[9] = NOVA_RED;
}

static uint32_t	smooth_color(double t, uint32_t *colors, int num_colors)
{
	uint32_t	color1;
	uint32_t	color2;
	t_rgb		color_comp;
	double		frac;
	int			index;

	t = t * (num_colors - 1);
	index = (int) t;
	frac = t - index;
	color1 = colors[index];
	color2 = colors[(index + 1) * (index + 1 < num_colors - 1)
		+ (num_colors - 1) * (num_colors - 1 < index + 1)];
	color_comp.r = (1 - frac) * ((color1 >> 24) & 0xFF)
		+ frac * ((color2 >> 24) & 0xFF);
	color_comp.g = (1 - frac) * ((color1 >> 16) & 0xFF)
		+ frac * ((color2 >> 16) & 0xFF);
	color_comp.b = (1 - frac) * (color1 >> 8 & 0xFF)
		+ frac * (color2 >> 8 & 0xFF);
	return ((color_comp.r << 24) | (color_comp.g << 16) 
		| color_comp.b << 8 | 0xFF);
}

static void	put_pixels(t_fractal fractal, uint32_t iter)
{
	uint32_t	color;
	uint32_t	iters;

	iters = fractal.iters;
	color = WHITE;
	if (iter == iters)
	{
		mlx_put_pixel(fractal.img, fractal.pixel_coords.i, 
			fractal.pixel_coords.j, color);
		if (fractal.type == MANDELBROT)
			mlx_put_pixel(fractal.img, fractal.pixel_coords.i, 
				HEIGHT - fractal.pixel_coords.j - 1, color);
	}
	else
	{
		color = smooth_color((double)iter / iters, fractal.palette, 10);
		mlx_put_pixel(fractal.img, fractal.pixel_coords.i, 
			fractal.pixel_coords.j, color);
		if (fractal.type == MANDELBROT)
			mlx_put_pixel(fractal.img, fractal.pixel_coords.i, 
				HEIGHT - fractal.pixel_coords.j - 1, color);
	}
}

void	render_fractal(t_fractal fractal, t_complex z0, 
			size_t iters, t_complex c)
{
	size_t		iter;
	t_complex	z;
	t_complex	z1;

	iter = 0;
	z = z0;
	while (iter < iters)
	{
		if (z.x * z.x + z.y * z.y > 4.00)
			break ;
		z1.x = z.x * z.x - z.y * z.y + c.x;
		z1.y = 2 * z.x * z.y + c.y;
		z = z1;
		iter++;
	}
	put_pixels(fractal, iter);
}
