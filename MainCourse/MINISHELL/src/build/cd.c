#include "../../includes/minishell.h"

void cd(char **args, t_general *all)
{
    getcwd(all->tmp, sizeof(all->tmp));
    if (strcmp(args[0], "cd") == 0)
    {
        // Esegui il cambio di directory
        if (args[1] == NULL)
        {
            // Se l'utente non ha specificato una directory, torna alla home
            if(chdir(getenv("HOME")) != 0)
                perror("cd");
            else
                strcpy(all->current_directory, "/home");
        }
        else
        {
            
            // Altrimenti, cambia la directory
            if (chdir(args[1]) != 0)
                perror("cd");
            else
            {
                // Memorizza la directory corrente
                if (getcwd(all->current_directory, sizeof(all->current_directory)) == NULL)
                    perror("getcwd");
            }
        }
    }
}