/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:56:36 by andi-gia          #+#    #+#             */
/*   Updated: 2023/02/28 02:58:38 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	num = 0;
	sign = 0;
	while (str[i] != '\0')
	{	
		if (str[i] == '-')
			sign++;
		while (is_numeric(str[i]))
		{
			num = num * 10 + (str[i] - 48);
			i++;
		}
		if (num > 0)
			break ;
		i++;
	}
	if (sign % 2 > 0)
		return (-num);
	else
		return (num);
}
