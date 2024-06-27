/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:17:32 by mben-yah          #+#    #+#             */
/*   Updated: 2024/06/27 15:48:34 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H


#include <math.h>


typedef struct s_point
{
	double	x;
	double	y;
}	t_point;


typedef t_point t_complex;

t_complex	c_pow(t_complex z);
double		c_magnitude(t_complex z);
t_complex	c_sum(t_complex z1, t_complex z2);



#endif