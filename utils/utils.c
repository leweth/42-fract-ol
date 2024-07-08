/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:24:44 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/08 12:32:39 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	initilize_fractal(t_fractal *fractal)
{
	fractal->mlx = NULL;
	fractal->img = NULL;
	color_palette(fractal->palette);
	fractal->iters = DEFAULT_ITERS;
	fractal->type = NONE;
	fractal->err = 0;
	fractal->pixel_coords = (t_pixel) {0, 0};
	fractal->cursor_coords = (t_point){0, 0};
	fractal->axes_limits = (t_point){2, -2};
	fractal->zoom_value = 1;
	fractal->c = (t_complex){0, 0};
	fractal->scroll_flag = false;
	fractal->cursor_flag = false;
}


t_complex	rescale(t_fractal fractal, t_complex z)
{
	t_complex	z0;

	z0.x = (((z.x - 0.0) * (fractal.axes_limits.x  - fractal.axes_limits.y ) 
			/ (WIDTH - 0)) + fractal.axes_limits.y) * fractal.zoom_value;
	z0.y = (((z.y - 0.0) * (fractal.axes_limits.x - fractal.axes_limits.y ) 
			/ (HEIGHT - 0)) + fractal.axes_limits.y) * fractal.zoom_value;
	return (z0);
}
