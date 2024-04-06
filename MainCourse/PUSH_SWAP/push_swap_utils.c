#include "push_swap.h"

void	nodes_positions_a(t_node *a)
{
	int	pos;
	int	len_a;

	len_a = count_nodes(a);
	pos = 0;
	if (a)
	{
		while (a)
		{
			a->position = pos;
			if (pos <= len_a / 2)
				a->first_half = 1;
			else
				a->first_half = 0;
			pos++;
			a = a->next_node;
		}
	}
}

void	nodes_positions(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = count_nodes(a);
	len_b = count_nodes(b);
	if (a)
		assign_positions(a, len_a);
	if (b)
		assign_positions(b, len_b);
}

// void	nodes_positions(t_node *a, t_node *b)
// {
// 	int	pos;
// 	int	len_a;
// 	int	len_b;

// 	len_a = count_nodes(a);
// 	len_b = count_nodes(b);
// 	pos = 0;
// 	if (a)
// 	{
// 		while (a)
// 		{
// 			a->position = pos;
// 			if (pos <= len_a / 2)
// 				a->first_half = 1;
// 			else
// 				a->first_half = 0;
// 			pos++;
// 			a = a->next_node;
// 		}
// 	}
// 	pos = 0;
// 	if (b)
// 	{
// 		while (b)
// 		{
// 			b->position = pos;
// 			if (pos <= len_b / 2)
// 				b->first_half = 1;
// 			else
// 				b->first_half = 0;
// 			pos++;
// 			b = b->next_node;
// 		}
// 	}
// }

void	nodes_match(t_node *a, t_node *b)
{
	t_node	*target_node;
	t_node	*a_current;
	int		target_value;

	while (b)
	{
		target_value = 2147483647;
		a_current = a;
		while (a_current)
		{
			if (a_current->value > b->value && a_current->value < target_value)
			{
				target_value = a_current->value;
				target_node = a_current;
			}
			a_current = a_current->next_node;
		}
		if (target_value == 2147483647)
			b->target_node = find_smallest_node(a);
		else
			b->target_node = target_node;
		b = b->next_node;
	}
}

void	nodes_cost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = count_nodes(a);
	len_b = count_nodes(b);
	while (b)
	{
		if (b->first_half == 1)
			b->cost = b->position;
		else
			b->cost = len_b - b->position;
		if (b->target_node->first_half == 1)
			b->cost += b->target_node->position;
		else
			b->cost += len_a - (b->target_node->position);
		b = b->next_node;
	}
}

void	nodes_to_push(t_node *b)
{
	t_node	*node_to_push;
	int		lowest_cost;

	lowest_cost = 2147483647;
	while (b->next_node != NULL)
	{
		if (b->cost < lowest_cost)
		{
			node_to_push = b;
			lowest_cost = b->cost;
		}
		b = b->next_node;
	}
	if (b->cost < lowest_cost)
		node_to_push = b;
	while (b != node_to_push)
		b = b->prev_node;
	b->to_push = 1;
}
