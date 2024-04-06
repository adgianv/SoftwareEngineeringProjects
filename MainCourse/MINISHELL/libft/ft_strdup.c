/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:32:52 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/05 00:39:41 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;
	char	*ptr1;
	int		size;

	size = ft_strlen((char *) s1) + 1;
	i = 0;
	ptr = malloc(size);
	if (ptr == 0)
		return (0);
	ptr1 = (char *)s1;
	while (i < size)
	{
		ptr[i] = ptr1[i];
		i++;
	}
	return (ptr);
}
