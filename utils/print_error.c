/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:55:27 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/05 16:08:39 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_error(int err)
{
	if (err == ONE_ARGUMENT_ERR)
	{
		ft_printf("No arguements Were provided.\n");
		ft_printf("--------------------------------\n");
		ft_printf("You must choose either 'Mandelbrot' or 'Julia'.\n");
		ft_printf("The next two arguments are for the Julia's parameter.\n");
	}
	else if (err == WRONG_FRCTAL_NAME)
	{
		ft_printf("Wrong fractal name.\n");
		ft_printf("--------------------------------\n");
		ft_printf("You must choose either 'Mandelbrot' or 'Julia'.\n");
		ft_printf("The next two arguments are for the Julia's parameter.\n");
	}
	else if (err == FAILED_MALLOC_ERR)
		ft_printf("Failed to allocate.\n");
	else if (err == NO_JULIA_PARAMS)
	{
		ft_printf("You must enter the parameters for the C constant.\n");
		ft_printf("--------------------------------\n");
		ft_printf("You must choose either 'Mandelbrot' or 'Julia'.\n");
		ft_printf("The next two arguments are for the Julia's parameter.\n");
	}
	else if (err == WRONG_NUMS_FORMAT_ERR)
	{
		ft_printf("Wrong format for the complex constant.\n");
		ft_printf("--------------------------------\n");
		ft_printf("You must choose either 'Mandelbrot' or 'Julia'.\n");
		ft_printf("The next two arguments are for the Julia's parameter.\n");
	}
	else if (err == EXCEEDS_MAX_DOUBLE)
	{
		ft_printf("Number exceeds the available max for the double data type.\n");
		ft_printf("--------------------------------\n");
		ft_printf("You must choose either 'Mandelbrot' or 'Julia'.\n");
		ft_printf("The next two arguments are for the Julia's parameter.\n");
	}
	else if (err == RENDERING_ERR)
		ft_printf("Error in rendering.\n");
}
