/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:27:49 by mben-yah          #+#    #+#             */
/*   Updated: 2024/01/11 20:48:59 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	len_count(int n)
{
	size_t	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	size_t	len;
	int		sign;

	len = len_count(n);
	if (n < 0)
		len++;
	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	sign = 1;
	if (n < 0)
	{
		tmp[0] = '-';
		sign = -1;
	}
	tmp[len--] = 0;
	if (!n)
		tmp[0] = '0';
	while (n)
	{
		tmp[len--] = sign * (n % 10) + '0';
		n /= 10;
	}
	return (tmp);
}
