#include "../../includes/minishell.h"

void	print_matrix(char **matrice)
{
	int	i;

	i = 0;
	
	if (matrice == NULL)
		return ;
	
	while (matrice[i])
	{	
		ft_printf("%s\n", matrice[i]);
		i++;
	}
	return ;
}

char	**build_env(char **matrix)
{
	char	**ret;
	size_t	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (matrix[i] != NULL)
	{
		ret[i] = ft_strdup(matrix[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}


/*void env(t_general *all)
{
    print_matrix(all->env_v);
}*/