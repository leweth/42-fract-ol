/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:50:11 by mben-yah          #+#    #+#             */
/*   Updated: 2024/01/21 22:26:45 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;

	if (!s1 || !set)
		return (0);
	s1_len = ft_strlen(s1);
	if (!s1_len)
		return (ft_strdup(""));
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	j = 0;
	while (ft_strchr(set, s1[s1_len - j]))
		j++;
	return (ft_substr(s1, i, s1_len - j - i + 1));
}
