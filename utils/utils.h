/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:46 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/04 19:15:42 by mben-yah         ###   ########.fr       */
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

#define MAX_ITERATIONS 1000000
#define BLACK 0x000000FF
#define WHITE 0xFFFFFFFF
#define min(a,b) ((a) < (b) ? (a) : (b))
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
t_complex	quad_iter(t_complex z, t_complex c);
t_complex c_pow5_add_c(t_complex z, t_complex c);

#endif