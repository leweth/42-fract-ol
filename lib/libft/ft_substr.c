/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:39:37 by mben-yah          #+#    #+#             */
/*   Updated: 2024/01/21 22:16:41 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_substr extracts a substring from the given string by
	allocating sufficient memory for the new string starting at index start
	and ending at len characters.

	RETURN VALUE :
	A pointer to the new string.
	NULL if the memory allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (!s)
		return (0);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = ft_strlen(s + start);
	tmp = malloc(len + 1);
	if (!tmp)
		return (0);
	while (i < len)
		tmp[i++] = *(s++ + start);
	tmp[i] = 0;
	return (tmp);
}
