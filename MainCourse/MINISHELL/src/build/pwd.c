#include "../../includes/minishell.h"

char *pwd(t_general *all)
{
    if (getcwd(all->cwd, sizeof(all->cwd)) == NULL)
    {
        perror("getcwd");
        return NULL;
    }
    else
        return(all->cwd);
}
