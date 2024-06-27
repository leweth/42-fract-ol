/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:52:10 by mben-yah          #+#    #+#             */
/*   Updated: 2023/12/04 21:53:43 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
	DESCRIPTION :
	The function ft_bzero erases data in the n bytes of memory starting
	at location s by writing '\0's.

	RETURN VALUE :
	None.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
