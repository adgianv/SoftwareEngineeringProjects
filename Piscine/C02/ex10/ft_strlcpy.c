/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:38:58 by andi-gia          #+#    #+#             */
/*   Updated: 2023/02/27 19:03:28 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	length(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		return (length(src));
	}
	while (src [i] != '\0' && i < size -1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i == size -1)
	{
		dest[i] = '\0';
	}
	return (length(src));
}
