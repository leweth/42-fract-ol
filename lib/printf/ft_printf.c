/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:54:51 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/08 12:09:53 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	__check_specifier(char c)
{
	char	*specs;
	int		i;

	specs = "cs%pxXidu";
	i = 0;
	while (i < 9)
	{
		if (c == specs[i])
			return (i);
		i++;
	}
	return (-1);
}

static t_func	__print(int index)
{
	t_func	funcs[9];

	funcs[0] = ft_putchar;
	funcs[1] = ft_putstr;
	funcs[2] = ft_putpercent; 
	funcs[3] = ft_putaddress; 
	funcs[4] = ft_puthexa_x; 
	funcs[5] = ft_puthexa_xup;
	funcs[6] = ft_putint; 
	funcs[7] = ft_putint;
	funcs[8] = ft_putunint;
	return (funcs[index]);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && __check_specifier(format[i + 1]) == -1)
		{
			i++;
			continue ;
		}
		else if (format[i] == '%' && __check_specifier(format[i + 1]) > -1)
			len += (__print(__check_specifier(format[i++ + 1])))(args);
		else
			len += write(1, format + i, 1);
		i++;
	}
	va_end(args);
	return (len);
}
