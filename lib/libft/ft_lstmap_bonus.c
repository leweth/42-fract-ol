/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:40:27 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/08 12:11:18 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*n_node;
	void	*contento;

	if (!lst || !f || !del)
		return (0);
	node = 0;
	while (lst)
	{
		contento = f(lst->content);
		n_node = ft_lstnew(contento);
		if (!n_node)
		{
			del(contento);
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&node, n_node);
		lst = lst->next;
	}
	return (node);
}
