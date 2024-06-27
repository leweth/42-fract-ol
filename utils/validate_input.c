/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:50 by mben-yah          #+#    #+#             */
/*   Updated: 2024/06/26 20:50:44 by mben-yah         ###   ########.fr       */
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

int validate_input(char *str)
{
	str_to_lower(str);
	if (!ft_memcmp(str, "mandelbrot", sizeof(str)))
		return (0);
	else if (!ft_memcmp(str, "julia", sizeof(str)))
		return (1);
	else
	{
		ft_printf("Invalid input.\nYou must choose either 'Mandelbrot' or 'Julia'"); // I can make a function like str_error out of this, leave it for when there are multiple errors
		return (-1);
	}	
}
