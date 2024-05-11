/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** unsetenv.c
*/

#include "minishell.h"
#include "commands.h"
#include "my.h"

int remove_env_variable(info_t *shell, int index)
{
    if (shell == NULL || shell->env == NULL)
        return 1;
    free(shell->env[index]);
    for (int j = index; shell->env[j] != NULL; j++)
        shell->env[j] = shell->env[j + 1];
    return 0;
}

int command_unsetenv(info_t *shell)
{
    int name_len;

    if (shell == NULL || shell->env == NULL)
        return 1;
    if (shell->args[1] == NULL) {
        fprintf(stderr, "unsetenv: Too few arguments.\n");
        return 1;
    }
    name_len = my_strlen(shell->args[1]);
    for (int i = 0; shell->env[i]; i++) {
        if (!my_strncmp(shell->env[i], shell->args[1], name_len) &&
            shell->env[i][name_len] == '=') {
            return remove_env_variable(shell, i);
        }
    }
    return 0;
}
