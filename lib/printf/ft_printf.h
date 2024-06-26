/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:44:52 by mben-yah          #+#    #+#             */
/*   Updated: 2024/02/20 15:36:14 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

typedef int	(*t_func)(va_list);

int		ft_printf(const char *format, ...);
int		ft_putchar(va_list args);
int		ft_putstr(va_list args);
int		ft_putpercent(va_list args);
int		ft_putaddress(va_list args);
int		ft_puthexa(unsigned long num, char *base);
int		ft_puthexa_x(va_list args);
int		ft_puthexa_xup(va_list args);
int		ft_putint(va_list args);
int		ft_putunint(va_list args);

#endif