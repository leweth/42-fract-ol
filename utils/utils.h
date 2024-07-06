/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:46 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/06 09:59:34 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H


#include "../lib/printf/ft_printf.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>
#include "../lib/libcmplx/ft_complex.h"
#include "../lib/MLX42/MLX42.h"
#include <float.h>

# define SUCCESS 0
# define FAILURE -1


/* Fractal types */

# define MANDELBROT 41
# define JULIA 42

# define WIDTH 1000
# define HEIGHT 1000


/* Color codes */

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define CHARCOAL 0x264653FF
# define PERSIAN_GREEN 0x2A9D8FFF
# define SAFFRON 0xE9C46AFF
# define SANDY_BROWN 0xF4A261FF
# define BURNT_SIENNA 0xE76F51FF
# define LIGHT_BLUE 0x8ECAE6FF
# define BLUE_CERULEAN 0x219EBCFF
# define PRUSSIAN_BLUE 0x023047FF
# define AMBER 0xFFB703FF
# define ORANGE 0xFB8500FF


/* Error number */

# define ONE_ARGUMENT_ERR -11
# define WRONG_FRCTAL_NAME -12
# define NO_JULIA_PARAMS -13
# define WRONG_NUMS_FORMAT_ERR -14
# define EXCEEDS_MAX_DOUBLE -21
# define RENDERING_ERR -22

/* A struct holding the coodinates of a pixel */

typedef struct s_pixel
{
	u_int32_t	i;
	u_int32_t	j;
}	t_pixel;


/* A struct holding informtion about the fractal to draw */

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t *img;
	uint32_t	palette[10];
	t_pixel		pixel_coords;
	int			type;
	int			err;
} 	t_fractal;


/* Input validation and initialization function */
void		initilize_fractal(t_fractal *fractal);
void		validate_input(t_fractal *fractal, int argc, char **args, t_complex *c);
double		atod(const char *str, int *err);


/* Rendering functions */
t_complex	quad_iter(t_complex z, t_complex c);
t_complex	rescale(t_complex z);
int			draw_julia(t_fractal fractal, t_complex c, size_t iters);
int			draw_mandelbrot(t_fractal fractal, size_t iters);
int			min(int a, int b);
void		color_palette();
void		print_error(int err);


#endif