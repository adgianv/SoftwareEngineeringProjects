#include "push_swap.h"

int	check_doubles_(char **list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (list[i])
	{
		j = i + 1;
		while (list[j])
		{
			if (!ft_strcmp(list[j], list[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	free_struct(t_node **a, char **list, int argc)
{
	t_node	*current;
	int		i;

	while (*a)
	{
		current = (*a)->next_node;
		free(*a);
		*a = current;
	}
	if (argc == 2)
	{
		i = -1;
		while (list[++i])
			free(list[i]);
		free(list);
	}
	return (1);
}

int	check_doubles(t_node *a)
{
	t_node	*temp;

	while (a)
	{
		temp = a->next_node;
		while (temp)
		{
			if (a->value == temp->value)
				return (1);
			temp = temp->next_node;
		}
		a = a->next_node;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**list;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
		list = ft_split(argv[1], ' ');
	else
		list = argv;
	if (init_struct(&a, list + 1) || check_doubles(a))
	{
		write(2, "Error\n", 6);
		free_struct(&a, list, argc);
		return (0);
	}
	if ((!is_sorted(&a)) && (a->next_node))
		push_swap(&a, &b);
	free_struct(&a, list, argc);
	return (0);
}
