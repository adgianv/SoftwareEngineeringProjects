#include "ft_printf.h"

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

int	get_ptr_count(uintptr_t n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

void	pf_printptr(unsigned long long n)
{
	if (n >= 16)
	{
		pf_printptr(n / 16);
		pf_printptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	pf_putptr(unsigned long long n)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		pf_printptr(n);
		length += get_count(n);
	}
	return (length);
}