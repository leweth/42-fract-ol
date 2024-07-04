/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:50 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/04 14:39:17 by mben-yah         ###   ########.fr       */
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
		return (ft_printf("You must choose either 'Mandelbrot' or 'Julia'.\nThe next two arguments are for the Julia's parameter.\n"), FAILURE);
}

int validate_input(int argc, char **args, t_complex *c)
{
	int			set;
	int			err;

	if (argc < 2)
		return (FAILURE);
	set = check_set(args[1]);
	if (set == MANDELBROT)
		return  (set);
	else if (set == JULIA)
	{
		if (argc < 4)
			return (FAILURE);
		c->x = atod(args[2], &err);
		if (err == FAILURE)
			return (err);
		c->y = atod(args[3], &err);
		if (err == FAILURE)
			return (err);
		return (set);
	}
	return (FAILURE);
}
