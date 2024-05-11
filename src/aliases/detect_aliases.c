/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** detect_aliases.c
*/

#include "minishell.h"

int detecting_aliases(info_t *info)
{
    aliases_t *current = info->aliases;

    if (!current)
        return 1;
    if (!info->args[0])
        return 1;
    while (current != NULL) {
        if (strcmp(current->alias, info->args[0]) == 0)
            return 0;
        current = current->next;
    }
    return 1;
}
