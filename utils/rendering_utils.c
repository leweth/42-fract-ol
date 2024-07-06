/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:56:15 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/06 09:38:54 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	color_palette(uint32_t *colors)
{
	colors[0] = CHARCOAL;
	colors[1] = PERSIAN_GREEN;
	colors[2] = SAFFRON;
	colors[3] = SANDY_BROWN;
	colors[4] = BURNT_SIENNA;
	colors[5] = LIGHT_BLUE;
	colors[6] = BLUE_CERULEAN;
	colors[7] = PRUSSIAN_BLUE;
	colors[8] = AMBER;
	colors[9] = ORANGE;
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

    num_colors = 10;
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

int draw_julia(t_fractal fractal, t_complex c, size_t iters)
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
			fractal.pixel_coords = (t_pixel) {i, j};  
            render_fractal(fractal, rescale(z0), iters, c);
            j++;
        }
        i++;
    }
    return (SUCCESS);
}

int	draw_mandelbrot(t_fractal fractal, size_t iters)
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
			fractal.pixel_coords = (t_pixel) {i, j};  
			render_fractal(fractal,  (t_complex){0, 0}, iters, rescale(c));
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
