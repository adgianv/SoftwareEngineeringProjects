/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:37:10 by andi-gia          #+#    #+#             */
/*   Updated: 2023/03/08 14:11:25 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*ret;

	size = 0;
	if (min >= max)
	{
		ret = NULL;
		return (0);
	}
	ret = malloc(sizeof(int) * (max - min));
	if (!ret)
		return (-1);
	while (min < max)
	{
		ret[size] = min;
		size++;
		min++;
	}
	*range = ret;
	return (size);
}
