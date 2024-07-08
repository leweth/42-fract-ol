/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:15:43 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/08 12:11:52 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tmp = malloc(s1_len + s2_len + 1);
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, s1, s1_len + s2_len + 1);
	ft_strlcat(tmp, s2, s1_len + s2_len + 1);
	return (tmp);
}
