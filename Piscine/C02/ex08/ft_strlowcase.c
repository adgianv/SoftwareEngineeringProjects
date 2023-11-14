/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:55:20 by andi-gia          #+#    #+#             */
/*   Updated: 2023/02/26 19:17:59 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upper_case(char c)
{
	if ((c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_upper_case(str[i]))
		{
			str[i] = str[i] + 32;
		}
	i++;
	}
	return (str);
}
