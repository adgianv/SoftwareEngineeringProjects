/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:36:57 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/19 19:57:17 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_checker(const char s, va_list args);
int		ft_printf(const char *s, ...);
int		ft_hexa(unsigned long nb, char *str);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_uns_putnbr(unsigned int nb);
int		ft_void_hexa(unsigned long nb, char *ptr);
#endif
