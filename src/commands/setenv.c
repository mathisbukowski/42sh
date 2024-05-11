/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** setenv.c
*/

#include "minishell.h"
#include "commands.h"
#include "env.h"
#include "my.h"

int input_manager(info_t *shell)
{
    if (!((shell->args[1][0] >= 'A' && shell->args[1][0] <= 'Z') ||
    (shell->args[1][0] >= 'a' && shell->args[1][0] <= 'z')
    || shell->args[1][0] == '_')) {
        fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 1; shell->args[1][i]; i++) {
        if (!((shell->args[1][i] >= '0'
    && shell->args[1][i] <= '9')
    || (shell->args[1][i] >= 'A' && shell->args[1][i] <= 'Z') ||
    (shell->args[1][i] >= 'a' && shell->args[1][i] <= 'z')
    || shell->args[1][i] == '_' || shell->args[1][i] == '.')) {
            fprintf(stderr, "setenv: Variable name must contain alphanumeric "
                            "characters.\n");
            return 1;
        }
    }
    return 0;
}

int error_manager(info_t *shell)
{
    if (shell->env == NULL) {
        fprintf(stderr, "setenv: Empty environment.\n");
        return 1;
    }
    if (get_str_array_len(shell->args) > 3) {
        fprintf(stderr, "setenv: Too many arguments.\n");
        return 1;
    }
    return 0;
}

int add_value(info_t *shell, int size, int name_len, int value_len)
{
    shell->env = my_realloc(shell->env,
    (size + 1) * sizeof(char *), (size + 2) * sizeof(char *));
    if (shell->env == NULL) {
        free_str_array(shell->env);
        return 1;
    }
    free(shell->env[size]);
    shell->env[size] = malloc(name_len + value_len + 2);
    if (shell->env[size] == NULL) {
        free(shell->env[size]);
        return 1;
    }
    my_memcpy(shell->env[size], shell->args[1], name_len);
    shell->env[size][name_len] = '=';
    my_memcpy(&shell->env[size][name_len + 1],
    shell->args[2], value_len);
    shell->env[size][name_len + value_len + 1] = '\0';
    shell->env[size + 1] = NULL;
    return 0;
}

static int update_value(info_t *shell, int value_len,
    int name_len, int index)
{
    free(shell->env[index]);
    shell->env[index] = malloc(name_len + value_len + 2);
    if (shell->env[index] == NULL)
        return 1;
    my_memcpy(shell->env[index], shell->args[1], name_len);
    shell->env[index][name_len] = '=';
    my_memcpy(&shell->env[index][name_len + 1],
    shell->args[2], value_len);
    shell->env[index][name_len + value_len + 1] = '\0';
    if (strncmp(shell->env[index], "HOME", 4) == 0)
        shell->home_var = get_env_value(shell, "HOME");
    return 0;
}

int update_or_add_value(info_t *shell, int size,
    int name_len, int value_len)
{
    int index = -1;

    for (int i = 0; shell->env[i]; i++) {
        if (!my_strncmp(shell->env[i], shell->args[1], name_len)
            && shell->env[i][name_len] == '=') {
            index = i;
            break;
        }
    }
    if (index != -1) {
        if (update_value(shell, value_len, name_len, index) != 0)
            return 1;
    } else
        return add_value(shell, size, name_len, value_len);
    return 0;
}

static int value_length(info_t *shell)
{
    return (shell->args[2] != NULL) ?
    my_strlen(shell->args[2]) : 0;
}

static void add_params(int *size, int *value_len, int *name_len,
    info_t *shell)
{
    *name_len = my_strlen(shell->args[1]);
    *value_len = value_length(shell);
    *size = 0;
}

int command_setenv(info_t *shell)
{
    int size;
    int name_len;
    int value_len;

    if (!shell)
        return 1;
    if (!shell->args[1]) {
        command_env(shell);
        return 0;
    }
    if (error_manager(shell) || input_manager(shell))
        return 1;
    add_params(&size, &value_len, &name_len, shell);
    for (int i = 0; shell->env && shell->env[i]; ++i)
        if (!my_strncmp(shell->env[i], shell->args[1], name_len)
            && shell->env[i][name_len] == '=')
            break;
        else
            size++;
    return update_or_add_value(shell, size, name_len, value_len) ? 1 : 0;
}
