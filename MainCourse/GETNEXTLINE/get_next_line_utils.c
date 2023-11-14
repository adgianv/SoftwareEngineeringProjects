#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *) s;
	while (*str)
	{
		if (*str == (char) c)
			return (str);
		str++;
	}
	if (*str == (char) c)
		return (str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *) malloc(size);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*f;

	f = (unsigned char *) str;
	while (n-- > 0)
		*(f++) = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count + size < count || count + size < size)
		return (NULL);
	str = (void *)malloc (count * size);
	if (!str)
		return (NULL);
	ft_bzero (str, count * size);
	return (str);
}

