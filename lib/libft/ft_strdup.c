/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:45:32 by mben-yah          #+#    #+#             */
/*   Updated: 2024/01/07 11:56:51 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strdup duplicates the given string s1 by allocating 
	memory and performing a copy of the given string.

	RETURN VALUE :
	A pointer to the new string. NULL if the memory allocation fails.
*/

char	*ft_strdup(const char *s1)
{
	char	*tmp;

	tmp = malloc(ft_strlen(s1) + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1, ft_strlen(s1) + 1);
	return (tmp);
}
