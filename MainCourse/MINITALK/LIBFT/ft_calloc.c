/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:14:48 by andi-gia          #+#    #+#             */
/*   Updated: 2023/04/03 15:03:58 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count + size < count || count + size < size)
		return (NULL);
	str = (void *)malloc (count * size);
	if (!str)
		return (NULL);
	ft_bzero (str, count * size);
	return (str);
}
