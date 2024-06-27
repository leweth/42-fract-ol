/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:46 by mben-yah          #+#    #+#             */
/*   Updated: 2024/06/27 10:30:33 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H


#include "../lib/printf/ft_printf.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>


int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_tolower(int c);
size_t	ft_strlen(const char *str);
int 	validate_input(char *str);

#endif