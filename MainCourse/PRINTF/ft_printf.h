#ifndef FT_PRINTF_H
#define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		pf_putstr(const char *str);
int		pf_putnbr(int i);
int		pf_put_percent(void);
int	    get_unsigned_count(unsigned int n);
int		get_ptr_count(uintptr_t n);
void	pf_printptr(unsigned long long n);
int		pf_putptr(unsigned long long n);
char	*pf_unsigned_itoa(unsigned int n);
int		pf_put_unsigned(unsigned int i);
char	*ft_itoa(int n);
int	    get_count(long n);

#endif