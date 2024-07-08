/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:03:49 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/08 12:11:27 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len--)
			*(p1 + len) = *(p2 + len);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst); 
}
