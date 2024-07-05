/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:50 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/05 15:51:30 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	str_to_lower(char *str)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

static int	check_set(char *str)
{
	str_to_lower(str);
	if (!ft_memcmp(str, "mandelbrot", 10))
		return (MANDELBROT);
	else if (!ft_memcmp(str, "julia", 5))
		return (JULIA);
	else
		return (WRONG_FRCTAL_NAME);
}

int validate_input(t_fractal *fractal, int argc, char **args, t_complex *c)
{
	int			set;

	if (argc < 2)
		return (fractal->err = ONE_ARGUMENT_ERR, FAILURE);
	set = check_set(args[1]);
	if (set == MANDELBROT)
		return  (fractal->type = MANDELBROT, SUCCESS);
	else if (set == JULIA)
	{
		if (argc < 4)
			return (fractal->err = NO_JULIA_PARAMS, FAILURE);
		c->x = atod(args[2], &(fractal->err));
		if (fractal->err < 0)
			return (FAILURE);
		c->y = atod(args[3], &(fractal->err));
		if (fractal->err < 0)
			return (FAILURE);
		return (fractal->type = JULIA, SUCCESS);
	}
	else
		return (fractal->err = WRONG_FRCTAL_NAME, FAILURE);
}
