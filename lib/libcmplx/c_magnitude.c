/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_magnitude.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:12:31 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/04 17:36:26 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

double	c_magnitude(t_complex z)
{
	return (sqrt(pow(z.x, 2) + pow(z.y, 2)));
	// return (z.x * z.x + z.y * z.y);
	/* double	p;
	double	q;

	p = sqrt((z.x - 0.25) * (z.x - 0.25) + z.y * z.y);
	if (z.x < p - 2 * p * p + 0.25)
		return (1);
	q = (z.x + 1) * (z.x + 1) + z.y * z.y;
	if (q <= 1.0 / 16.0)
		return (1);
	return (0); */
}
