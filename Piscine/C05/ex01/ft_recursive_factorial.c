/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:52:16 by andi-gia          #+#    #+#             */
/*   Updated: 2023/03/02 13:49:20 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_recursive_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb > 0)
	{
		res = ft_recursive_factorial(nb - 1);
		res = nb * res;
		return (res);
	}
	if (nb == 0)
		return (1);
	else
		return (0);
}
