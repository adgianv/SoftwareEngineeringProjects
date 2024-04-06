/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:32:53 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/04 18:51:10 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	len;

	if (s == 0)
		return (0);
	i = 0;
	ptr = malloc(sizeof(char *) * (ft_word(s, c) + 1));
	if (ptr == 0)
		return (0);
	while (*s != 0)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ptr[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ptr[i] = 0;
	return (ptr);
}
