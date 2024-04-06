#include "push_swap.h"

void	swap(t_node **root)
{
	t_node	*second_node;

	second_node = (*root)->next_node;
	(*root)->next_node = second_node->next_node;
	if (second_node->next_node)
		second_node->next_node->prev_node = *root;
	second_node->next_node = second_node->prev_node;
	second_node->prev_node = NULL;
	(*root)->prev_node = second_node;
	*root = second_node;
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	rotate(t_node **root)
{
	t_node	*last_node;
	t_node	*second_node;

	second_node = (*root)->next_node;
	last_node = search_last_node(root);
	last_node->next_node = *root;
	(*root)->prev_node = last_node;
	(*root)->next_node = NULL;
	second_node->prev_node = NULL;
	*root = second_node;
}
