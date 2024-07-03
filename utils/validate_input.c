/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:50 by mben-yah          #+#    #+#             */
/*   Updated: 2024/06/27 16:27:44 by mben-yah         ###   ########.fr       */
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
	if (!ft_memcmp(str, "mandelbrot", sizeof(str)))
		return (MANDELBROT);
	else if (!ft_memcmp(str, "julia", sizeof(str)))
		return (JULIA);
	else
	{
		ft_printf("Invalid input.\nYou must choose either 'Mandelbrot' or 'Julia'"); // I can make a function like str_error out of this, leave it for when there are multiple errors
		return (-1);
	}
}

int validate_input(int argc, char **args, t_complex *c)
{
	int			set;
	int			err;
	t_complex	c;

	if (argc < 2)
		return (FALURE);
	set = check_set(args[1]);
	// check the validity of the rendering paramaters, meaning if it is not an double return an ERROR
	if (set == MANDELBROT)
		return  (set)
	else if (set == JULIA)
	{
		if (argc < 4)
			return (FAILURE);
		c->x = atod(args[2], &err):
		if (err == FAILURE)
			return (err);
		c->y = atod(args[3], &err):
		if (err == FAILURE)
			return (err);
		return (set);
	}
	return (FAILURE);
}
