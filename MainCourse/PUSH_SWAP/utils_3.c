#include "push_swap.h"

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	long	nb;

	nb = (long)n;
	size = (int)get_count(nb);
	res = (char *)malloc(size + 1);
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

t_node	*search_last_node(t_node **a)
{
	t_node	*last_node;

	last_node = *a;
	while (last_node->next_node != NULL)
		last_node = last_node->next_node;
	return (last_node);
}

int	count_nodes(t_node *node)
{
	int	count;

	count = 1;
	while (node->next_node != NULL)
	{
		node = node->next_node;
		count += 1;
	}
	return (count);
}

void	sort_small_stack(t_node **stack)
{
	if ((*stack)->value > (*stack)->next_node->value)
		sa(stack);
	if ((*stack)->next_node->next_node)
	{
		if ((*stack)->next_node->value > (*stack)->next_node->next_node->value)
			rra(stack);
	}
	else
	{
		return ;
	}
	if ((*stack)->value > (*stack)->next_node->value)
		sa(stack);
}

t_node	*find_smallest_node(t_node *node)
{
	t_node	*smallest_node;
	int		smallest_value;

	smallest_value = 2147483647;
	while (node != NULL)
	{
		if (node->value < smallest_value)
		{
			smallest_node = node;
			smallest_value = node->value;
		}
		node = node->next_node;
	}
	return (smallest_node);
}
