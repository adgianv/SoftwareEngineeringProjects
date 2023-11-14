/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:35:14 by andi-gia          #+#    #+#             */
/*   Updated: 2023/03/08 16:25:01 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN(x) x % 2 == 0
# define TRUE 1
# define FALSE 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0

typedef int	t_bool;

#endif
