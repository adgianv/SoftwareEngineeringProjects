#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stacks stack;
	int **mtx;
	int	i;
	int j;

// add error handling
	// if (argc == 2)
	// {
	// 	mtx = (int **)ft_split(argv[1], ' ');
	// 	i = 0;
	// 	while(mtx[i])
	// 		i++;
	// 	stack.a = malloc(i*4+1);
	// 	i = 0;
	// 	while(mtx[i] != 0)
	// 		stack.a[i++] = ft_atoi(mtx[i++]);
	// 	stack.a[i] = 0;
	// 	push_swap(&stack);
	// }
	if (argc > 2)
	{
		stack.a = malloc(argc * 4 + 1);
		i = 1;
		j = 0;
		while(i < argc)
		{
			stack.a[j] = ft_atoi(argv[i]);
			i++;
			j++;
		}
		i = 0;
		// while (i < 8)
		// {
		// 	printf("%d", stack.a[i]);
		// 	i++;
		// }
		push_swap(&stack);
	}
	//print the result
	while (stack.a[i])
	{
		printf("%d", stack.a[i]);
		i++;
	}
	return(0);
}
