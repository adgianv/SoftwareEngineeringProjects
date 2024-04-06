#include "../../includes/minishell.h"

/*int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s VARIABLE=VALUE\n", argv[0]);
        return 1;
    }*/
void ft_export(t_general *all, char **args)
{
    char *var_value = args[1];
    (void)all;
    // Trova il simbolo '=' che separa il nome della variabile dal suo valore
    char *equal_sign = strchr(var_value, '='); // provare a usare strchr per cercare var_value in export_v

    if (equal_sign == NULL || equal_sign == var_value) {
        printf("Usage: %s VARIABLE=VALUE\n", args[0]);
        return ;
    }

    // Dividi la stringa in nome della variabile e valore
    *equal_sign = '\0'; // Termina la stringa al segno '='
    char *var_name = var_value; //provare a usare var_name per cercare in export_v la riga e successivamente incollare var_value e equal_sign
    char *value = equal_sign + 1;

    // Imposta la variabile nell'ambiente del processo
    if (setenv(var_name, value, 1) != 0) {
        perror("Failed to set environment variable");
        return; 
    }

    // Visualizza il risultato per conferma
    printf("Exported: %s=%s\n", var_name, value);

    return ;
}
//valutare se fare una copia della matrice e sostiture la stringa passata in imput e successivamente stamparla
//oppure sostituire solo la stringa che gli passi in imput 