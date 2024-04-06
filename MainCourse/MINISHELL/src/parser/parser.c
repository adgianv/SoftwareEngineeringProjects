#include "../../includes/minishell.h"

// Funzione per dividere una stringa in token
int split_line(char *line, char **args)
{
    int argc = 0;
    char *start = line;
    char *end = line;
    int in_word = 0; // Flag per indicare se siamo all'interno di una parola

    while (*end)
    {
        if (*end == ' ' || *end == '\t' || *end == '\n')
        {
            if (in_word)
            {
                // Termina la parola corrente
                *end = '\0';
                args[argc++] = start;
                in_word = 0;
            }
        }
        else
        {
            if (!in_word)
            {
                // Inizia una nuova parola
                start = end;
                in_word = 1;
            }
        }
        end++;
    }

    // Aggiungi l'ultimo token se non è vuoto
    if (in_word)
        args[argc++] = start;

    // Termina l'array degli argomenti
    args[argc] = NULL;

    return argc;
}


// Funzione per eseguire il comando
void execute_command(char **args, t_general *all)
{
    // Controlla se il comando è "cd"
    if (strcmp(args[0], "cd") == 0)
    {
        getcwd(all->tmp, sizeof(all->tmp));
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
    else if (strcmp(args[0], "pwd") == 0)
    {
        // Se il comando è "pwd", stampa la directory corrente
            printf("%s\n", pwd(all));
    }
    else if (strcmp(args[0], "oldpwd") == 0)
        printf("%s\n", all->tmp);
    else if(strcmp(args[0], "env") == 0)
        print_matrix(all->env_v);
    else if(strcmp(args[0], "export") != 0)
    {    
        ft_export(all, all->export_v);
        print_matrix(all->export_v);
    }
    else
    {
        // Altrimenti, esegui il comando
        pid_t pid = fork();
        if (pid == 0)
        {
            // Processo figlio
            char *envp[] = { "PATH=/bin:/usr/bin", NULL };
            execve(args[0], args, envp);
            // Se execvp ritorna, c'è stato un errore
            perror("execve");
            exit(EXIT_FAILURE);
        }
        else if (pid > 0)
            // Processo padre
            waitpid(pid, NULL, 0);
        else
            // fork ha fallito
            perror("fork");
    }
}

/*int main() {
    char *line;
    char *args[MAX_ARGS + 1]; // Aggiunto uno spazio per il terminatore NULL

    while (1) {
        // Leggi l'input
        line = readline("$ ");

        if (!line)
            break;

        // Aggiungi l'input alla history
        if (line[0] != '\0')
            add_history(line);

        // Dividi l'input in token
        int argc = split_line(line, args);

        // Esegui il comando se ci sono argomenti
        if (argc > 0)
            execute_command(args);

        // Libera la memoria allocata per l'input
        free(line);
    }

    return 0;
}*/
