/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:15:56 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/08 12:10:23 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar2(char c)
{
	return (write(1, &c, 1));
}

static int	__putnbr(unsigned int n)
{
	if (n < 10)
		return (ft_putchar2(n + '0'));
	else
		return (__putnbr(n / 10) + __putnbr(n % 10));
}

int	ft_putunint(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (__putnbr(num));
}
