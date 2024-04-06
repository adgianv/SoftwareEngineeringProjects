/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:29:05 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/05 19:46:54 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_listlink	*ft_lstlast(t_listlink *lst)
{	
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
