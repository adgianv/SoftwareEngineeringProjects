#include "../../includes/minishell.h"

void start(t_general *all, char **build)
{
    all->env_v = build_env(build);
    all->export_v = build_env(build);
    //all->tmp = "\n";
}