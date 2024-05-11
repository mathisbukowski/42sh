/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** local_variable_replacer.c
*/

#include <string.h>
#include "minishell.h"

char *get_local_variable(info_t *info, char *name)
{
    local_var_t *var = info->locale;

    while (var != NULL) {
        if (strcmp(var->name, name) == 0)
            return var->value;
        var = var->next;
    }
    return NULL;
}

void replace_local_variable(info_t *info)
{
    char *local_variable_result = NULL;
    char *value_tmp = NULL;

    for (int i = 0; info->args[i] != NULL; i++) {
        if (info->args[i][0] != '$')
            continue;
        local_variable_result = get_local_variable(info, info->args[i] + 1);
        if (local_variable_result == NULL)
            continue;
        value_tmp = strdup(local_variable_result);
        if (value_tmp == NULL)
            continue;
        free(info->args[i]);
        info->args[i] = value_tmp;
    }
}
