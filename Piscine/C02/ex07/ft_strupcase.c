/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:28:50 by andi-gia          #+#    #+#             */
/*   Updated: 2023/02/26 16:42:28 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower_case(char c)
{
	if ((c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_lower_case(str[i]))
		{
			str[i] = str[i] - 32;
		}
	i++;
	}
	return (str);
}
