#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*node_to_push;

	if (*src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next_node;
	if (*src)
		(*src)->prev_node = NULL;
	node_to_push->prev_node = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next_node = NULL;
	}
	else
	{
		(*dest)->prev_node = node_to_push;
		node_to_push->next_node = *dest;
		*dest = node_to_push;
	}
}

void	push_a(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	push_b(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
