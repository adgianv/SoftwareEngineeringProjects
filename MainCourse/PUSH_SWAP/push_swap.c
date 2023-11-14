/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:20:41 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/21 20:07:25 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"


// n > stack.b[0] && n < stack.b[top_b - 1]      PB
// n < stack.min_b && stack.b[0] == stack.max_b      PB
// n > stack.max_b && stack.b[0] == stack.max_b      PB

// Dobbiamo calcolare top_a e top_b
// -------- top_b = 0 When Pb top_b++ && top_a--
// Confrontiamo ogni volta che pushiamo il min e max
// while stack.b != Max max_pos++;
// if max_pos > top_b/2    stack.max_half = 1; else max_half = 0;
// if first_big > top_b/2    stack.big_half = 1; else big_half = 0;
// if first_small > top_b/2    stack.small_half = 1; else small_half = 0;

//ra = push up a
//rra = push down a

int		to_shift (t_stacks *stack, int pos)
{
	int	first_smaller;
	int	first_bigger;
	char *str;

	first_smaller = 0;
	first_bigger = 0;
	// str = ft_itoa(stack->b[1]);
	// 	write(1, &str[0], 1);
	while(stack->a[pos] < stack->b[first_smaller])
		first_smaller++;
	while(stack->a[pos] > stack->b[first_bigger])
		first_bigger++;
	if (stack->a[pos] < stack->b[0] && stack->a[pos] > stack->b[stack->top_b-1])
	{
		if (stack->top_b/2 > first_smaller)
			return (1);
		else
			return (2);
	}
	if (stack->a[pos] < stack->b[0] && stack->a[pos] < stack->b[stack->top_b-1] && stack->b[0] != stack->max)
	{
		if (stack->top_b/2 > first_smaller)
			return (1);
		else
			return (2);
	}
	if (stack->a[pos] > stack->b[0] && stack->a[pos] > stack->b[stack->top_b-1] && stack->b[0] != stack->max)
	{
		if (stack->top_b/2 > first_bigger)
			return (1);
		else
			return (2);
	}
	return (0);
}

int		normal_push(t_stacks *stack, int pos)
{
	if(stack->a[pos] > stack->b[0] && stack->a[pos] < stack->b[stack->top_b-1])
		return (1);
	else
		return (0);
}

int ft_pushmin(t_stacks *stack, int pos)
{
	if(stack->a[pos] < stack->min && stack->b[0] == stack->max)
	{
		stack->min=stack->a[pos];
		return (1);
	}
	else
		return (0);
}

int ft_pushmax(t_stacks *stack, int pos)
{
	if(stack->a[pos] > stack->max && stack->b[0] == stack->max)
	{
		stack->max=stack->a[pos];
		return (1);
	}
	else
		return (0);	
}

int	push_try(t_stacks *stack, int pos)
{
	int	ret;
	
	if (normal_push(stack, pos) == 1)
		return (1);
	else if (ft_pushmax(stack, pos) == 1)
		return (1);
	else if (ft_pushmin(stack, pos) == 1)
		return (1);
	else
		return (0);
}

void	ft_count(t_stacks *stack)
{
	int	*temp_a;
	int *temp_b;
	int	count_t;
	int	i;
	char *str;

	i = 0;
	temp_a = ft_strcpy(stack->a);
	temp_b = ft_strcpy(stack->b);
	stack->count_temp = 0;
	while(stack->a[i])
	{
		/*Questo processo non considera la possibilità degli rr/rrr quindi vanno aggiunti nel "while" loop linee (73-80)*/
		//azzera contatore parziale
		count_t = 0;
		//Da Ricontrollare - contare quante mosse ci vogliono per portare alla prima posizione i numeri nello stack a
		if (stack->top_a / 2 >= i)
			count_t += i;
		else if (stack->top_a / 2 < i)
			count_t += stack->top_a - i;
		while(push_try(stack, i) == 0)
		{
			str = ft_itoa(stack->b[0]);
			write(1, &str[0], 1);
			if (to_shift(stack, i) == 1)
				rb(stack);
			else if (to_shift(stack, i) == 2)
				rrb(stack);			
			count_t++;
		}
		//aumentare il contatore totale (nella struttura sarebbe il temporaneo) solo se il numero ci mette meno mosse ad essere pushato
		if (count_t < stack->count_temp)
		{
			stack->pos_push = stack->a[i];
			stack->count_temp += count_t;
		}
		//riportare gli array nella struttura alla loro forma originale
		stack->a = temp_a;
		stack->b = temp_b;
		i++;
	}
	free(temp_a);
	free(temp_b);
}

void	ft_first_pos(t_stacks *stack)
{
	int pos;

	pos = stack->pos_push;
	if (pos < (stack->top_a/2))
	{
		while(pos > 0)
		{
			ra(stack);
			pos--;
		}
	}
	else if (pos >= (stack->top_a/2))
	{
		while(pos < (stack->top_a/2))
		{
			rra(stack);
			pos++;
		}
	}
}

void	ft_push(t_stacks *stack)
{
	while(normal_push(stack, 0) != 1 && ft_pushmax(stack, 0) != 1 && ft_pushmin(stack, 0) != 1)
	{
		if(to_shift(stack, 0) == 1)
			rb(stack);
		if(to_shift(stack, 0) == 2)
			rrb(stack);
	}
}

void	ft_sort_a(t_stacks *stack)
{
	if(stack->a[0] > stack->a[1])
		sa(stack);
	if(stack->a[1] > stack->a[2])
		rra(stack);
	if(stack->a[0] > stack->a[1])
		sa(stack);
}

void	push_swap(t_stacks *stack)
{
	int	i;
	int count_moves;
	char	*uno;
	char	*due;

	stack->top_a = ft_strlen(stack);
	stack->top_b = 0;
	stack->count_tot = 0;
	while(stack->top_a > 3)
	{
		while(stack->top_b < 2)
		{
			push_b(stack);
			stack->top_b++;
			stack->top_a--;
			stack->count_tot++;
		}
		stack->max = stack->b[0];
		if (stack->b[1] < stack->b[0])
			stack->min=stack->b[1];
		else
			{
				stack->max = stack->b[1];
				stack->min=stack->b[0];
			}
		//funzione per trovare la posizione del numero che ci mette mano mosse ad essere pushato
		ft_count(stack);
		//aggiungere le mosse che servono per pusharlo al conteggio delle mosse totale
		stack->count_tot += stack->count_temp;
		//funzione per portarlo alla prima posizione
		ft_first_pos(stack);
		//funzione per pusharlo
		ft_push(stack);
		stack->top_a--;
		stack->top_b++;
	}
	ft_sort_a(stack);
	while (stack->top_b > 0)
	{
		if (stack->b[0] > stack->a[stack->top_a - 3])
			push_a(stack);
		else
			rra(stack);
		stack->top_b--;
		stack->top_a++;
	}
}
