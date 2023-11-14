/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:17:04 by andi-gia          #+#    #+#             */
/*   Updated: 2023/03/02 11:46:37 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	res;

	i = power;
	res = nb;
	if (power == 0)
		res = 1;
	if (power < 0)
		res = 0;
	while (i > 1)
	{
		res = res * nb;
		i--;
	}
	return (res);
}
