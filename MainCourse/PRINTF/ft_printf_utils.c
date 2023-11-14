#include "ft_printf.h"

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

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	long	nb;

	nb = (long) n;
	size = (int) get_count(nb);
	res = (char *) malloc (size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (nb == 0)
		res[0] = 48;
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		res[--size] = 48 + (nb % 10);
		nb /= 10;
	}
	return (res);
}

int	pf_putnbr(int i)
{
	char	*number;
	int		length;

	number = ft_itoa(i);
	length = pf_putstr(number);
	free(number);
	return (length);
}

int	pf_put_percent(void)
{
	write(1, "%", 1);
	return (1);
}