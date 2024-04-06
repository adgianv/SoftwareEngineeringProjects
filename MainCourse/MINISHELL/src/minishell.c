#include "../includes/minishell.h"

int main(int ac, char **av, char **build)
{
    (void)ac;
    (void)av;
    t_general all;
    char *line;
    char *args[MAX_ARGS + 1]; // Aggiunto uno spazio per il terminatore NULL
    start(&all, build);

    
    printf(RED "%s", HELLO RESET);
    while (1)
    {
        // Leggi l'input
        line = readline(RED "minishell> " RESET);
        if (!line)
            break;

        // Aggiungi l'input alla history
        if (line[0] != '\0')
            add_history(line);

        // Dividi l'input in token
        int argc = split_line(line, args);

        // Esegui il comando se ci sono argomenti
        if (argc > 0)
            execute_command(args, &all);

        // Libera la memoria allocata per l'input
        free(line);
    }
    return 0;
}