/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:54:42 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/06 15:12:13 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	scroll_trigger(double xdelta, double ydelta, void* param)
{
	t_fractal	*fractal;

	fractal = param;
	(void) ydelta;
	if (xdelta > 0)
		fractal->zoom_value = 0.92;
	else
		fractal->zoom_value = 1 / 0.92;
	// destroy old image
	mlx_delete_image(fractal->mlx, fractal->img);
	// build a new one with the image drawn
	draw_fractal(fractal);
	if (mlx_image_to_window(fractal->mlx, fractal->img, 0, 0) < 0)
		ft_error(fractal);
	if (fractal->err < 0)
		clean_exit(fractal);
	fractal->zoom_value = 1; // might be unecessary
}

void	cursor_coords(double xpos, double ypos, void* param)
{
	t_fractal	*fractal;

	fractal = param;
	fractal->cursor_coords.x = xpos;
	fractal->cursor_coords.y = ypos;
}
