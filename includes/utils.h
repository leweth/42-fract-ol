/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:46 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/15 12:21:52 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* Header files inclusions */

# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include "MLX42.h"

/* Functions exit status macros */

# define SUCCESS 0
# define FAILURE -1

/* Fractal types */

# define NONE 40
# define MANDELBROT 41
# define JULIA 42

/* Window dimensions */

# define WIDTH 1000
# define HEIGHT 1000

/* Different utilities macros */

# define DEFAULT_ITERS 200
# define ZOOM_IN_COEFF 0.95
# define ZOOM_OUT_COEFF 1.05
# define LOG_OF_2 0.6931471805599453

/* Color codes */

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define DEEP_SPACE 0x000033FF
# define COSMIC_COBALT 0x2E2D4DFF
# define NEBULA_PINK 0xFFB3BAFF
# define STARDUST_BLUE 0x4682B4FF
# define GALACTIC_PURPLE 0x663399FF
# define CELESTIAL_CYAN 0x00FFFFFF
# define SOLAR_ORANGE 0xFFA500FF
# define ASTEROID_GRAY 0x8B8989FF
# define PULSAR_GREEN 0x50C878FF
# define NOVA_RED 0xFF4500FF

/* Error numbers */

# define ONE_ARGUMENT_ERR -11
# define WRONG_FRACTAL_NAME -12
# define NO_JULIA_PARAMS -13
# define WRONG_NUMS_FORMAT_ERR -14
# define RENDERING_ERR -22

/* Structures for axes representation */

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef t_point	t_complex;

/* Structure for color composants */

typedef struct s_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb;

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
	mlx_image_t	*img;
	int			type;
	uint32_t	iters;
	t_complex	c;
	t_pixel		pixel_coords;
	double		zoom_value;
	t_point		axes_limits;
	uint32_t	palette[10];
	int			err;
	bool		scroll_flag;
	bool		cursor_flag;
	t_point		cursor_coords;
}	t_fractal;

/* Input validation and initialization function */

void		initilize_fractal(t_fractal *fractal);
int			validate_input(t_fractal *fractal, int argc, 
				char **args, t_complex *c);
double		atod(const char *str, int *err);

/* Rendering functions */

void		color_palette(uint32_t *colors);
t_complex	quad_iter(t_complex z, t_complex c);
t_complex	rescale(t_fractal fractal, t_complex z);
bool		is_in_mandelbrot_set(double x, double y);
void		render_fractal(t_fractal fractal, t_complex z0, 
				size_t iters, t_complex c);
int			draw_julia(t_fractal fractal, t_complex c, uint32_t iters);
int			draw_mandelbrot(t_fractal fractal, uint32_t iters);
void		draw_fractal(t_fractal *fractal);

/* Zoom functions */

void		scroll_trigger(double xdelta, double ydelta, void *param);

/* Error function */

void		print_error(int err);
void		ft_error(t_fractal *fractal);

/* Exit function */

void		clean_exit(t_fractal *fractal);

#endif