/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:24:44 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/04 19:13:03 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_complex	quad_iter(t_complex z, t_complex c)
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
		if (c_magnitude(z) > 2.00)
			return (false);
		j++;
	}
	return (true);
}
t_complex c_pow5_add_c(t_complex z, t_complex c) {
  t_complex squared_z = c_pow(z);  // Reuse the provided function for squaring
  t_complex cubed_z;
  cubed_z.x = squared_z.x * z.x - squared_z.y * z.y;
  cubed_z.y = 2 * squared_z.x * z.y + 2 * squared_z.y * z.x;

  t_complex fourth_z;
  fourth_z.x = cubed_z.x * z.x - cubed_z.y * z.y;
  fourth_z.y = 2 * cubed_z.x * z.y + 2 * cubed_z.y * z.x;

  t_complex fifth_z;
  fifth_z.x = fourth_z.x * z.x - fourth_z.y * z.y;
  fifth_z.y = 2 * fourth_z.x * z.y + 2 * fourth_z.y * z.x;

  // Add constant value 'c' to the final result
  fifth_z.x += c.x;
  fifth_z.y += c.y;

  return fifth_z;
}