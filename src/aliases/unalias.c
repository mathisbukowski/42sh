/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** unalias.c
*/

#include "minishell.h"
#include "commands.h"

static void check_prev(aliases_t *prev, aliases_t *current, info_t *info)
{
    if (prev == NULL)
        info->aliases = current->next;
    else
        prev->next = current->next;
}

int command_unalias(info_t *info)
{
    aliases_t *current = info->aliases;
    aliases_t *prev = NULL;

    if (current == NULL || !info->args[1] || info->args[2])
        return 1;
    while (current != NULL) {
        if (strcmp(current->alias, info->args[1]) == 0) {
            check_prev(prev, current, info);
            free(current->alias);
            free(current->command);
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 1;
}
