/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:46 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/01 14:47:03 by mben-yah         ###   ########.fr       */
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


# define SUCCESS 0
# define FAILURE -1

# define MANDELBROT 41
# define Julia 42

/*  
typedef struct s_params
{
	mlx_image_t *img;
	t_complex	c; 
	size_t		iters;
} 	t_params;
 */


int 		validate_input(int argc, char **args, t_complex *c)
// t_complex	quad_iter(t_complex z, t_complex c);
bool		is_in_set(t_complex z0, size_t iters, t_complex c);
double		atod(const char *str, int *err);


#endif