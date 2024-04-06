/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:14:52 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/06 15:33:41 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_listlink	*ft_lstnew(int content, int index)
{
	t_listlink	*mal;

	mal = (t_listlink *)malloc(sizeof(t_listlink));
	if (mal == NULL)
		return (NULL);
	mal->content = content;
	mal->next = NULL;
	mal->before = NULL;
	mal->index = index;
	return (mal);
}
