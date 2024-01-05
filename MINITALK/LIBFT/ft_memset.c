/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:07:33 by andi-gia          #+#    #+#             */
/*   Updated: 2023/04/03 15:17:01 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;
	unsigned char	a;
	size_t			i;

	i = 0;
	a = (unsigned char) c;
	dst = (unsigned char *) b;
	while (i < len)
	{
		dst[i] = a;
		i++;
	}
	return (b);
}
