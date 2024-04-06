#include "push_swap.h"

void	assign_positions(t_node *node, int length)
{
	int	pos;

	pos = 0;
	while (node)
	{
		node->position = pos;
		if (pos <= length / 2)
			node->first_half = 1;
		else
			node->first_half = 0;
		pos++;
		node = node->next_node;
	}
}

int	is_sorted(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head && head->next_node)
	{
		if (head->value > head->next_node->value)
			return (0);
		head = head->next_node;
	}
	return (1);
}
