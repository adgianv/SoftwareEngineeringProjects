#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
# include <stdarg.h>


int	pf_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	check(const char type, va_list args)
{
	int	length;

	length = 0;
	if (type == 'c')
		length = pf_putchar(va_arg(args, int));
	else if (type == 's')
		length = pf_putstr(va_arg(args, const char *));
	else if (type == 'd' || type == 'i')
		length = pf_putnbr(va_arg(args, int));
	else if (type == 'p')
		length = pf_putptr(va_arg(args, unsigned long long));
	else if (type == 'u')
		length = pf_put_unsigned(va_arg(args, unsigned int));
	// else if (type == 'x' || type == 'X')
	// 	length = pf_putptr(va_arg(args, unsigned int), type);
	else if (type == '%')
		length = pf_put_percent();
	return (length);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	int		length;
	int		i;

	i = 0;
	length = 0;
	va_start(args, type);
	while (type[i] != '\0')
	{
		if (type[i] == '%')
		{
			length += check(type[i + 1], args);
			i++;
		}
		else
			length += pf_putchar(type[i]);
		i++;
	}
	return (length);
}

int main()
{
	char	*str;
	int		i;
	unsigned int	n;
	void	*ptr;

	ft_printf("%p\n", ptr);
	printf("%p\n", ptr);
	return(0);
}