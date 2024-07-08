/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:48:03 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/08 12:10:47 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
	DESCRIPTION :
	The function ft_atoi converts a string into an int.

	RETURN VALUE :
	The converted int.
*/

static	int	__isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	conv;

	conv = 0;
	sign = 1;
	i = 0;
	while (__isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
	{
		conv = conv * 10 + str[i++] - '0';
		if (conv > 9223372036854775807 && sign == 1)
			return (-1);
		if (conv > 9223372036854775807 && sign == -1)
			return (0);
	}
	return ((int)conv * sign);
}
