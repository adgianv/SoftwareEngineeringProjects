#include "ft_printf.h"

int	pf_putstr(const char *str)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	get_unsigned_count(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*pf_unsigned_itoa(unsigned int n)
{
	char	*res;
	int		size;
	long	nb;

	size = get_count(n);
	res = (char *) malloc (size + 1);
	if (!res)
		return (0);
	res[size] = '\0';
	if (nb == 0)
		res[0] = 48;
	while (nb > 0)
	{
		res[--size] = 48 + (nb % 10);
		nb /= 10;
	}
	return (res);
}

int	pf_put_unsigned(unsigned int i)
{
	char	*number;
	int		length;

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	number = pf_unsigned_itoa(i);
	length = pf_putstr(number);
	free(number);
	return (length);
}
