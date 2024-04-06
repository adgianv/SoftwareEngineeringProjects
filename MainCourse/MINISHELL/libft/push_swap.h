#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"
# define MAX_SIZE 10

typedef struct s_moves
{
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
}	t_moves;

typedef struct s_utils
{
	int				nodes_b;
	int				countmovesofnode;
	struct s_moves	moves;
	struct s_moves	finalmoves;
}	t_utils;

typedef struct s_minmax
{
	int	num_max;
	int	num_min;
}	t_minmax;

typedef struct s_countr
{
	int	countra;
	int	countrra;
}	t_countr;

typedef struct s_utils2
{
	int	content;
	int	nodes;
}	t_utils2;

typedef struct s_create
{
	char		**helper;
	int			i;
	int			j;
	int			index;
	t_listlink	*tmp;
}	t_create;

void		push_min_on_top(t_listlink *stack_a, int nodes,
				int content, t_listlink *tmp);
void		calc_min(t_listlink **tmp, t_listlink **stack_a,
				int *content, int nodes);
void		checker_push(t_listlink *stack_a, t_listlink *stack_b);
void		checker3(t_listlink *stack_a, t_listlink *stack_b);
void		checker(t_listlink *stack_a);
void		checker10(t_listlink *stack_a, t_listlink *stack_b);
void		count_put_my_node_on_top_a(t_listlink *stack, t_moves *moves);
void		count_put_my_node_on_top_b(t_listlink *stack, t_moves *moves);
t_listlink	*search_min_than_node(t_listlink *stack_a, t_listlink *stack_b);
int			count_num_moves(t_moves *moves);
t_moves		*reset_moves(t_moves *moves);
void		error(void);
void		free1(char **split);
void		delete_list(t_listlink *stack_a);
void		error1(char **helper, t_listlink *stack_a, int flag);
t_listlink	*create_stack_a(char **argv, int argc);
void		sa(t_listlink *stack_a, int flag);
void		sb(t_listlink *stack_b, int flag);
void		ss(t_listlink *stack_a, t_listlink *stack_b);
void		pa(t_listlink *stack_a, t_listlink *stack_b, int flag);
void		pb(t_listlink *stack_a, t_listlink *stack_b, int flag);
void		ra(t_listlink *stack_a, int flag);
void		rb(t_listlink *stack_b, int flag);
void		rr(t_listlink *stack_a, t_listlink *stack_b);
void		rra(t_listlink *stack_a, int flag);
void		rrb(t_listlink *stack_b, int flag);
void		rrr(t_listlink *stack_a, t_listlink *stack_b);
t_listlink	*move_on_first(t_listlink *stack);
void		print_nodes(t_listlink *stack, int j);
void		checker2(t_listlink *stack_a);
void		checker4(t_listlink *stack_a, t_listlink *stack_b);
t_moves		*reset_moves(t_moves *moves);
int			count_num_moves(t_moves *moves);
void		exec_moves(t_moves finalmoves,
				t_listlink *stack_a, t_listlink *stack_b);
void		count_moves_node2(t_listlink *stack_a,
				t_listlink *stack_b, t_utils *utils, t_minmax minmax);
void		count_moves_node(t_listlink **stack_a,
				t_listlink *stack_b, t_utils *utils);
void		search_max_node2(t_listlink **stack,
				int *content, t_listlink **tmp);
t_listlink	*search_max_node(t_listlink *stack);
void		handle_double_r(t_utils *utils);
void		copy_moves(t_moves *finalmoves, t_moves *moves);
void		pa2(t_listlink **stack_a, t_listlink *stack_b, t_listlink **helper);
void		pb2(t_listlink **stack_b, t_listlink *stack_a, t_listlink **helper);
void		finalfree(t_listlink **stack_a, t_listlink **stack_b);
void		check_order(t_listlink **stack_a, t_listlink **stack_b);
#endif
