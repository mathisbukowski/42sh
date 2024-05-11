/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** search_alias.c
*/

#include "minishell.h"

int search_alias_command(info_t *info)
{
    aliases_t *current = info->aliases;

    if (!current)
        return 1;
    if (!info->args[1]) {
        fprintf(stderr, "searchalias: Too few arguments\n");
        return 1;
    }
    while (current != NULL) {
        if (strcmp(current->alias, info->args[1]) == 0) {
            printf("Alias : %s  Command: %s\n", current->alias,
                    current->command);
            return 0;
        }
        current = current->next;
    }
    printf("None alias was provided.\n");
    return 1;
}

char *get_alias_command(info_t *info, char *alias)
{
    aliases_t *current = info->aliases;

    if (!current)
        return NULL;
    while (current != NULL) {
        if (strcmp(current->alias, alias) == 0)
            return current->command;
        current = current->next;
    }
    return NULL;
}
