#include "push_swap.h"

void	append_next_node(t_node **a, int number)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = malloc(sizeof(t_node));
	new_node->value = number;
	new_node->next_node = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		new_node->prev_node = NULL;
	}
	else
	{
		last_node = search_last_node(a);
		last_node->next_node = new_node;
		new_node->prev_node = last_node;
	}
}

int	init_struct(t_node **a, char **numbers)
{
	long	integer;

	while (*numbers)
	{
		if (ft_atoi(*numbers, &integer))
			return (1);
		if (integer < -2147483648 || integer > 2147483647)
			return (1);
		append_next_node(a, (int)integer);
		++numbers;
	}
	return (0);
}
