/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_replacer.c
*/

#include "minishell.h"

void replace_alias_in_command(info_t *info)
{
    char *original_command = info->args[0];
    char *alias_command;

    if (original_command == NULL)
        return;
    alias_command = get_alias_command(info, original_command);
    if (alias_command == NULL)
        return;
    free(info->args[0]);
    info->args[0] = strdup(alias_command);
}
