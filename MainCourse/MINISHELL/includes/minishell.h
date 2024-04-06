#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "print.h"
#include "../libft/libft.h"
#include <limits.h>
#include <sys/wait.h>

# define MAX_ARGS 64
# define MAX_COMMAND_LEN 1024

typedef struct s_general
{
    char *args;
    char **env_v;
    char **export_v;
    char tmp[PATH_MAX];
    char cwd[PATH_MAX];
    char current_directory[PATH_MAX];
    int flag;

} t_general;

void execute_command(char **args, t_general *all);
int split_line(char *line, char **args);
char *pwd(t_general *all);
void cd(char **args, t_general *all);
void start(t_general *all, char **build);
char **build_env(char **matrix);
void print_matrix(char **matrice);
void ft_export(t_general *all, char **args);
//char *old_pwd(t_general *all);
#endif