/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:21:12 by andi-gia          #+#    #+#             */
/*   Updated: 2023/03/02 13:51:51 by andi-gia         ###   ########.fr       */
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

int	ft_sqrt(int nb)
{
	int	power;
	int	num;

	num = 0;
	power = 2;
	if (nb > 2147395600)
		return (0);
	while (ft_recursive_power(num, power) < nb)
	{
		num++;
	}
	if ((ft_recursive_power(num, power)) == nb)
		return (num);
	else
		return (0);
}
