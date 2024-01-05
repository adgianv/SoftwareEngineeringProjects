/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:33 by andi-gia          #+#    #+#             */
/*   Updated: 2023/04/03 15:17:01 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*u;

	i = 0;
	u = (unsigned char *) s;
	while (i < n)
	{
		if (*u == (unsigned char)c)
			return ((void *)u);
		u++;
		i++;
	}
	return (0);
}
