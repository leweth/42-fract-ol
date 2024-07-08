/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:54:42 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/08 12:04:17 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	scroll_trigger(double xdelta, double ydelta, void* param)
{
	t_fractal	*fractal;
	// t_point		p_scaled;
	// t_point		p;

	fractal = param;
	(void) xdelta;
	if (fractal->scroll_flag)
		return ;
	fractal->scroll_flag = true;
	// fractal->cursor_flag = true;
	// p_scaled = rescale(*fractal, (t_complex)fractal->cursor_coords);
	// p.x = (fractal->axes_limits).x + p_scaled.x; 
	// p.y = (fractal->axes_limits).y + p_scaled.y; 
	// fractal->axes_limits = p; 
	if (ydelta < 0)
		fractal->zoom_value *= ZOOM_COEFF;
	else
		fractal->zoom_value /= ZOOM_COEFF;
	draw_fractal(fractal);
	// fractal->cursor_flag = false;
	fractal->scroll_flag = false;
}

// void	cursor_coords(double xpos, double ypos, void* param)
// {
// 	t_fractal	*fractal;

// 	fractal = param;
// 	if (!(fractal->cursor_flag))
// 	{
// 		fractal->cursor_coords.x = xpos;
// 		fractal->cursor_coords.y = ypos;
// 	}
// }
