/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:33 by andi-gia          #+#    #+#             */
/*   Updated: 2023/04/03 15:17:01 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*newlist;

	if (!lst)
		return (0);
	temp = ft_lstnew((f)(lst->content));
	if (!temp)
		return (NULL);
	newlist = temp;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = ft_lstnew((f)(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&lst, del);
			return (newlist);
		}
		ft_lstadd_back(&newlist, temp);
		lst = lst->next;
	}
	return (newlist);
}
