/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:10:58 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/06 15:11:05 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clean_exit(t_fractal *fractal)
{
	if (fractal->mlx)
		mlx_terminate(fractal->mlx);
	print_error(fractal->err);
	exit(EXIT_SUCCESS);
}
