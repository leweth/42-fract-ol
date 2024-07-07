/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_pow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:40:57 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/07 12:49:46 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex	c_pow(t_complex z)
{
	t_complex	squarred_z;

	squarred_z.x = pow(z.x, 2) - pow(z.y, 2);
	squarred_z.y = 2 * z.x * z.y;
	return (squarred_z);
}
