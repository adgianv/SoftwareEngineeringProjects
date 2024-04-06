#include "push_swap.h"

void	nodes_rotation(t_node **a, t_node **b)
{
	t_node	*node_to_push;

	node_to_push = search_to_push(*b);
	if (node_to_push->first_half == 1
		&& node_to_push->target_node->first_half == 1)
		rotate_both_stacks(a, b, node_to_push);
	if (!(node_to_push->first_half == 1)
		&& !(node_to_push->target_node->first_half == 1))
		reverse_rotate_both_stacks(a, b, node_to_push);
	rotate_nodes(b, node_to_push, 'b');
	rotate_nodes(a, node_to_push->target_node, 'a');
	push_a(a, b);
}

void	set_nodes(t_node *a, t_node *b)
{
	nodes_positions(a, b);
	nodes_match(a, b);
	nodes_cost(a, b);
	nodes_to_push(b);
}

void	push_swap(t_node **a, t_node **b)
{
	int		len_a;
	t_node	*smallest_node;

	len_a = count_nodes(*a);
	while (len_a > 3)
	{
		push_b(a, b);
		len_a--;
	}
	sort_small_stack(a);
	while (*b)
	{
		set_nodes(*a, *b);
		nodes_rotation(a, b);
	}
	nodes_positions_a(*a);
	smallest_node = find_smallest_node(*a);
	while (*a != smallest_node)
	{
		if (smallest_node->first_half == 1)
			ra(a);
		else
			rra(a);
	}
}
