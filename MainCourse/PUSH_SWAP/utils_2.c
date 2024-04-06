#include "push_swap.h"

t_node	*search_to_push(t_node *a)
{
	while (a->to_push != 1)
	{
		a = a->next_node;
	}
	return (a);
}

void	rotate_both_stacks(t_node **a, t_node **b, t_node *node_to_push)
{
	while (*b != node_to_push && *a != node_to_push->target_node)
		rr(a, b);
	nodes_positions(*a, *b);
}

void	reverse_rotate_both_stacks(t_node **a, t_node **b, t_node *node_to_push)
{
	while (*b != node_to_push && *a != node_to_push->target_node)
		rrr(a, b);
	nodes_positions(*a, *b);
}

void	rotate_nodes(t_node **a, t_node *node_to_move, char stack)
{
	while ((*a) != node_to_move)
	{
		if (stack == 'a')
		{
			if (node_to_move->first_half == 1)
				ra(a);
			else
				rra(a);
		}
		else if (stack == 'b')
		{
			if (node_to_move->first_half == 1)
				rb(a);
			else
				rrb(a);
		}
	}
}
