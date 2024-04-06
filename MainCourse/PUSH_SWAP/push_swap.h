#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				position;
	int				cost;
	int				first_half;
	int				to_push;
	struct s_node	*prev_node;
	struct s_node	*next_node;
	struct s_node	*target_node;
}					t_node;

typedef struct tstack
{
	int				len_a;
	int				len_b;
	int				pos_push;
	int				count_tot_moves;
	int				count_temp;
	int				max_pos;
	int				max;
	int				min;
	int				first_big;
	int				first_small;
}					t_stacks;

char				**ft_split(char const *s, char sep);
int					init_struct(t_node **a, char **numbers);
t_node				*search_last_node(t_node **a);
int					*ft_strcpy(int *a);
int					*ft_strjoin(int first, int *a);
int					ft_strcmp(char *s1, char *s2);
int					ft_strlen(char *str);
void				push_swap(t_node **a, t_node **b);
void				sa(t_node **node);
void				sb(t_node **node);
void				ra(t_node **node);
void				rb(t_node **node);
void				rra(t_node **node);
void				rrb(t_node **node);
void				push(t_node **src, t_node **dest);
void				rr(t_node **a, t_node **b);
void				rrr(t_node **a, t_node **b);
void				push_a(t_node **a, t_node **b);
void				push_b(t_node **a, t_node **b);
void				sort_small_stack(t_node **stack);
t_node				*find_smallest_node(t_node *node);
int					ft_atoi(const char *str, long *res);
char				*ft_itoa(int n);
int					count_nodes(t_node *node);
void				set_nodes(t_node *a, t_node *b);
void				nodes_positions_a(t_node *a);
void				nodes_positions(t_node *a, t_node *b);
void				nodes_match(t_node *a, t_node *b);
void				nodes_cost(t_node *a, t_node *b);
void				nodes_to_push(t_node *b);
void				print_list(t_node *l);
t_node				*search_to_push(t_node *a);
void				rotate_both_stacks(t_node **a, t_node **b,
						t_node *node_to_push);
void				reverse_rotate_both_stacks(t_node **a, t_node **b,
						t_node *node_to_push);
void				rotate_nodes(t_node **a, t_node *node_to_move, char stack);
void				reverse_rotate(t_node **root);
void				rotate(t_node **root);
int					get_count(long n);
void				assign_positions(t_node *node, int length);
int					is_sorted(t_node **stack);

#endif
