/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:24:44 by mben-yah          #+#    #+#             */
/*   Updated: 2024/06/27 18:42:20 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_complex	quad_iter(t_complex z, t_complex c)
{
	return (c_sum(c_pow(z), c));
}

/* t_point	map_coords(t_point point)
{
	t_point	mapped_p;

	mapped_p.x = ;
	mapped_p.y = ;
} */

bool	is_in_set(t_complex z0, size_t iters, t_complex c)
{
	size_t		j;
	t_complex	z;

	j = 0;
	z = z0;
	while (j < iters)
	{
		if (c_magnitude(z) > 2)
			break ;
		z = quad_iter(z, c); 
		j++;
	}
	if (j == iters)
		return (true);
	return (false);
}

