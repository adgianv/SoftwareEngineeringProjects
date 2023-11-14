/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:18:59 by andi-gia          #+#    #+#             */
/*   Updated: 2023/07/21 19:28:19 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int     *ft_strcpy(int *a)
{
    int *res;
    int i;

    i = 0;
    while(a[i])
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

int     *ft_strjoin(int first, int  *a)
{
    int i;
    int j;
    int *res;

    i = 0;
    while(a[i])
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

int ft_strlen(t_stacks *stack)
{
    int i;

    i = 0;
    while (stack->a[i])
        i++;
    return (i);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
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