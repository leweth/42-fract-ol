/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:54:42 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/07 11:55:48 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
/* static void	paint_in_black(t_fractal fractal)
{
	uint32_t	i;	
	uint32_t	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
			mlx_put_pixel(fractal.img, i, j++, 0x00000000);
		i++;
	}
} */

void	scroll_trigger(double xdelta, double ydelta, void* param)
{
	t_fractal	*fractal;

	fractal = param;
	(void) xdelta;
	if (fractal->scroll_flag)
		return ;
	fractal->scroll_flag = true;
	// fractal->cursor_flag = true;
	// printf("%lf\n", ydelta);
	// fractal->iters += 50;
	/* fractal->x_axis_limits = c_sum(fractal->x_axis_limits, 
					rescale(*fractal, (t_complex)fractal->cursor_coords));
	fractal->y_axis_limits = c_sum(fractal->y_axis_limits, 
					rescale(*fractal, (t_complex)fractal->cursor_coords)); */
	if (ydelta < 0)
		fractal->zoom_value *= ZOOM_COEFF;
	else
		fractal->zoom_value /= ZOOM_COEFF;
	// destroy old image
	// paint_in_black(*fractal); // sba8
	// build a new one with the image drawn
	// fractal->x_axis_limits
	draw_fractal(fractal);
	// fractal->zoom_value = 1; // might be unecessary
	// fractal->cursor_flag = false;
	fractal->scroll_flag = false;
}

/* void	cursor_coords(double xpos, double ypos, void* param)
{
	t_fractal	*fractal;

	fractal = param;
	if (!(fractal->cursor_flag))
	{
		fractal->cursor_coords.x = xpos;
		fractal->cursor_coords.y = ypos;
	}
} */
