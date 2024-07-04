/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:41:44 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/04 17:53:07 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Fonction d'interpolation linéaire pour la couleur.
 *
 * @param t Paramètre d'interpolation.
 * @return int Couleur interpolée.
 */

static int	linear_interpolation(double t)
{
	int	red;
	int	green;
	int	blue;

	if (t < 0)
		t = 0;
	if (t > 1)
		t = 1;
	red = ((WHITE >> 16) & 0xFF) * t;
	green = ((WHITE >> 8) & 0xFF) * t;
	blue = (WHITE & 0xFF) * t;
	return ((red << 16) | (green << 8) | blue);
}

/**
* @brief Fonction pour déterminer la couleur d'un pixel à l'extérieur 
 *	de l'ensemble de Mandelbrot.
 * 
 * @param z Le point z après l'itération finale.
 * @param der La dérivée de z après l'itération finale.
 * @return int Couleur à appliquer au format 0x00RRGGBB.
 */
int	normal_color(t_complex z, t_complex der)
{
	t_complex	u;
	t_complex	v;
	double		t;
	double		angle;

	angle = 2.0 * ANGLE * M_PI / 360.0;
	exp_complex(angle, &v);
	u = divide_complex(z, der);
	u.x /= abs_complex(u);
	u.y /= abs_complex(u);
	t = dot_complex(&u, &v) + 2;
	t = t / (1 + 2);
	return (linear_interpolation(t));
}
