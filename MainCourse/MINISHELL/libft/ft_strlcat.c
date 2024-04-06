/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:14:43 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/05 16:23:11 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size;

	if (!dst && ! src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	size = ft_strlen(dst);
	if (dstsize <= size)
		return (ft_strlen(src) + dstsize);
	ft_strlcpy((dst + size), src, (dstsize - size));
	return (size + ft_strlen(src));
}
