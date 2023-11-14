/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:34:42 by andi-gia          #+#    #+#             */
/*   Updated: 2023/03/06 17:52:28 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 1;
	while (i <= nb / i)
	{
		if (nb % i == 0 && i != 1 && i != nb)
		{
			break ;
		}
		i++;
	}
	if (nb % i == 0 || nb == 0 || nb == 1)
		return (0);
	else if (nb < 0)
		return (0);
	else
		return (1);
}

int	ft_find_next_prime(int nb)
{
	int	n;

	n = nb;
	if (nb <= 2)
		n = 2;
	else
	{
		while (ft_is_prime(n) != 1)
		{
			n++;
		}
	}
	return (n);
}
