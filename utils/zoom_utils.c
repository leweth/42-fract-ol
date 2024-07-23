/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:54:42 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/14 17:49:32 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	scroll_trigger(double xdelta, double ydelta, void	*param)
{
	t_fractal	*fractal;

	fractal = param;
	(void) xdelta;
	if (fractal->scroll_flag)
		return ;
	fractal->scroll_flag = true;
	if (ydelta < 0)
		fractal->zoom_value *= ZOOM_IN_COEFF;
	else
		fractal->zoom_value *= ZOOM_OUT_COEFF;
	draw_fractal(fractal);
	fractal->scroll_flag = false;
}
