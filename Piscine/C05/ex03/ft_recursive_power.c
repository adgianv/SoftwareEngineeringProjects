/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:00:01 by andi-gia          #+#    #+#             */
/*   Updated: 2023/03/02 11:46:51 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	i;
	int	res;

	i = power;
	res = nb;
	if (power == 0)
		res = 1;
	if (power < 0)
		res = 0;
	if (i > 1)
	{
		res = ft_recursive_power(nb, (power - 1));
		res = res * nb;
	}
	return (res);
}
