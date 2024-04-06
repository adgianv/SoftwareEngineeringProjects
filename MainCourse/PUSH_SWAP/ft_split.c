/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:49:47 by andi-gia          #+#    #+#             */
/*   Updated: 2023/03/10 00:50:21 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sep(char c, char d)
{
	if (c == d)
		return (1);
	return (0);
}

int	count_strings(char const *str, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (check_sep(str[i], sep))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !check_sep(str[i], sep))
			i++;
	}
	return (count);
}

int	length(char const *str, char sep)
{
	int	i;

	i = 0;
	while (!check_sep(str[i], sep) && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_word(char const *str, char sep)
{
	int		len;
	char	*word;
	int		i;

	i = 0;
	len = length(str, sep);
	word = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char sep)
{
	char	**strings;
	int		i;

	i = 0;
	if (s == 0)
		return (NULL);
	strings = malloc(sizeof(char *) * (count_strings(s, sep) + 2));
	if (!strings)
		return (NULL);
	strings[i] = ft_word("PlaceHolder ", ' ');
	i++;
	while (*s != '\0')
	{
		while (check_sep(*s, sep) && *s != '\0')
			s++;
		if (*s != '\0')
		{
			strings[i] = ft_word(s, sep);
			i++;
		}
		while (*s && !check_sep(*s, sep))
			s++;
	}
	strings[i] = 0;
	return (strings);
}

/*
int main(int argc, char **argv)
{
	int index;
	char **split;

	split = ft_split(argv[1], argv[2][0]);
	(void) argc;
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
	return 0;
}
*/