/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:56:15 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/06 19:15:28 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_in_mandelbrot_set(double x, double y)
{
	double	p;
	double	q;

	p = sqrt((x - 0.25) * (x - 0.25) + y * y);
	if (x < p - 2 * p * p + 0.25)
		return (1);
	q = (x + 1) * (x + 1) + y * y;
	if (q <= 1.0 / 16.0)
		return (true);
	return (false);
}

void	color_palette(uint32_t *colors)
{
	colors[0] = CHARCOAL;
	colors[1] = PERSIAN_GREEN;
	colors[2] = SAFFRON;
	colors[3] = SANDY_BROWN;
	colors[4] = BURNT_SIENNA;
	/* colors[5] = LIGHT_BLUE;
	colors[6] = BLUE_CERULEAN;
	colors[7] = PRUSSIAN_BLUE;
	colors[8] = AMBER;
	colors[9] = ORANGE; */
}

uint32_t smooth_color(double t, uint32_t *colors)
{
	int			num_colors;
	uint32_t 	color1;
	uint32_t 	color2;
	uint8_t 	b;
	uint8_t 	g;
	uint8_t 	r;
	double 		frac;
	int 		index;
	double 		scaled_t;

    num_colors = 5;
    scaled_t = t * (num_colors - 1);
    index = (int) scaled_t;
    frac = scaled_t - index;
    color1 = colors[index];
    color2 = colors[min(index + 1, num_colors - 1)];
    r = (1 - frac) * ((color1 >> 16) & 0xFF) + frac * ((color2 >> 16) & 0xFF);
    g = (1 - frac) * ((color1 >> 8) & 0xFF) + frac * ((color2 >> 8) & 0xFF);
    b = (1 - frac) * (color1 & 0xFF) + frac * (color2 & 0xFF);
    return ((r << 16) | (g << 8) | b);
}

void	render_fractal(t_fractal fractal, t_complex z0, size_t iters, t_complex c)
{
	size_t		iter;
	t_complex	z;

	iter = 0;
	z = z0;
	while (iter < iters)
	{
		if (c_magnitude(z) > 2.00)
			break ;
		z = quad_iter(z, c);
		iter++;
	}
	if (iter == iters)
		mlx_put_pixel(fractal.img, fractal.pixel_coords.i, fractal.pixel_coords.j, WHITE);
	else
		mlx_put_pixel(fractal.img, fractal.pixel_coords.i, fractal.pixel_coords.j, 
				smooth_color((double)iter/iters, fractal.palette));
}

int draw_julia(t_fractal fractal, t_complex c, uint32_t iters)
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
			if (is_in_mandelbrot_set(i, j) == true)
				mlx_put_pixel(fractal.img, fractal.pixel_coords.i, fractal.pixel_coords.j, WHITE);
            z0 = (t_complex){i, j};
			fractal.pixel_coords = (t_pixel) {i, j};  
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
		while (j < HEIGHT)
		{
			if (is_in_mandelbrot_set(i, j) == true)
				mlx_put_pixel(fractal.img, fractal.pixel_coords.i, fractal.pixel_coords.j, WHITE);
			c = (t_complex){i, j};
			fractal.pixel_coords = (t_pixel) {i, j};  
			render_fractal(fractal,  (t_complex){0, 0}, iters, rescale(fractal, c));
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
