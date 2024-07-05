/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:46 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/05 12:28:27 by mben-yah         ###   ########.fr       */
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

#define WIDTH 1000
#define HEIGHT 1000

#define BLACK 0x000000FF
#define WHITE 0xFFFFFFFF
#define CHARCOAL 0x264653FF
#define PERSIAN_GREEN 0x2A9D8FFF
#define SAFFRON 0xE9C46AFF
#define SANDY_BROWN 0xF4A261FF
#define BURNT_SIENNA 0xE76F51FF
#define LIGHT_BLUE 0x8ECAE6FF
#define BLUE_CERULEAN 0x219EBCFF
#define PRUSSIAN_BLUE 0x023047FF
#define AMBER 0xFFB703FF
#define ORANGE 0xFB8500FF


typedef struct s_pixel
{
	u_int32_t	i;
	u_int32_t	j;
}	t_pixel;

typedef struct s_fractal
{
	mlx_image_t *img;
	uint32_t	*palette;
	int			err;
	t_pixel		pixel_coords;
} 	t_fractal;


int 		validate_input(int argc, char **args, t_complex *c);
double		atod(const char *str, int *err);
t_complex	quad_iter(t_complex z, t_complex c);
t_complex	rescale(t_complex z);
int			draw_julia(t_fractal fractal, t_complex c, size_t iters);
int			draw_mandelbrot(t_fractal fractal, size_t iters);
int			min(int a, int b);
uint32_t	*color_palette();

#endif