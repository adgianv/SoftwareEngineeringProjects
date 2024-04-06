/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:09:18 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/05 16:06:36 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr1;

	i = 0;
	ptr = (unsigned char *)s1;
	ptr1 = (unsigned char *)s2;
	while ((s2[i] || s1[i]) && i < n)
	{
		if (ptr[i] != ptr1[i])
			return (ptr[i] - ptr1[i]);
		i++;
	}
	return (0);
}
