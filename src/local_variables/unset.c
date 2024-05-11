/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** unset.c
*/

#include "minishell.h"
#include "commands.h"

static void check_prev(local_var_t *prev, local_var_t *current, info_t *info)
{
    if (prev == NULL)
        info->locale = current->next;
    else
        prev->next = current->next;
}

int command_unset(info_t *info)
{
    local_var_t *current = info->locale;
    local_var_t *prev = NULL;

    if (current == NULL || !info->args[1] || info->args[2])
        return 1;
    while (current != NULL) {
        if (strcmp(current->name, info->args[1]) == 0) {
            check_prev(prev, current, info);
            free(current->name);
            free(current->value);
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 1;
}
