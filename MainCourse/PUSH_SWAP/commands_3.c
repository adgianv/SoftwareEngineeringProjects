#include "push_swap.h"

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	reverse_rotate(t_node **root)
{
	t_node	*last_node;

	last_node = search_last_node(root);
	last_node->next_node = *root;
	(*root)->prev_node = last_node;
	last_node->prev_node->next_node = NULL;
	last_node->prev_node = NULL;
	*root = last_node;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
