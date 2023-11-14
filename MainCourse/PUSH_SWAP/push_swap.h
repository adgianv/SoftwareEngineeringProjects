/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:21:05 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/21 20:07:42 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  tstack
{
    int	*a;
	int	*b;
	int max_half;
    int top_a;
	int top_b;
    int pos_push;
    int count_tot;
    int	count_temp;
	int	max_pos;
	int	max;
	int	min;
	int	first_big;
	int	first_small;
}   t_stacks;

int     *ft_strcpy(int *a);
int     *ft_strjoin(int first, int  *a);
int 	ft_strlen(t_stacks *stack);
int		**ft_split(char *str, char c);
void	push_swap(t_stacks *stack);
void	sa(t_stacks *stack);
void	sb(t_stacks *stack);
void	ra(t_stacks *stack);
void	rb(t_stacks *stack);
void	rra(t_stacks *stack);
void	rrb(t_stacks *stack);
void	rr(t_stacks *stack);
void	rrr(t_stacks *stack);
void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

#endif
