/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:34:46 by mben-yah          #+#    #+#             */
/*   Updated: 2024/06/27 18:42:05 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H


#include "../lib/printf/ft_printf.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../lib/libcmplx/ft_complex.h"

# define SUCCESS 0
# define FAILURE -1


int 		validate_input(char **args);
// t_complex	quad_iter(t_complex z, t_complex c);
bool		is_in_set(t_complex z0, size_t iters, t_complex c);



#endif