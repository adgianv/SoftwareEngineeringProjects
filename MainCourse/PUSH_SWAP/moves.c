/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:24:13 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/21 20:01:46 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	sa(t_stacks *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->a[1];
	stack->a[1] = stack->a[0];
	stack->a[0] = temp;
}

void	sb(t_stacks *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->b[1];
	stack->b[1] = stack->b[0];
	stack->b[0] = temp;
}

void	ra(t_stacks *stack)
{
	int	i;
	int	j;
	int	temp;

	temp = stack->a[0];
	i = 0;
	j = 1;
	while (stack->a[j])
		stack->a[i++] = stack->a[j++];
	stack->a[i] = temp;
}

void	rb(t_stacks *stack)
{
	int	i;
	int	j;
	int	temp;

	temp = stack->b[0];
	i = 0;
	j = 1;
	while (stack->b[j])
		stack->b[i++] = stack->b[j++];
	stack->b[i] = temp;
}

void	rra(t_stacks *stack)
{
	int	i;
	int	j;
	int	temp;

	temp = stack->a[0];
	i = 0;
	while (stack->a[i])
		i++;
	i--;
	j = i - 1;
	temp = stack->a[i];
	while (i > 0)
		stack->a[i--] = stack->a[j--];
	stack->a[0] = temp;
}

void	rrb(t_stacks *stack)
{
	int	i;
	int	j;
	int	temp;

	temp = stack->b[0];
	i = 0;
	while (stack->b[i])
		i++;
	i--;
	j = i - 1;
	temp = stack->b[i];
	while (i > 0)
		stack->b[i--] = stack->b[j--];
	stack->b[0] = temp;
}

void	rr(t_stacks *stack)
{
	ra(stack);
	rb(stack);
}

void	rrr(t_stacks *stack)
{
	rra(stack);
	rrb(stack);
}

void	push_a(t_stacks *stack)
{
	int	b_first;
	int	*temp_a;
	int	*temp_b;

	temp_b = ft_strcpy(&stack->b[1]);
	b_first = stack->b[0];
	free(stack->b);
	stack->b = ft_strcpy(temp_b);
	free(temp_b);
	temp_a = ft_strjoin(b_first, stack->a);
	free(stack->a);
	stack->a = ft_strcpy(temp_a);
	free(temp_a);
}

void	push_b(t_stacks *stack)
{
	int	a_first;
	int	*temp_a;
	int	*temp_b;

	temp_a = ft_strcpy(&stack->a[1]);
	a_first = stack->a[0];
	free(stack->a);
	stack->a = ft_strcpy(temp_a);
	free(temp_a);
	if (!stack->b)
		stack->b = malloc(4);
	temp_b = ft_strjoin(a_first, stack->b);
	free(stack->b);
	stack->b = ft_strcpy(temp_b);
	free(temp_b);
}


// int main()
// {
//     int i;
//     t_stacks    stack;

//     i = 0;

//     stack.b = malloc(16);
//     stack.b[0] = 1;
//     stack.b[1] = 2;
//     stack.b[2] = 3;
//     stack.b[3] = 4;

//     rrb(&stack);
//     while (stack.b[i])
//     {
//         printf("%d", stack.b[i]);
//         i++;
//     }
//     return (0);
// }
