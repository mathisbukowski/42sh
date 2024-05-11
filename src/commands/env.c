/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** env.c
*/

#include "minishell.h"
#include "commands.h"
#include "my.h"

int command_env(info_t *info)
{
    int i = 0;

    while (info->env[i] != NULL) {
        my_putstr(info->env[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
