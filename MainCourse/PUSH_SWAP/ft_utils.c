#include "push_swap.h"

int	*ft_strcpy(int *a)
{
	int	*res;
	int	i;

	i = 0;
	while (a[i])
		i++;
	res = malloc(i * 4);
	if (!res)
		return (NULL);
	i = 0;
	while (a[i])
	{
		res[i] = a[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int	*ft_strjoin(int first, int *a)
{
	int	i;
	int	j;
	int	*res;

	i = 0;
	while (a[i])
		i++;
	res = malloc((i + 1) * 4);
	if (!res)
		return (NULL);
	res[0] = first;
	i = 0;
	j = 1;
	while (a[i])
		res[j++] = a[i++];
	res[j] = 0;
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str, long *res)
{
	long	negative;

	negative = 1;
	*res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		++str;
	}
	if (!*str)
		return (1);
	while (*str && *str >= '0' && *str <= '9')
	{
		*res = *res * 10 + (*str - 48);
		++str;
	}
	*res *= negative;
	if (*str)
		return (1);
	return (0);
}

int	get_count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}
