/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:55:27 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/06 10:06:46 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	print_redundant(const char *str)
{
	ft_printf("%s\n", str);
	ft_printf("--------------------------------\n");
	ft_printf("You must choose either 'Mandelbrot' or 'Julia'.\n");
	ft_printf("The next two arguments are for the Julia's parameter.\n");
}
void	print_error(int err)
{
	if (err == ONE_ARGUMENT_ERR)
		print_redundant("No arguements Were provided.");
	else if (err == WRONG_FRCTAL_NAME)
		print_redundant("Wrong fractal name.");
	else if (err == NO_JULIA_PARAMS)
		print_redundant("You must enter the parameters for the C constant.");
	else if (err == WRONG_NUMS_FORMAT_ERR)
		print_redundant("Wrong format for the complex constant.");
	else if (err == EXCEEDS_MAX_DOUBLE)
		print_redundant("Number exceeds the available max for the double data type.");
	else if (err == RENDERING_ERR)
		ft_printf("Error in rendering.\n");
}
