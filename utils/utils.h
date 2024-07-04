/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:46 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/04 17:54:27 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H


#include "../lib/printf/ft_printf.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../lib/libcmplx/ft_complex.h"
#include "../lib/MLX42/MLX42.h"
#include <float.h>

# define SUCCESS 0
# define FAILURE -1

# define MANDELBROT 41
# define JULIA 42


#define ANGLE 1.5

#define WHITE 0x00FFFFFF
/* 
typedef struct s_params
{
	mlx_image_t *img;
	t_complex	c; 
	size_t		iters;
} 	t_params;
 */

typedef struct s_pixel
{
	mlx_image_t *img;
	uint32_t i;
	uint32_t j;
} 	t_pixel;

int 		validate_input(int argc, char **args, t_complex *c);
// t_complex	quad_iter(t_complex z, t_complex c);
bool		is_in_set(t_complex z0, size_t iters, t_complex c);
double		atod(const char *str, int *err);
int			normal_color(t_complex z, t_complex der);
double		abs_complex(t_complex complex);
double		dot_complex(t_complex *a, t_complex *b);
void	exp_complex(double angle, t_complex *result);
int		normal_color(t_complex z, t_complex der);
t_complex	conjugate(t_complex a);
t_complex	divide_complex(t_complex numerator, t_complex denominator);

#endif