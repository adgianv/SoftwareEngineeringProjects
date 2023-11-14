/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:08:56 by everolla          #+#    #+#             */
/*   Updated: 2023/02/03 23:18:05 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	if (i > 0)
		return (i);
	else
		return (0);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putptr(unsigned long long nb)
{
	const char	basex[16] = "0123456789abcdef";
	int			r;
	int			count;

	count = 0;
	if (nb < 16)
		count += write(1, &basex[nb], 1);
	if (nb >= 16)
	{
		r = nb % 16;
		nb = nb / 16;
		count += ft_putptr(nb);
		count += write(1, &basex[r], 1);
	}
	return (count);
}
