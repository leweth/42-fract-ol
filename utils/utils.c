/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:24:44 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/01 18:25:47 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_complex	quad_iter(t_complex z, t_complex c)
{
	return (c_sum(c_pow(z), c));
}

#include <stdio.h>
bool	is_in_set(t_complex z0, size_t iters, t_complex c)
{
	size_t		j;
	t_complex	z;

	j = 0;
	z = z0;
	while (j < iters)
	{
		z = quad_iter(z, c);
		// printf("%f\n", c_magnitude(z));
		if (c_magnitude(z) > 2.00)
			// return (printf("Nope\n"), false);
			return (false);
		j++;
	}
	return (true);
}

