/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:12:26 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/20 10:31:49 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checker(const char s, va_list args)
{
	int	j;

	j = 0;
	if (s == 'c')
		j += ft_putchar((char)va_arg(args, int));
	else if (s == 's')
		j += ft_putstr(va_arg(args, char *));
	else if (s == 'd')
		j += ft_putnbr(va_arg(args, int));
	else if (s == 'i')
		j += ft_putnbr(va_arg(args, int));
	else if (s == 'p')
		j += ft_void_hexa(va_arg(args, unsigned long), "0123456789abcdef");
	else if (s == 'u')
		j += ft_uns_putnbr(va_arg(args, unsigned int));
	else if (s == 'x')
		j += ft_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (s == 'X')
		j += ft_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (s == '%')
		j += ft_putchar('%');
	return (j);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		j;
	va_list	args;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	va_start(args, s);
	while (s && s[i])
	{
		if (s[i] == '%')
			j += ft_checker(s[++i], args);
		else
			j += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (j);
}
