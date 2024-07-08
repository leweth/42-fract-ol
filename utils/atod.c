/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:03:48 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/08 12:03:49 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static	bool	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

static	int	convert_digits(double *conv, const char *str, size_t *i, int *err)
{
	int	j;

	j = 0;
	*conv = 0;
	while (ft_isdigit(str[*i]))
	{
		*conv = *conv * 10 + str[(*i)++] - '0';
		if (*conv > DBL_MAX)
			*err = EXCEEDS_MAX_DOUBLE;
		j++;
	}
	return (j);
}

double	atod(const char *str, int *err)
{
	double				conv;
	size_t				i;
	int					sign;
	double				conv2;
	int					j;

	sign = 1;
	i = 0;
	conv = 0;
	conv2 = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		*err = WRONG_NUMS_FORMAT_ERR;
	convert_digits(&conv, str, &i, err);
	if (str[i] == '.')
		i++;
	j = convert_digits(&conv2, str, &i, err);
	return (sign * ( conv +  conv2 * pow(10, -j)));
}

