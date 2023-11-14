/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:23:12 by andi-gia          #+#    #+#             */
/*   Updated: 2023/02/28 16:18:08 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		write(1, &argv[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	char	*arg;

	argc = 1;
	arg = argv[0];
	ft_putchar(arg);
	return (0);
}
