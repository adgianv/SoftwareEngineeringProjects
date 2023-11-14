/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:35:24 by andi-gia          #+#    #+#             */
/*   Updated: 2023/03/07 12:52:32 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	size;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	size = max - min;
	tab = (int *)malloc(sizeof(int) * size);
	if (tab == NULL)
		return (NULL);
	while (max > min)
	{
		tab[i] = min;
		min += 1;
		i++;
	}
	return (tab);
}
